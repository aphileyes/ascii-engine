cmake_minimum_required(VERSION 3.31)
project(ascii_ape)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_EXE_LINKER_FLAGS ${CMAKE_EXE_LINKER_FLAGS} "-static")

add_executable(ascii_ape src/main.cpp
        src/Graphics/Render.cpp
        src/Graphics/Render.h
        src/Exceptions/RenderException.cpp
        src/Exceptions/RenderException.h
        src/Game/Game.cpp
        src/Game/Game.h
)