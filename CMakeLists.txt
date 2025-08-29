cmake_minimum_required(VERSION 3.31)
project(ascii_engine)

set(CMAKE_CXX_STANDARD 26)
add_executable(ascii_engine src/main.cpp
        src/core/engine/io/IInput.h
        src/core/engine/Utils/Console.cpp
        src/core/engine/Utils/Console.h
        src/core/graphics/Renderer.cpp
        src/core/graphics/Renderer.h
        src/core/engine/io/KeyCodes.h
        src/ecs/entity/EntityManager.h
        src/ecs/component/Position.h
        src/ecs/component/Sprite.h
        src/ecs/component/Health.h
        src/ecs/system/ActorController.cpp
        src/ecs/system/ActorController.h
        src/core/engine/io/InputReceiver.cpp
        src/core/engine/io/InputReceiver.h
        src/ecs/system/Canvas.cpp
        src/ecs/system/Canvas.h
        src/ecs/component/Size.h
        src/core/engine/Engine.cpp
        src/core/engine/Engine.h
        src/core/graphics/Renderer.cpp
        src/core/engine/scheduler/Scheduler.cpp
        src/core/engine/scheduler/Scheduler.h
        src/core/engine/scheduler/Scheduler.cpp
)