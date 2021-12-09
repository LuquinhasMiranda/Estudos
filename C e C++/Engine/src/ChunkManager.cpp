#include "../include/ChunkManager.h"

ChunkManager::ChunkManager(string world_name) {
    head = new Chunk(-1, -1, -1, "HEAD");
    world_folder_path = "worlds/" + world_name + "/";
    filesystem::create_directories(world_folder_path);
}

int ChunkManager::LoadChunk(int _x, int _y, int _z) {
    if (FindChunk(_x, _y, _z) != NULL) return -2;
    Chunk *load_chunk = new Chunk(_x, _y, _z, world_folder_path);
    
    // FILE SEARCH
    if ((*load_chunk).ReadChunkFromFile() == -1)
    {
        unsigned short new_blockgrid[CHUNK_SIZE_X][CHUNK_SIZE_Y][CHUNK_SIZE_Z];
        for (int x = 0; x < CHUNK_SIZE_X; x++)
            for (int y = 0; y < CHUNK_SIZE_Y; y++)
                for (int z = 0; z < CHUNK_SIZE_Z; z++)
                    new_blockgrid[x][y][z] = 0;
        (*load_chunk).SetBlockGrid(new_blockgrid);
    }
    
    Chunk *p1 = head;
    while (p1->Next != NULL) p1 = p1->Next;
    p1->Next = load_chunk;

    return 0;
}

Chunk* ChunkManager::FindChunk(int _x, int _y, int _z) {
    Chunk *p1 = head;
    while (p1->Next != NULL) {
        p1 = p1->Next;
        if ((*p1).x == _x && (*p1).y == _y && (*p1).z == _z) return p1;
    }
    return NULL;
}

int ChunkManager::UnloadChunk(int _x, int _y, int _z) {
    Chunk *p1 = FindChunk(_x, _y, _z);
    if (p1 == NULL) return -2;

    (*p1).SaveChunkToFile();

    Chunk *p2 = head;
    while (p2->Next != p1) p2 = p2->Next;
    
    p2->Next = p1->Next;
    free(p1);

    return 0;
}

int ChunkManager::UnloadChunk(Chunk* unload_chunk) {
    return UnloadChunk((*unload_chunk).x, (*unload_chunk).y, (*unload_chunk).z);
}

int ChunkManager::ClearChunks() {
    while (head->Next != NULL) {
        Chunk *p1 = head;
        while (p1->Next != NULL) p1 = p1->Next;
        UnloadChunk(p1);
    }
    return 0;
}

int ChunkManager::GetBlock(int _world_x, int _world_y, int _world_z) {
    int block_x = _world_x % CHUNK_SIZE_X;
    int block_y = _world_y % CHUNK_SIZE_Y;
    int block_z = _world_z % CHUNK_SIZE_Z;
    int chunk_x = _world_x - block_x;
    int chunk_y = _world_y - block_y;
    int chunk_z = _world_z - block_z;

    Chunk *p = FindChunk(chunk_x, chunk_y, chunk_z);
    if (p == NULL) return -2;

    return (*p).GetBlock(block_x, block_y, block_z);
}

int ChunkManager::SetBlock(int _world_x, int _world_y, int _world_z, int _block) {
    int block_x = _world_x % CHUNK_SIZE_X;
    int block_y = _world_y % CHUNK_SIZE_Y;
    int block_z = _world_z % CHUNK_SIZE_Z;
    int chunk_x = _world_x - block_x;
    int chunk_y = _world_y - block_y;
    int chunk_z = _world_z - block_z;

    Chunk *p = FindChunk(chunk_x, chunk_y, chunk_z);
    if (p == NULL) return -2;

    (*p).SetBlock(block_x, block_y, block_z, _block);
    return 0;
}