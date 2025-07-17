//
// Created by Aphile on 17.07.2025.
//

#include "TestScene.h"

namespace Scenes {

    TestScene::TestScene(const unsigned int width, const unsigned int height) {
        _width = width;
        _height = height;
    }

    void TestScene::AddGameObject(std::unique_ptr<Game::GameObject> game_object) {}
    void TestScene::RemoveGameObject(Game::GameObject& game_object) {}
    void TestScene::Update(float delta_time) const {}
    void TestScene::RenderUpdates(Graphics::IRender& render) const {}

    unsigned int TestScene::GetWidth() { return _width; }
    unsigned int TestScene::GetHeight() { return _height; }

}  // namespace Scenes
