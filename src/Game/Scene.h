//
// Created by Aphile on 19.07.2025.
//

#ifndef SCENE_H
#define SCENE_H
#include <vector>

#include "../Graphics/IRender.h"
#include "GameObject.h"

namespace Game {

    class IScene {
    public:
        virtual ~IScene() = default;
        virtual void AddGameObject(const std::shared_ptr<GameObject>& game_object) = 0;
        virtual void RemoveGameObject(const std::shared_ptr<GameObject>& game_object) = 0;
        virtual void Update() const = 0;
        virtual void RenderUpdates(const std::unique_ptr<Graphics::IRender>& render) const = 0;

        virtual int GetWidth() = 0;
        virtual int GetHeight() = 0;

    protected:
        IScene() = default;
    };

    class Scene : public IScene {
    public:
        Scene(int width, int height);
        void AddGameObject(const std::shared_ptr<GameObject>& game_object) override;
        void RemoveGameObject(const std::shared_ptr<GameObject>& game_object) override;
        void Update() const override;
        void RenderUpdates(const std::unique_ptr<Graphics::IRender>& render) const override;
        int GetWidth() override;
        int GetHeight() override;

    private:
        int _width, _height;
        std::vector<std::shared_ptr<GameObject>> _game_objects;
    };

}  // namespace Game

#endif  // SCENE_H
