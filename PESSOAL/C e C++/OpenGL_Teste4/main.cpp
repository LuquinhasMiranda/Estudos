#include "include/Render/OGLHandler.hpp"
#include <stdio.h>

void GameLoop(int deltaTime) {

}

int main( ) {
    OGLHandler handler = OGLHandler(&GameLoop, 1080, 1080, "Comi a sandra");
    handler.init();
}
