using Godot;
using System;

public class ChunkMesh : MeshInstance
{
    public override void _Ready()
    {
        Vector3[] cubo =
        {
            // FRONT
            new Vector3(0, 1, 1),
            new Vector3(1, 1, 1),
            new Vector3(1, 0, 1),
            new Vector3(0, 1, 1),
            new Vector3(1, 0, 1),
            new Vector3(0, 0, 1),
            // BACK
            new Vector3(1, 1, 0),
            new Vector3(0, 1, 0),
            new Vector3(0, 0, 0),
            new Vector3(1, 1, 0),
            new Vector3(0, 0, 0),
            new Vector3(1, 0, 0),
            // LEFT
            new Vector3(0, 1, 0),
            new Vector3(0, 1, 1),
            new Vector3(0, 0, 1),
            new Vector3(0, 1, 0),
            new Vector3(0, 0, 1),
            new Vector3(0, 0, 0),
            // RIGHT
            new Vector3(1, 1, 1),
            new Vector3(1, 1, 0),
            new Vector3(1, 0, 0),
            new Vector3(1, 1, 1),
            new Vector3(1, 0, 0),
            new Vector3(1, 0, 1),
            // TOP
            new Vector3(0, 1, 0),
            new Vector3(1, 1, 0),
            new Vector3(1, 1, 1),
            new Vector3(0, 1, 0),
            new Vector3(1, 1, 1),
            new Vector3(0, 1, 1),
            // BOTTOM
            new Vector3(0, 0, 1),
            new Vector3(1, 0, 1),
            new Vector3(1, 0, 0),
            new Vector3(0, 0, 1),
            new Vector3(1, 0, 0),
            new Vector3(0, 0, 0)
        };


        SurfaceTool st = new SurfaceTool();
        st.Begin(Mesh.PrimitiveType.Triangles);

        foreach (Vector3 vector in cubo) 
        {
            st.AddVertex(vector);
        }

        st.GenerateNormals();
        Mesh = st.Commit();
        CreateConvexCollision();

    }

}
