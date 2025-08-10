//
// Created by Aphile on 31.07.2025.
//

#include "Canvas.h"

#include <iostream>

#include "../../core/graphics/Renderer.h"

namespace System {

    void Canvas::Update(Entity::EntityManager& entity_manager,
                        Graphics::Renderer& render) {
        auto entities =
            entity_manager.GetEntitiesWithComponent<Component::Position,
                                                    Component::Size>();

        for (const auto& entity : entities) {
            const auto& position =
                entity_manager.GetComponent<Component::Position>(entity);
            const auto& size =
                entity_manager.GetComponent<Component::Size>(entity);
            const auto& sprite =
                entity_manager.GetComponent<Component::Sprite>(entity);

            render.DrawObject(*position, *size, *sprite);
        }
    }

}  // namespace System