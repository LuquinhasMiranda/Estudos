#ifndef CHUNK_CLASS_H
#define CHUNK_CLASS_H

#include <stdlib.h>
#include <fstream>
#include <string>
#include <filesystem>

// CHUNK DEFINITIONS
#define CHUNK_SIZE_X 32
#define CHUNK_SIZE_Y 64
#define CHUNK_SIZE_Z 32

using namespace std;

class Vector3 {
public:
    Vector3();
    Vector3(int _x, int _y, int _z);
    int x;
    int y;
    int z;
};

class Chunk : public Vector3 {
private:
    unsigned short BlockGrid[CHUNK_SIZE_X][CHUNK_SIZE_Y][CHUNK_SIZE_Z];
    string chunk_file_path;

public:
    Chunk(int _x, int _y, int _z, string _world_folder_path);
    Chunk *Next;

    // BLOCKGRID FUNCTIONS
    int GetBlock(int _x, int _y, int _z);
    int SetBlock(int _x, int _y, int _z, int _block);
    int SetBlockGrid(unsigned short _grid[CHUNK_SIZE_X][CHUNK_SIZE_Y][CHUNK_SIZE_Z]);

    // CHUNK FILE NAME
    string GetFileName();
    
    // STORAGE FUNCTIONS
    int SaveChunkToFile();
    int ReadChunkFromFile();
};

#endif