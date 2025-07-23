//
// Created by Aphile on 19.07.2025.
//

#include "EntityAlive.h"

namespace Game {

    EntityAlive::EntityAlive(Position position, Size size, char symbol, float health) :
        GameObject(position, size, symbol) {
        _health = health;
    }

}  // namespace Game
