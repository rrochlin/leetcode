cmake_minimum_required(VERSION 3.27)
project(Leetcode)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(
        Leetcode
        HelperFuncts/PrintBT.cpp
        DynamicProgramming/main.cpp
)
