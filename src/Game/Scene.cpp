//
// Created by Aphile on 14.07.2025.
//

#include "Scene.h"

#include <algorithm>

#include "../Graphics/Render.h"

namespace Game {

    Scene::Scene(const unsigned int width, const unsigned int height) {
        _width = width;
        _height = height;
    }

    void Scene::AddGameObject(std::unique_ptr<GameObject> game_object) {
        _game_objects.push_back(std::move(game_object));
    }

    void Scene::RemoveGameObject(const std::unique_ptr<GameObject>& game_object) {
        std::erase_if(_game_objects,
                      [&game_object](const std::unique_ptr<GameObject>& ptr_to_current_vector_game_object) {
                          return &ptr_to_current_vector_game_object == &game_object;
                      });
    }

    void Scene::Update() const {
        for (auto& game_object: _game_objects) {
            game_object->Update();
        }
    }

    void Scene::Render(Graphics::Render& render) const {
        for (const auto& game_object: _game_objects) {
            render.DrawGameObject(game_object);
        }
    }

} // namespace Game
