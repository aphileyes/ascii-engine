//
// Created by Aphile on 19.07.2025.
//

#include "Scene.h"

#include <stdexcept>

namespace Game {

    Scene::Scene(int width, int height) {
        if (width <= 0 || height <= 0) {
            throw std::invalid_argument("Scene width and height must be greater than 0.");
        }

        _width = width;
        _height = height;
    }

    void Scene::AddGameObject(const std::shared_ptr<GameObject>& game_object) { _game_objects.push_back(game_object); }

    void Scene::RemoveGameObject(const std::shared_ptr<GameObject>& game_object) {
        if (_game_objects.empty()) {
            return;
        }

        std::erase_if(_game_objects, [&](const std::shared_ptr<GameObject>& iterator_object) {
            return iterator_object == game_object;
        });
    }

    void Scene::Update(const std::unique_ptr<Graphics::IRender>& render, float delta_time) const {
        for (const auto& game_object: _game_objects) {
            game_object->Update(delta_time);
        }

        for (const auto& game_object: _game_objects) {
            render->Draw(game_object);
        }
    }

    int Scene::GetWidth() { return _width; }
    int Scene::GetHeight() { return _height; }

}  // namespace Game
