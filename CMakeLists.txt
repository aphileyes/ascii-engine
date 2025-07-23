cmake_minimum_required(VERSION 3.31)
project(ascii_engine)

set(CMAKE_CXX_STANDARD 26)

include_directories(F:/Projects/CLion/ascii-engine/libraries/di-1.3.2/include)

add_executable(ascii_engine src/main.cpp
        src/Graphics/IRender.h
        src/Game/Game.cpp
        src/Game/Game.h
        src/Game/GameObject.cpp
        src/Game/GameObject.h
        src/Game/Actor.cpp
        src/Game/Actor.h
        src/IO/IInput.h
        src/Utils/Console.cpp
        src/Utils/Console.h
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
        src/Factories/EntityFactory.cpp
        src/Factories/EntityFactory.h
        src/IO/KeyCodes.h
)
