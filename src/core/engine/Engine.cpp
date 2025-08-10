//
// Created by Aphile on 03.08.2025.
//

#include "Engine.h"

#include <thread>

#include "../../ecs/component/Health.h"
#include "../../ecs/component/Position.h"
#include "../../ecs/component/Size.h"
#include "../../ecs/component/Sprite.h"
#include "../../ecs/entity/EntityManager.h"
#include "../../ecs/system/ActorController.h"
#include "../../ecs/system/Canvas.h"
#include "io/InputReceiver.h"

#include "Engine.h"

#include <chrono>
#include <iostream>
#include <thread>

#include "../../ecs/component/Health.h"
#include "../../ecs/component/Position.h"
#include "../../ecs/component/Size.h"
#include "../../ecs/component/Sprite.h"
#include "utils/Console.h"

namespace Engine {

    constexpr size_t SECOND_IN_MICROSECONDS = 1'000'000;
    constexpr size_t SECOND_IN_NANOSECONDS = 1'000'000'000;

    Engine::Engine()
        : entity_manager_(std::make_unique<Entity::EntityManager>()),
          input_receiver_(std::make_unique<IO::InputReceiver>()),
          actor_controller_(std::make_unique<System::ActorController>()),
          canvas_(std::make_unique<System::Canvas>()),
          renderer_(std::make_unique<Graphics::Renderer>(50, 30)) {}

    void Engine::Run() {
        is_running_ = true;
        GameLoop();
    }

    void Engine::Shutdown() {
        is_running_ = false;
    }

    void Engine::GameLoop() {
        Entity::Entity actor = entity_manager_->CreateEntity();
        entity_manager_->AddComponent<Component::Sprite>(
            actor, std::make_shared<Component::Sprite>('*'));
        entity_manager_->AddComponent<Component::Health>(
            actor, std::make_shared<Component::Health>(1.0f));
        entity_manager_->AddComponent<Component::Position>(
            actor, std::make_shared<Component::Position>(1, 1));
        entity_manager_->AddComponent<Component::Size>(
            actor, std::make_shared<Component::Size>(5, 3));

        auto accumulated_delta_time = std::chrono::nanoseconds(0);
        size_t fixed_update_step = SECOND_IN_NANOSECONDS / 30.0f;

        auto last_frame_time = std::chrono::high_resolution_clock::now();
        auto last_fps_time = last_frame_time;
        auto render_time_accumulator = std::chrono::nanoseconds(0);
        size_t frame_count = 0;

        renderer_->SetStartRenderFromRow(1);

        while (is_running_) {
            auto frame_start = std::chrono::high_resolution_clock::now();
            auto delta_time = frame_start - last_frame_time;
            accumulated_delta_time += delta_time;
            frame_count++;

            auto time_since_last_fps =
                std::chrono::duration_cast<std::chrono::milliseconds>(
                    frame_start - last_fps_time);
            if (time_since_last_fps.count() >= 1000) {
                float fps =
                    frame_count / (time_since_last_fps.count() / 1000.0f);
                float avg_render_time =
                    frame_count > 0
                        ? std::chrono::duration_cast<std::chrono::milliseconds>(
                              render_time_accumulator)
                                  .count() /
                              static_cast<float>(frame_count)
                        : 0;
                float avg_frame_time = frame_count > 0
                                           ? time_since_last_fps.count() /
                                                 static_cast<float>(frame_count)
                                           : 0;

                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),
                                         {0, 0});

                std::cout << std::format(
                    "FPS: {:.0f}, AVG render time: {:.2f}ms, AVG frame time: "
                    "{:.2f}ms.",
                    fps, avg_render_time, avg_frame_time);

                frame_count = 0;
                render_time_accumulator = std::chrono::nanoseconds(0);
                last_fps_time = frame_start;
            }

            if (accumulated_delta_time.count() >= fixed_update_step) {
                input_receiver_->Update();
                actor_controller_->Update(*entity_manager_,
                                          input_receiver_->GetInputEvents());
                accumulated_delta_time -=
                    std::chrono::nanoseconds(fixed_update_step);
            }
            canvas_->Update(*entity_manager_, *renderer_);
            auto render_time_start = std::chrono::high_resolution_clock::now();
            renderer_->RenderFrame();
            renderer_->ResetFrame();
            auto render_time_elapsed =
                std::chrono::high_resolution_clock::now() - render_time_start;
            render_time_accumulator += render_time_elapsed;

            // auto frame_duration = std::chrono::duration_cast<std::chrono::microseconds>(frame_end - frame_start);
            // if (frame_duration < std::chrono::microseconds(SECOND_IN_MICROSECONDS / 60)) {
            //     std::this_thread::sleep_for(std::chrono::microseconds(SECOND_IN_MICROSECONDS / 60) - frame_duration);
            // }

            last_frame_time = frame_start;
        }
    }
}  // namespace Engine