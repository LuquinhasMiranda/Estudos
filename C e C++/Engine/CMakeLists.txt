cmake_minimum_required(VERSION 3.22)

project(Engine VERSION 1.0.0)

add_executable(Application main.cpp src/EngineLib.cpp src/Chunk.cpp src/ChunkManager.cpp)

set_property(TARGET Application PROPERTY CXX_STANDARD 23)