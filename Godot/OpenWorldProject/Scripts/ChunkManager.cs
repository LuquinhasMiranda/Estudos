using Godot;
using System;
using System.Collections.Generic;

public class ChunkManager : Spatial
{
    public override void _Ready()
    {
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                RenderChunk(LoadChunk(i*16, 0, j*16), i * 16, 0, j * 16);
    }

    void GerarChunk(int GERAR_X, int GERAR_Y, int GERAR_Z)
    {
        OpenSimplexNoise NOISE = new OpenSimplexNoise();
        NOISE.Seed = 1024;
        NOISE.Octaves = 4;
        NOISE.Period = 20.0f;
        NOISE.Persistence = 0.5f;

        string CHUNK_DATA = "";

        for (int z = 0; z < 32; z++)
        {
            for (int y = 0; y < 32; y++)
            {
                for (int x = 0; x < 32; x++)
                {
                    float RESULT = (NOISE.GetNoise3d(GERAR_X + x, GERAR_Y + y, GERAR_Z + z) + 1) * 256;
                    if      (RESULT > 384) CHUNK_DATA += '4';
                    else if (RESULT > 256) CHUNK_DATA += '3';
                    else if (RESULT > 128) CHUNK_DATA += '2';
                    else if (RESULT >   0) CHUNK_DATA += '1';
                }
                CHUNK_DATA += '\n';
            }
        }
        File file_write = new File();
        file_write.Open("res://EnviromentAssets/_WORLD/"+ GERAR_X + "_" + GERAR_Y + "_" + GERAR_Z +".txt", File.ModeFlags.Write);
        file_write.StoreString(CHUNK_DATA);
        file_write.Close();
    }

    int[,,] LoadChunk(int LOAD_X, int LOAD_Y, int LOAD_Z)
    {
        File file_read = new File();
        file_read.Open("res://EnviromentAssets/_WORLD/" + LOAD_X + "_" + LOAD_Y + "_" + LOAD_Z + ".txt", File.ModeFlags.Read);
        int[,,] LOADED_CHUNK = new int[32,32,32];
        for (int z = 0; z < 32; z++)
        {
            for (int y = 0; y < 32; y++)
            {
                string LINE = file_read.GetLine();
                for (int x = 0; x < 32; x++)
                {
                    if      (LINE[x] == '4') LOADED_CHUNK[x, y, z] = 4;
                    else if (LINE[x] == '3') LOADED_CHUNK[x, y, z] = 3;
                    else if (LINE[x] == '2') LOADED_CHUNK[x, y, z] = 2;
                    else if (LINE[x] == '1') LOADED_CHUNK[x, y, z] = 1;
                }
            }
        }
        file_read.Close();
        return LOADED_CHUNK;
    }

    List<Vector3> VERTEX_LIST = new List<Vector3>();
    void RenderChunk(int[,,] RENDER_CHUNK, int x_offset, int y_offset, int z_offset)
    {
        for (int z = 0; z < 32; z++)
            for (int y = 0; y < 32; y++)
                for (int x = 0; x < 32; x++)
                {
                    if      (RENDER_CHUNK[x, y, z] == 4) continue;
                    else if (RENDER_CHUNK[x, y, z] == 3) continue;
                    else if (RENDER_CHUNK[x, y, z] == 2) RenderBlock(RENDER_CHUNK, x, y, z, x_offset, y_offset, z_offset);
                    else if (RENDER_CHUNK[x, y, z] == 1) continue;
                }

        MeshInstance ChunkMesh = new MeshInstance();
        SurfaceTool st = new SurfaceTool();
        st.Begin(Mesh.PrimitiveType.Triangles);

        foreach (Vector3 vertex in VERTEX_LIST)
            st.AddVertex(vertex*2);

        st.GenerateNormals();
        ChunkMesh.Mesh = st.Commit();
        ChunkMesh.CreateTrimeshCollision();

        AddChild(ChunkMesh);
    }
    
