#include "ChunkNetLib.h"
#include <stdio.h>
#include <stdlib.h>

Vector3::Vector3(int _x, int _y, int _z){
    x = _x;
    y = _y;
    z = _z;
}

Vector2::Vector2(int _x, int _y){
    x = _x;
    y = _y;
}

ChunkNet::ChunkNet() {
    head = (Chunk*) malloc(sizeof(Chunk));
    head->Next = NULL;
}

void ChunkNet::Add(int x, int y, int z) {
    Chunk* new_chunk = (Chunk*) malloc(sizeof(Chunk));
    new_chunk->chunkPos = Vector3(x, y, z);
    new_chunk->Next = NULL;

    if (ChunkNet::Find(x,y,z) != NULL) return;

    Chunk* p1 = head;
    while (p1->Next != NULL) p1 = p1->Next;

    p1->Next = new_chunk;
}

Chunk* ChunkNet::Find(int x, int y, int z) {
    Chunk* p1 = head;
    while (p1 != NULL) {
        if (p1 != head)
            if ((*p1).chunkPos.x == x && (*p1).chunkPos.y == y && (*p1).chunkPos.z == z)
                return p1;
        p1 = p1->Next;
    }
    return NULL;
}

void ChunkNet::PrintarAll() {
    Chunk* p1 = head;
    while (p1 != NULL) {
        if (p1 != head) printf("%d %d %d\n", (*p1).chunkPos.x, (*p1).chunkPos.y, (*p1).chunkPos.z);
        p1 = p1->Next;
    }
}

void ChunkNet::PrintarChunk(int x, int y, int z) {
    Chunk* p1 = ChunkNet::Find(x, y, z);
    if (p1 == NULL) printf("> NULL\n");
    else
        printf("> %d %d %d\n", (*p1).chunkPos.x, (*p1).chunkPos.y, (*p1).chunkPos.z);
}

void ChunkNet::Remover(int x, int y, int z) {
    Chunk* p1 = ChunkNet::Find(x, y, z);
    if (p1 == NULL) return;

    Chunk* p3 = head;
    while (p3->Next != p1 && p3 != NULL) p3 = p3->Next;

    p3->Next = p1->Next;
    free(p1);
}

void ChunkNet::Limpar() {
    Chunk* p1 = head;
    Chunk* p2;

    while (p1 != NULL) {
        p2 = p1;
        p1 = p1->Next;
        if (p2 != head) free(p2);
    }
}

