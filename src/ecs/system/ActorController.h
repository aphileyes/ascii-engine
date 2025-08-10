//
// Created by Aphile on 30.07.2025.
//

#ifndef ACTORCONTROLLER_H
#define ACTORCONTROLLER_H
#include <memory>

#include "../../core/engine/io/IInput.h"
#include "../entity/EntityManager.h"

namespace System {

    class ActorController {
    public:
        ActorController() = default;
        void Update(Entity::EntityManager& entity_manager,
                    const std::vector<IO::InputEvent>& input_events);
        std::vector<std::type_index> GetRequiredComponents();

    private:
    };

}  // namespace System

#endif  //ACTORCONTROLLER_H
