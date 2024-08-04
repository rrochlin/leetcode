cmake_minimum_required(VERSION 3.27)
project(Leetcode)

set(CMAKE_CXX_STANDARD 14)

include_directories(LinkedLists/146_LRUCache)

add_executable(
        Leetcode
        HelperFuncts/PrintBT.cpp
        Trees/Trees.cpp
)
