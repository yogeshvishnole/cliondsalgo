cmake_minimum_required(VERSION 3.19)
project(priority_queue)

set(CMAKE_CXX_STANDARD 14)

add_executable(priority_queue main.cpp PriorityQueue.h heap_sort.h)