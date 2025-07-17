cmake_minimum_required(VERSION 3.31)
project(ascii_ape)

set(CMAKE_CXX_STANDARD 26)

include_directories(F:/Projects/CLion/ascii-ape/libraries/di-1.3.2/include)

add_executable(ascii_ape src/main.cpp
        src/Graphics/Render.cpp
        src/Graphics/Render.h
        src/Exceptions/RenderException.cpp
        src/Exceptions/RenderException.h
        src/Game/Game.cpp
        src/Game/Game.h
        src/Game/Scene.cpp
        src/Game/Scene.h
        src/Game/GameObject.cpp
        src/Game/GameObject.h
        src/Entities/Cube.cpp
        src/Entities/Cube.h
        src/IO/InputManager.cpp
        src/IO/InputManager.h
        src/Utils/Console.cpp
        src/Utils/Console.h
)
