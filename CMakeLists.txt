cmake_minimum_required(VERSION 3.26)
project(FList)

set(CMAKE_CXX_STANDARD 17)

add_executable(FList main.cpp
        FList.h
        Node.h)
