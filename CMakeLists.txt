cmake_minimum_required(VERSION 3.6)
project(LinkList)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp constant.h linklist.h function.cpp)
add_executable(LinkList ${SOURCE_FILES})