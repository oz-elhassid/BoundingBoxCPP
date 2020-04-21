cmake_minimum_required(VERSION 3.10)
project(BoundingBoxCPP)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(tests
        BoundingBox.cpp
        BoundingBox.h
        tests.cpp
        )
