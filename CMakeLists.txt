cmake_minimum_required(VERSION 3.3)
project(HuffmanTest)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Huffman.h HuffmanNode.h MinHeap.h)
add_executable(HuffmanTest ${SOURCE_FILES})