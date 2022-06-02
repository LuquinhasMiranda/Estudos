#include <stdio.h>
#include <stdlib.h>
#include "ChunkNetLib.hpp"

using namespace std;

int main()
{
    ChunkNet net = ChunkNet();
    for (int x = 0; x < 16; x++)
        for (int y = 0; y < 16; y++)
            for (int z = 0; z < 16; z++)
                net.Add(x,y,z);

    net.Remover(1,1,10);

    for (int x = 0; x < 16; x++)
        for (int y = 0; y < 16; y++)
            for (int z = 0; z < 16; z++)
                net.PrintarChunk(x,y,z);

    net.Limpar();

    scanf("%d");
    return 0;
}
