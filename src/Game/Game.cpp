//
// Created by Aphile on 14.07.2025.
//

#include "Game.h"

#include <algorithm>
#include <chrono>
#include <iostream>
#include <memory>
#include <thread>

#include "../Graphics/IRender.h"
#include "Entities/Actor.h"

namespace Game {

    Game::Game(std::unique_ptr<Graphics::IRender> render, std::unique_ptr<IScene> scene,
               std::unique_ptr<IO::IInput> input_manager) {
        _is_running = false;

        _scene = std::move(scene);
        _render = std::move(render);
        _input = std::move(input_manager);

        _actor = std::make_shared<Actor>(GameObject::Position{0, 0}, GameObject::Size{5, 5}, '&', 1.0f);
        _scene->AddGameObject(_actor);

        _actor_controller = std::make_unique<ActorController>(_actor);
    }

    void Game::Run() {
        _is_running = true;
        GameLoop();
    }
    void Game::Stop() { _is_running = false; }

    void Game::GameLoop() {
        auto target_frame_time = std::chrono::microseconds(1'000'000 / _render->GetFramesPerSecond());

        while (_is_running) {
            auto frame_start = std::chrono::high_resolution_clock::now();
            _input->Update();
            _actor_controller->Update(_input->GetInputEvents());
            _scene->Update();
            _scene->RenderUpdates(_render);
            _render->RenderFrame();
            auto frame_end = std::chrono::high_resolution_clock::now();

            auto frame_elapsed = std::chrono::duration_cast<std::chrono::microseconds>(frame_end - frame_start);

            if (frame_elapsed < target_frame_time) {
                std::this_thread::sleep_for(target_frame_time - frame_elapsed);
            }

            // std::cout << "Pressed keys: " << std::endl;
            // for (const auto& [type, key_code]: _input_manager->GetInputEvents()) {
            //     std::cout << static_cast<char>(key_code) << std::endl;
            // }
        }
    }

}  // namespace Game
