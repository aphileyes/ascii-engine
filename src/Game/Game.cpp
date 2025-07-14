//
// Created by Aphile on 14.07.2025.
//

#include "Game.h"

#include <chrono>
#include <stdexcept>

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
        _scene = std::make_unique<Scene>();
    }

    void Game::Run() {
        _is_running = true;
        GameLoop();
    }
    void Game::Stop() { _is_running = false; }

    void Game::GameLoop() const {
        const GameObject cube(5, 5, 5, 5, '.');
        _scene->AddGameObject(cube);

        double frame_time = 1000.0 / _fps;

        while (_is_running) {

            _scene->Update();
            _render->RenderFrame();
        }
    }

} // namespace Game
