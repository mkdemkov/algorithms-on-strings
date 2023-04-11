cmake_minimum_required(VERSION 3.21)
project(KDZ2)

set(CMAKE_CXX_STANDARD 17)

add_library(text_generating STATIC
        text_generating/text-generating.cpp)

add_library(static STATIC
        static/enum.cpp)

add_executable(KDZ2 main.cpp)
