cmake_minimum_required(VERSION 3.12)
project(Tablice)

set(CMAKE_CXX_STANDARD 14)

include_directories(Tablice)

add_executable(Tablice
        Tablice/Array.cpp
        Tablice/Array.h
        Tablice/main.cpp)
