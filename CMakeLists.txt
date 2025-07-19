cmake_minimum_required(VERSION 3.31)
project(ascii_ape)

set(CMAKE_CXX_STANDARD 26)

include_directories(F:/Projects/CLion/ascii-ape/libraries/di-1.3.2/include)

add_executable(ascii_ape src/main.cpp
        src/Graphics/IRender.h
        src/Game/Game.cpp
        src/Game/Game.h
        src/Game/GameObject.cpp
        src/Game/GameObject.h
        src/Game/Entities/Actor.cpp
        src/Game/Entities/Actor.h
        src/IO/IInput.h
        src/Utils/Console.cpp
        src/Utils/Console.h
        src/Scenes/TestScene.cpp
        src/Scenes/TestScene.h
        src/Graphics/Renders/ASCIIRender.cpp
        src/Graphics/Renders/ASCIIRender.h
        src/IO/Handlers/Input.cpp
        src/IO/Handlers/Input.h
        src/Game/EntityAlive.cpp
        src/Game/EntityAlive.h
        src/IO/Controllers/ActorController.cpp
        src/IO/Controllers/ActorController.h
        src/Game/Scene.cpp
        src/Game/Scene.h
)
