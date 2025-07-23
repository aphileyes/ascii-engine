//
// Created by Aphile on 21.07.2025.
//

#include "EntityFactory.h"

#include <stdexcept>

#include "../Game/Actor.h"

namespace Factory {

    std::shared_ptr<Game::EntityAlive> EntityFactory::CreateEntity(const std::string& type,
                                                                   Game::GameObject::Position pos,
                                                                   Game::GameObject::Size size, char symbol,
                                                                   float health) {
        if (type == "Actor") {
            return std::make_shared<Game::Actor>(pos, size, symbol, health);
        } else if (type == "Enemy") {
            // return std::make_shared<Enemy>(pos, size, symbol, health);
        }
        throw std::invalid_argument("Unknown entity type");
    }


}  // namespace Factory
