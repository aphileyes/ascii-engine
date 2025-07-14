//
// Created by Aphile on 14.07.2025.
//

#include "Game.h"

#include <algorithm>
#include <bits/this_thread_sleep.h>
#include <chrono>
#include <stdexcept>

#include "../Entities/Cube.h"
#include "../Graphics/Render.h"
#include "Scene.h"

namespace Game {
    static_assert(_WIN32, "This engine only work on windows platform.");

    Game::Game(const unsigned int width, const unsigned int height, const double fps) {
        if (width == 0 || height == 0) {
            throw std::invalid_argument("Width and height must be greater than 0.");
        }

        if (fps <= 0) {
            throw std::invalid_argument("Fps must be greater than 0.");
        }

        _width = width;
        _height = height;

        _fps = fps;
        _is_running = false;

        _render = std::make_unique<Graphics::Render>(_width, _height, _fps);
        _scene = std::make_unique<Scene>(_width, _height);
    }

    void Game::Run() {
        _is_running = true;
        GameLoop();
    }
    void Game::Stop() { _is_running = false; }

    [[noreturn]] void Game::GameLoop() const {
        auto game_object_cube = std::make_unique<Cube>(5, 5, 10, 10, '-');
        _scene->AddGameObject(std::move(game_object_cube));

        const long long frame_time = 1000 / _fps;

        while (_is_running) {
            auto frame_start = std::chrono::high_resolution_clock::now();
            _scene->Update();
            _scene->Render(*_render);
            _render->RenderFrame();
            auto frame_end = std::chrono::high_resolution_clock::now();

            const auto frameTimeRenderElapsed =
                    std::chrono::duration_cast<std::chrono::milliseconds>(frame_end - frame_start).count();

            if (frameTimeRenderElapsed < frame_time) {
                std::this_thread::sleep_for(std::chrono::milliseconds(frame_time - frameTimeRenderElapsed));
            }
        }
    }

} // namespace Game
