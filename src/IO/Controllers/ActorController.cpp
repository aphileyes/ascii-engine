//
// Created by Aphile on 19.07.2025.
//

#include "ActorController.h"

#include <vector>

#include "../KeyCodes.h"

namespace Game {

    ActorController::ActorController(const std::shared_ptr<Actor>& actor) { _actor = actor; }

    void ActorController::Update(const std::vector<IO::InputEvent>& input_events, float delta_time) {
        for (auto [type, key_code]: input_events) {
            switch (key_code) {
                case KEY_W:
                    _actor->SetPosition({_actor->GetX(), _actor->GetY() - 1});
                    break;

                case KEY_A:
                    _actor->SetPosition({_actor->GetX() - 1, _actor->GetY()});
                    break;

                case KEY_S:
                    _actor->SetPosition({_actor->GetX(), _actor->GetY() + 1});
                    break;

                case KEY_D:
                    _actor->SetPosition({_actor->GetX() + 1, _actor->GetY()});
                    break;

                default:
                    break;
            }
        }
    }

}  // namespace Game
