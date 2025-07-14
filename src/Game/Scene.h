//
// Created by Aphile on 14.07.2025.
//

#ifndef SCENE_H
#define SCENE_H
#include <vector>

#include "GameObject.h"


namespace Game {

    class Scene {
    public:
        Scene();
        void AddGameObject(const GameObject& game_object);
        void RemoveGameObject(const GameObject& game_object);
        void Update();

    private:
        std::vector<GameObject> _game_objects;
    };

} // namespace Game

#endif // SCENE_H
