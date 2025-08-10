//
// Created by Aphile on 30.07.2025.
//

#include "ActorController.h"

#include <iostream>

#include "../../../src/core/engine/io/KeyCodes.h"
#include "../../core/engine/io/InputReceiver.h"
#include "../component/Position.h"

namespace System {

    void ActorController::Update(Entity::EntityManager& entity_manager, const std::vector<IO::InputEvent>& input_events) {
        for (auto entity : entity_manager.GetEntitiesWithComponent<Component::Position>()) {
            auto position = entity_manager.GetComponent<Component::Position>(entity);

            for (auto [type, key] : input_events) {
                if (type == IO::KEY_HOLD)
                    switch (key) {
                        case KEY_W:
                            position->y -= 1;
                            break;
                        case KEY_S:
                            position->y += 1;
                            break;
                        case KEY_A:
                            position->x -= 1;
                            break;
                        case KEY_D:
                            position->x += 1;
                            break;
                    }
            }
        }
    }

    std::vector<std::type_index> ActorController::GetRequiredComponents() {
        return {std::type_index(typeid(Component::Position))};
    }

}  // namespace System