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
#include "../Graphics/Renders/ASCIIRender.h"
#include "Actor.h"

namespace Game {

    Game::Game(std::unique_ptr<Graphics::IRender> render, std::unique_ptr<IScene> scene,
               std::unique_ptr<IO::IInput> input_manager) {
        _is_running = false;

        _scene = std::move(scene);
        _render = std::move(render);
        _input = std::move(input_manager);

        _actor = std::make_shared<Actor>(GameObject::Position{0, 0}, GameObject::Size{30, 10}, '!', 1.0f);
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

        int frame_count = 0;
        int frame_time_accumulator = 0;

        auto last_frame_time = std::chrono::high_resolution_clock::now();

        while (_is_running) {
            auto frame_start = std::chrono::high_resolution_clock::now();

            auto delta_time =
                    std::chrono::duration_cast<std::chrono::microseconds>(frame_start - last_frame_time).count();

            _input->Update();
            // for (const auto& [type, key_code]: _input->GetInputEvents()) {
            //     std::string input_type;
            //
            //     switch (type) {
            //         case IO::KEY_PRESSED:
            //             input_type = "KEY_PRESSED";
            //             break;
            //         case IO::KEY_HOLD:
            //             input_type = "KEY_HOLD";
            //             break;
            //         case IO::KEY_RELEASED:
            //             input_type = "KEY_RELEASED";
            //             break;
            //     }
            //
            //     std::cout << "Key " << static_cast<char>(key_code) << " is " << input_type << std::endl;
            // }
            _actor_controller->Update(_input->GetInputEvents(), delta_time);
            _scene->Update(_render, delta_time);
            _render->RenderFrame();
            auto frame_end = std::chrono::high_resolution_clock::now();
            auto frame_elapsed = std::chrono::duration_cast<std::chrono::microseconds>(frame_end - frame_start);


            last_frame_time = frame_end;

            if (frame_elapsed < target_frame_time) {
                std::this_thread::sleep_for(target_frame_time - frame_elapsed);
            }
        }
    }

}  // namespace Game
