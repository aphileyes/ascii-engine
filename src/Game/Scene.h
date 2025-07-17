//
// Created by Aphile on 14.07.2025.
//

#ifndef SCENE_H
#define SCENE_H
#include <memory>
#include <vector>

#include "../Graphics/Render.h"
#include "GameObject.h"


namespace Game {

    class Scene {
    public:
        Scene(unsigned int width, unsigned int height);
        void AddGameObject(std::unique_ptr<GameObject> game_object);
        void RemoveGameObject(GameObject& game_object);
        void Update(float delta_time) const;
        void RenderUpdates(Graphics::IRender& render) const;

    private:
        unsigned int _width;
        unsigned int _height;

        std::vector<std::unique_ptr<GameObject>> _game_objects;
    };

} // namespace Game

#endif // SCENE_H
