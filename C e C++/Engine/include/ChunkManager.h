#ifndef CHUNKMANAGER_CLASS_H
#define CHUNKMANAGERCLASS_H

#include "Chunk.h"

class ChunkManager {
private:
    Chunk* head;
    string world_folder_path;

public:
    ChunkManager(string world_name);

    // LIST FUNCTIONS
    int LoadChunk(int _x, int _y, int _z);
    Chunk* FindChunk(int _x, int _y, int _z);
    int UnloadChunk(int _x, int _y, int _z);
    int UnloadChunk(Chunk* unload_chunk);
    int ClearChunks();

    // BLOCK CONTROL THROUGH CHUNKMANAGER
    int GetBlock(int _world_x, int _world_y, int _world_z);
    int SetBlock(int _world_x, int _world_y, int _world_z, int _block);
};

#endif