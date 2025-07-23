//
// Created by Aphile 14.07.2025.
//

#ifndef RENDER_H
#define RENDER_H

#include <memory>

#include "../Game/GameObject.h"

namespace Graphics {

    class IRender {
    public:
        virtual ~IRender() = default;

        virtual void Draw(const std::shared_ptr<Game::GameObject>& game_object) = 0;
        virtual void ResetFrame() = 0;
        virtual void RenderFrame() = 0;

        [[nodiscard]] virtual unsigned int GetWidth() const = 0;
        [[nodiscard]] virtual unsigned int GetHeight() const = 0;
        [[nodiscard]] virtual int GetFramesPerSecond() const = 0;

    protected:
        IRender() = default;
    };

}  // namespace Graphics

#endif  // RENDER_H
