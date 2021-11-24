#ifndef CHUNKNET_H_INCLUDED
#define CHUNKNET_H_INCLUDED

class Vector3 {
public:
    int x;
    int y;
    int z;
    Vector3(int _x, int _y, int _z);
};

class Vector2 {
public:
    int x;
    int y;
    Vector2(int _x, int _y);
};

class Chunk {
public:
    Vector3 chunkPos;
    int blocos[32][32][32];
    Chunk *Next;
};

class ChunkNet {
public:
    Chunk *head;
    ChunkNet();

    void Add(int x, int y, int z);
    void PrintarAll();
    void PrintarChunk(int x, int y, int z);
    void Remover(int x, int y, int z);
    void Limpar();
    struct Chunk* Find(int x, int y, int z);
};

#endif // CHUNKNET_H_INCLUDED
