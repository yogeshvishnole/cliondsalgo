cmake_minimum_required(VERSION 3.19)
project(Graph)

set(CMAKE_CXX_STANDARD 20)

add_executable(Graph Graph.h  dfs.cpp countNoOfConnectedComponents.cpp)