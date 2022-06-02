cmake_minimum_required(VERSION 3.9)

project(OGL_TESTE)

include_directories("C:/glfw-WIN64")
include_directories("C:/glfw-WIN64/include")
include_directories("include")

add_executable(Application main.cpp src/Render/OGLHandler.cpp src/Render/glad.c src/Render/VBO.cpp src/Render/VAO.cpp src/Render/EBO.cpp src/Render/ShaderClass.cpp )

target_link_libraries(Application PRIVATE "C:/glfw-WIN64/lib/glfw3.lib")