    void RenderBlock(int[,,] RENDER_CHUNK, int x, int y, int z, int x_offset, int y_offset, int z_offset)
    {
        bool TOP    = false;
        bool BOTTOM = false;
        bool RIGHT  = false;
        bool LEFT   = false;
        bool FRONT  = false;
        bool BACK   = false;

        if (y + 1 == 32) TOP = true;
        else if (RENDER_CHUNK[x, y + 1, z] != 2) TOP = true;

        if (y - 1 == -1) BOTTOM = true;
        else if (RENDER_CHUNK[x, y - 1, z] != 2) BOTTOM = true;

        if (x + 1 == 32) RIGHT = true;
        else if (RENDER_CHUNK[x + 1, y, z] != 2) RIGHT = true;

        if (x - 1 == -1) LEFT = true;
        else if (RENDER_CHUNK[x - 1, y, z] != 2) LEFT = true;

        if (z + 1 == 32) FRONT = true;
        else if (RENDER_CHUNK[x, y, z + 1] != 2) FRONT = true;

        if (z - 1 == -1) BACK = true;
        else if (RENDER_CHUNK[x, y, z - 1] != 2) BACK = true;

        x += x_offset;
        y += y_offset;
        z += z_offset;

        if (TOP)
        {
            VERTEX_LIST.Add(new Vector3(x + 0, y + 1, z + 0));
            VERTEX_LIST.Add(new Vector3(x + 1, y + 1, z + 0));
            VERTEX_LIST.Add(new Vector3(x + 1, y + 1, z + 1));
            VERTEX_LIST.Add(new Vector3(x + 0, y + 1, z + 0));
            VERTEX_LIST.Add(new Vector3(x + 1, y + 1, z + 1));
            VERTEX_LIST.Add(new Vector3(x + 0, y + 1, z + 1));
        }
        if (BOTTOM)
        {
            VERTEX_LIST.Add(new Vector3(x + 0, y + 0, z + 1));
            VERTEX_LIST.Add(new Vector3(x + 1, y + 0, z + 1));
            VERTEX_LIST.Add(new Vector3(x + 1, y + 0, z + 0));
            VERTEX_LIST.Add(new Vector3(x + 0, y + 0, z + 1));
            VERTEX_LIST.Add(new Vector3(x + 1, y + 0, z + 0));
            VERTEX_LIST.Add(new Vector3(x + 0, y + 0, z + 0));
        }
        if (RIGHT)
        {
            VERTEX_LIST.Add(new Vector3(x + 1, y + 1, z + 1));
            VERTEX_LIST.Add(new Vector3(x + 1, y + 1, z + 0));
            VERTEX_LIST.Add(new Vector3(x + 1, y + 0, z + 0));
            VERTEX_LIST.Add(new Vector3(x + 1, y + 1, z + 1));
            VERTEX_LIST.Add(new Vector3(x + 1, y + 0, z + 0));
            VERTEX_LIST.Add(new Vector3(x + 1, y + 0, z + 1));
        }
        if (LEFT)
        {
            VERTEX_LIST.Add(new Vector3(x + 0, y + 1, z + 0));
            VERTEX_LIST.Add(new Vector3(x + 0, y + 1, z + 1));
            VERTEX_LIST.Add(new Vector3(x + 0, y + 0, z + 1));
            VERTEX_LIST.Add(new Vector3(x + 0, y + 1, z + 0));
            VERTEX_LIST.Add(new Vector3(x + 0, y + 0, z + 1));
            VERTEX_LIST.Add(new Vector3(x + 0, y + 0, z + 0));
        }
        if (FRONT)
        {
            VERTEX_LIST.Add(new Vector3(x + 0, y + 1, z + 1));
            VERTEX_LIST.Add(new Vector3(x + 1, y + 1, z + 1));
            VERTEX_LIST.Add(new Vector3(x + 1, y + 0, z + 1));
            VERTEX_LIST.Add(new Vector3(x + 0, y + 1, z + 1));
            VERTEX_LIST.Add(new Vector3(x + 1, y + 0, z + 1));
            VERTEX_LIST.Add(new Vector3(x + 0, y + 0, z + 1));
        }
        if (BACK)
        {
            VERTEX_LIST.Add(new Vector3(x + 1, y + 1, z + 0));
            VERTEX_LIST.Add(new Vector3(x + 0, y + 1, z + 0));
            VERTEX_LIST.Add(new Vector3(x + 0, y + 0, z + 0));
            VERTEX_LIST.Add(new Vector3(x + 1, y + 1, z + 0));
            VERTEX_LIST.Add(new Vector3(x + 0, y + 0, z + 0));
            VERTEX_LIST.Add(new Vector3(x + 1, y + 0, z + 0));
        }
    }
}
