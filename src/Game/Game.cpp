//
// Created by Aphile on 14.07.2025.
//

#include "Game.h"

#include <algorithm>
#include <chrono>
#include <thread>

#include "../Entities/Cube.h"
#include "../Graphics/Render.h"
#include "Scene.h"

namespace Game {
    Game::Game(std::unique_ptr<Graphics::IRender> render) : _is_running(false), _render(std::move(render)) {
        _scene = std::make_unique<Scene>(_render->GetWidth(), _render->GetHeight());
    }

    void Game::Run() {
        _is_running = true;
        GameLoop();
    }
    void Game::Stop() { _is_running = false; }

    void Game::GameLoop() const {
        auto game_object_cube = std::make_unique<Cube>(0, 0, 5, 5, '*');
        _scene->AddGameObject(std::move(game_object_cube));

        const auto frame_time =
                std::chrono::microseconds(static_cast<long long>(1000000.0 / _render->GetFramesPerSecond()));
        auto last_frame_time = std::chrono::high_resolution_clock::now();

        while (_is_running) {
            const auto frame_start = std::chrono::high_resolution_clock::now();
            const float delta_time =
                    std::chrono::duration_cast<std::chrono::duration<float>>(frame_start - last_frame_time).count();

            // Render pipeline:
            // 1. Во-первых, обновляем абсолютно все объекты в сцене.
            // 2. Применяем накопленные обновления в сцене (через instance IRender),
            // затем проходимся по всем объектам в сцене и передаём каждый в IRender::Draw()
            // 3. Когда накопили все изменения из предыдущих шагов и все они содержатся в _back_frame_buffer,
            // рисуем кадр через IRender::RenderFrame.
            _scene->Update(delta_time);
            _scene->RenderUpdates(*_render);
            _render->RenderFrame();

            const auto frame_end = std::chrono::high_resolution_clock::now();

            const auto frameTimeRenderElapsed =
                    std::chrono::duration_cast<std::chrono::microseconds>(frame_end - frame_start);

            if (frameTimeRenderElapsed < frame_time) {
                std::this_thread::sleep_for(frame_time - frameTimeRenderElapsed);
            }

            last_frame_time = frame_end;
        }
    }

}  // namespace Game
