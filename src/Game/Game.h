//
// Created by Aphile on 14.07.2025.
//

#ifndef GAME_H
#define GAME_H
#include <memory>

#include "../Graphics/IRender.h"
#include "../IO/Controllers/ActorController.h"
#include "../IO/IInput.h"
#include "Actor.h"
#include "Scene.h"

namespace Game {

    class Game {
    public:
        explicit Game(std::unique_ptr<Graphics::IRender> render, std::unique_ptr<IScene> scene,
                      std::unique_ptr<IO::IInput> input_manager);
        void Run();
        void Stop();


    private:
        void GameLoop();
        bool _is_running;

        std::shared_ptr<Actor> _actor;
        std::unique_ptr<IScene> _scene;
        std::unique_ptr<IO::IInput> _input;
        std::unique_ptr<Graphics::IRender> _render;
        std::unique_ptr<ActorController> _actor_controller;
    };

}  // namespace Game

#endif  // GAME_H
