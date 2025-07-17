//
// Created by Aphile on 14.07.2025.
//

#include "Game.h"

#include <algorithm>
#include <chrono>
#include <thread>

#include "../Entities/Cube.h"
#include "../Graphics/IRender.h"

namespace Game {

    Game::Game(std::unique_ptr<Graphics::IRender> render, std::unique_ptr<IScene> scene) {
        _is_running = false;

        _render = std::move(render);
        _scene = std::move(scene);
    }

    void Game::Run() {
        _is_running = true;
        GameLoop();
    }
    void Game::Stop() { _is_running = false; }


    void Game::GameLoop() const {
        // auto cube = std::make_unique<Cube>(0, 0, 5, 5, '&');
        // _scene->AddGameObject(std::move(cube));

        const auto frame_time =
                // Для высокой точности просчёта времени кадра, берётся время кадра, делённое на 1 микросекунду.
                // 1 секунда = 10^6 микросекунд или же 1'000'000.0
                std::chrono::microseconds(static_cast<long long>(1'000'000.0 / _render->GetFramesPerSecond()));

        auto last_frame_time = std::chrono::high_resolution_clock::now();

        while (_is_running) {
            const auto frame_start = std::chrono::high_resolution_clock::now();
            const float delta_time =
                    std::chrono::duration_cast<std::chrono::duration<float>>(frame_start - last_frame_time).count();

            /*
             * ----- Render pipeline ----- Render pipeline ----- Render pipeline -----
             *
             *  1. Обновляем абсолютно все объекты в сцене.
             *  2. Добавляем изменения в текущий кадр, который находится в процессе построения.
             *  3. Рисуем кадр через IRender::RenderFrame со всеми накопленными изменениями.
             *
             * ----- Render pipeline ----- Render pipeline ----- Render pipeline -----
             */
            _scene->Update(delta_time);
            _scene->RenderUpdates(*_render);
            _render->RenderFrame();

            const auto frame_end = std::chrono::high_resolution_clock::now();

            const auto frame_render_elapsed_time =
                    std::chrono::duration_cast<std::chrono::microseconds>(frame_end - frame_start);

            // Если текущий кадр отобразился быстрее, чем на него было выделено времени,
            // то для синхронизации досыпаем разницу.
            if (frame_render_elapsed_time < frame_time) {
                std::this_thread::sleep_for(frame_time - frame_render_elapsed_time);
            }

            last_frame_time = frame_end;
        }
    }

}  // namespace Game
