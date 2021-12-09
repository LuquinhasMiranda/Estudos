#ifndef OGLHandler_H
#define OGLHandler_H

#include <stdio.h>
#include <cmath>
#include "glad/glad.h"
#include <GLFW/glfw3.h>

class OGLHandler {
private:
    void (*GameLoop)(int);
    int width;
    int height;
    char* window_name;

public:
    OGLHandler(void (*_GameLoop)(int), int width, int height, char* _window_name);
    int init();
};

#endif
