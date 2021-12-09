cmake_minimum_required(VERSION 3.10)

project(ChunkNetDevelopment)

add_library(
    ChunkNetLib
    ChunkNetLib.hpp
    ChunkNetLib.cpp
    )

add_executable(ChunkNet main.cpp)

target_link_libraries(ChunkNet PRIVATE ChunkNetLib)