//
// Created by Aphile on 14.07.2025.
//

#ifndef GAME_H
#define GAME_H
#include <memory>


#include "../Graphics/Render.h"
#include "Scene.h"

namespace Game {

    class Game {
    public:
        Game(unsigned int width, unsigned int height, double fps);
        void Run();
        void Stop();

        // Graphics::Render* GetRenderInstance() const;

    private:
        std::unique_ptr<Scene> _scene;
        std::unique_ptr<Graphics::Render> _render;

        bool _is_running = false;
        unsigned int _width;
        unsigned int _height;
        double _fps;

        void GameLoop() const;
    };

} // namespace Game

#endif // GAME_H
