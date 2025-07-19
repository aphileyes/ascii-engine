//
// Created by Aphile on 19.07.2025.
//

#include "ActorController.h"

#include <vector>

#include "../IInput.h"

namespace Game {
    ActorController::ActorController(const std::shared_ptr<Actor>& actor) { _actor = actor; }

    void ActorController::Update(const std::vector<IO::InputEvent>& input_events) {
        for (auto [type, key_code]: input_events) {
            switch (key_code) {
                case 'W':
                    _actor->SetPosition({_actor->GetX(), _actor->GetY() - 1});
                    break;

                case 'A':
                    _actor->SetPosition({_actor->GetX() - 1, _actor->GetY()});
                    break;

                case 'S':
                    _actor->SetPosition({_actor->GetX(), _actor->GetY() + 1});
                    break;

                case 'D':
                    _actor->SetPosition({_actor->GetX() + 1, _actor->GetY()});
                    break;

                default:
                    break;
            }
        }
    }
}  // namespace Game
