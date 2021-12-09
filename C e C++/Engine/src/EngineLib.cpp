#include "../include/EngineLib.h"

int start() {
    ChunkManager cm = ChunkManager("teste");
    
    cm.LoadChunk(0,0,0);
    printf("%d", cm.GetBlock(0,0,0));
    printf("%d", cm.GetBlock(1,0,0));
    printf("%d", cm.GetBlock(2,0,0));
    printf("%d", cm.GetBlock(3,0,0));
    printf("%d", cm.GetBlock(4,0,0));
    return 0;
}
