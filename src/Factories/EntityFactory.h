//
// Created by Aphile on 21.07.2025.
//

#ifndef ENTITYFACTORY_H
#define ENTITYFACTORY_H
#include <memory>
#include <string>

#include "../Game/EntityAlive.h"

namespace Factory {

    class EntityFactory {
    public:
        static std::shared_ptr<Game::EntityAlive> CreateEntity(const std::string& type, Game::GameObject::Position pos,
                                                               Game::GameObject::Size size, char symbol, float health);
    };

}  // namespace Factory

#endif  // ENTITYFACTORY_H
