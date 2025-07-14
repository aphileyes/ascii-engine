//
// Created by Aphile on 14.07.2025.
//

#include "Scene.h"

#include "../Graphics/Render.h"

namespace Game {

    Scene::Scene() {}

    void Scene::AddGameObject(const GameObject& game_object) { _game_objects.push_back(game_object); }
    void Scene::RemoveGameObject(const GameObject& game_object) {}
    void Scene::Update() {
        for (GameObject& game_object: _game_objects) {
            game_object.Update(game_object.GetX(), game_object.GetY());
        }
    }

} // namespace Game
