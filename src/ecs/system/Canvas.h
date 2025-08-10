//
// Created by Aphile on 31.07.2025.
//

#ifndef RENDERER_H
#define RENDERER_H
#include "../../core/graphics/Renderer.h"
#include "../entity/EntityManager.h"

namespace System {

    class Canvas {
    public:
        Canvas() = default;
        void Update(Entity::EntityManager& entity_manager,
                    Graphics::Renderer& render);
    };

}  // namespace System

#endif  //RENDERER_H
