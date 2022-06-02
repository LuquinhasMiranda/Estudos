cmake_minimum_required(VERSION 3.10)

project(LinkedListProj)

add_library(DataStructuresLib include/DataStructuresLib.hpp src/DataStructuresLib.cpp)

add_executable(DataStructuresApp main.cpp)

target_link_libraries(DataStructuresApp PRIVATE DataStructuresLib)