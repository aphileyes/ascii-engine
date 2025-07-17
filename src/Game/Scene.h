//
// Created by Aphile on 17.07.2025.
//

#ifndef SCENE_H
#define SCENE_H
#include <memory>

#include "../Graphics/IRender.h"

namespace Game {

    class IScene {
    public:
        virtual ~IScene() = default;
        virtual void AddGameObject(std::unique_ptr<GameObject> game_object) = 0;
        virtual void RemoveGameObject(GameObject& game_object) = 0;
        virtual void Update(float delta_time) const = 0;
        virtual void RenderUpdates(Graphics::IRender& render) const = 0;

        virtual unsigned int GetWidth() = 0;
        virtual unsigned int GetHeight() = 0;

    protected:
        IScene() = default;
    };

}  // namespace Game

#endif  // SCENE_H
