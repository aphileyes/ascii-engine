//
// Created by Aphile on 03.08.2025.
//

#ifndef GAMELOOP_H
#define GAMELOOP_H
#include <memory>

#include "../../ecs/entity/EntityManager.h"
#include "../../ecs/system/ActorController.h"
#include "../../ecs/system/Canvas.h"
#include "io/InputReceiver.h"

namespace Engine {

    class Engine {
    public:
        Engine();
        void Run();
        void Shutdown();

    private:
        void GameLoop();
        bool is_running_ = false;

        std::unique_ptr<System::Canvas> canvas_;
        std::unique_ptr<Graphics::Renderer> renderer_;
        std::unique_ptr<IO::InputReceiver> input_receiver_;
        std::unique_ptr<Entity::EntityManager> entity_manager_;
        std::unique_ptr<System::ActorController> actor_controller_;
    };

}  // namespace Engine

#endif  //GAMELOOP_H
