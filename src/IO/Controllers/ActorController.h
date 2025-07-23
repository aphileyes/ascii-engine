//
// Created by Aphile on 19.07.2025.
//

#ifndef ACTORCONTROLLER_H
#define ACTORCONTROLLER_H

#include <memory>
#include <vector>

#include "../../Game/Actor.h"
#include "../../Game/GameObject.h"
#include "../IInput.h"

namespace Game {

    class ActorController {
    public:
        explicit ActorController(const std::shared_ptr<Actor>& actor);

        void Update(const std::vector<IO::InputEvent>& input_events, float delta_time);

    private:
        std::shared_ptr<GameObject> _actor;
    };

}  // namespace Game

#endif  // ACTORCONTROLLER_H
