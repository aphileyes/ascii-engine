//
// Created by Aphile on 14.07.2025.
//

#ifndef SCENE_H
#define SCENE_H
#include <memory>
#include <vector>

#include "GameObject.h"


namespace Graphics {
    class Render;
}
namespace Game {

    class Scene {
    public:
        Scene(unsigned int width, unsigned int height);
        void AddGameObject(std::unique_ptr<GameObject> game_object);
        void RemoveGameObject(const std::unique_ptr<GameObject>& game_object);
        void Update() const;
        void Render(Graphics::Render& render) const;

    private:
        unsigned int _width;
        unsigned int _height;

        std::vector<std::unique_ptr<GameObject>> _game_objects;
    };

} // namespace Game

#endif // SCENE_H
