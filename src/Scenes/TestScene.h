//
// Created by Aphile on 17.07.2025.
//

#ifndef TESTSCENE_H
#define TESTSCENE_H
#include <vector>

#include "../Game/Game.h"

namespace Scenes {

    class TestScene final : public Game::IScene {
    public:
        TestScene(unsigned int width, unsigned int height);

        void AddGameObject(std::unique_ptr<Game::GameObject> game_object) override;
        void RemoveGameObject(Game::GameObject& game_object) override;
        void Update(float delta_time) const override;
        void RenderUpdates(Graphics::IRender& render) const override;

        [[nodiscard]] unsigned int GetWidth() override;
        [[nodiscard]] unsigned int GetHeight() override;

    private:
        unsigned int _width;
        unsigned int _height;

        std::vector<std::unique_ptr<Game::GameObject>> game_objects;
    };

}  // namespace Scenes

#endif  // TESTSCENE_H
