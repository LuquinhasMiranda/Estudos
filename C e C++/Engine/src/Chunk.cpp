#include "../include/Chunk.h"

using namespace std;

Vector3::Vector3() {
    x = y = z = 0;
}

Vector3::Vector3(int _x, int _y, int _z) {
    x = _x;
    y = _y;
    z = _z;
}


Chunk::Chunk(int _x, int _y, int _z, string _world_folder_path) {
    Vector3(_x, _y, _z);
    Next = NULL;

    chunk_file_path = _world_folder_path + to_string(_x) + "_" + to_string(_y) + "_" + to_string(_z);
}

string Chunk::GetFileName() {
    return chunk_file_path + ".bin";
}

int Chunk::GetBlock(int _x, int _y, int _z) {
    if (x >= CHUNK_SIZE_X || x < 0) return -1;
    if (y >= CHUNK_SIZE_Y || y < 0) return -1;
    if (z >= CHUNK_SIZE_Z || z < 0) return -1;
    return BlockGrid[_x][_y][_z];

    return 0;
}

int Chunk::SetBlock(int _x, int _y, int _z, int _block) {
    if (x >= CHUNK_SIZE_X || x < 0) return -1;
    if (y >= CHUNK_SIZE_Y || y < 0) return -1;
    if (z >= CHUNK_SIZE_Z || z < 0) return -1;
    BlockGrid[_x][_y][_z] = _block;
    
    return 0;
}

int Chunk::SetBlockGrid(unsigned short _grid[CHUNK_SIZE_X][CHUNK_SIZE_Y][CHUNK_SIZE_Z]) {
    for (int x = 0; x < CHUNK_SIZE_X; x++)
        for (int y = 0; y < CHUNK_SIZE_Y; y++)
            for (int z = 0; z < CHUNK_SIZE_Z; z++)
                BlockGrid[x][y][z] = _grid[x][y][z];
    return 0;
}

int Chunk::SaveChunkToFile() {
    unsigned short file_text[CHUNK_SIZE_X*CHUNK_SIZE_Y*CHUNK_SIZE_Z];
    for (int z = 0; z < CHUNK_SIZE_Z; z++) 
        for (int y = 0; y < CHUNK_SIZE_Y; y++) 
            for (int x = 0; x < CHUNK_SIZE_X; x++) 
            {
                static int i = 0;
                file_text[i] = BlockGrid[x][y][z];
                i++;
            }

    fstream chunk_file;
    chunk_file.open(GetFileName(), std::fstream::out | std::fstream::binary);
    chunk_file.write(reinterpret_cast<const char *>(&file_text), sizeof(file_text));
    chunk_file.close();

    return 0;
}

int Chunk::ReadChunkFromFile() {
    unsigned short file_text[CHUNK_SIZE_X*CHUNK_SIZE_Y*CHUNK_SIZE_Z];

    std::fstream chunk_file;
    chunk_file.open(GetFileName(), std::fstream::in | std::fstream::binary);
    chunk_file.read(reinterpret_cast<char *>(&file_text), sizeof(file_text));
    chunk_file.close();
    
    if (!chunk_file.fail()) 
    {
        for (int z = 0; z < CHUNK_SIZE_Z; z++) 
            for (int y = 0; y < CHUNK_SIZE_Y; y++) 
                for (int x = 0; x < CHUNK_SIZE_X; x++) 
                {
                    static int i = 0;
                    BlockGrid[x][y][z] = file_text[i];
                    i++;
                }
        chunk_file.close();
        return 0;
    }
    else 
    {
        chunk_file.close();
        return -1;
    } 
}