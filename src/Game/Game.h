//
// Created by Aphile on 14.07.2025.
//

#ifndef GAME_H
#define GAME_H
#include <memory>

#include "../Graphics/Render.h"
#include "../Utils/Console.h"
#include "Scene.h"

namespace Game {

    class Game {
    public:
        explicit Game(std::unique_ptr<Graphics::IRender> render);
        void Run();
        void Stop();

    private:
        void GameLoop() const;
        bool _is_running;

        std::unique_ptr<Graphics::IRender> _render;
        std::unique_ptr<Scene> _scene;
    };

}  // namespace Game

#endif  // GAME_H
