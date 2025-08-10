//
// Created by Aphile 14.07.2025.
//

#ifndef RENDER_H
#define RENDER_H

#include <memory>

#include "../../ecs/component/Position.h"
#include "../../ecs/component/Size.h"
#include "../../ecs/component/Sprite.h"

namespace Graphics {

    class IRender {
    public:
        virtual ~IRender() = default;

        virtual void DrawObject(const Component::Position& position,
                                const Component::Size size,
                                const Component::Sprite& sprite) = 0;
        virtual void ResetFrame() = 0;
        virtual void RenderFrame() = 0;

        [[nodiscard]] virtual int GetWidth() const = 0;
        [[nodiscard]] virtual int GetHeight() const = 0;

    protected:
        IRender() = default;
    };

}  // namespace Graphics

#endif  // RENDER_H
