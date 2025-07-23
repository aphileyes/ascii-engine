//
// Created by Aphile on 14.07.2025.
//

#include "Actor.h"

#include <iostream>

namespace Game {

    Actor::Actor(Position position, Size size, const char symbol, float health) :
        EntityAlive(position, size, symbol, health) {
        _health = health;
    }

    void Actor::Update(float delta_time) {}

}  // namespace Game
