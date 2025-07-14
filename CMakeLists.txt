cmake_minimum_required(VERSION 3.31)
project(ascii_ape)

set(CMAKE_CXX_STANDARD 26)

add_executable(ascii_ape main.cpp
        Graphics/Render.cpp
        Graphics/Render.h
        Exceptions/RenderException.cpp
        Exceptions/RenderException.h
)
