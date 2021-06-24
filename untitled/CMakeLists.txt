cmake_minimum_required(VERSION 3.13)
project(untitled)

set(CMAKE_CXX_STANDARD 17)


set(BOOST_ROOT "/home/dell/softwares/boost_1_75_0")
#Add header file search path
include_directories(/home/dell/softwares/boost_1_75_0)
#Add library file search path
link_directories(/home/dell/softwares/boost_1_75_0)

add_executable(untitled main.cpp)