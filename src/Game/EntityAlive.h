//
// Created by Aphile on 19.07.2025.
//

#ifndef ENTITYALIVE_H
#define ENTITYALIVE_H
#include "GameObject.h"

namespace Game {

    class EntityAlive : public GameObject {
    public:
        EntityAlive(Position position, Size size, char symbol, float health) : GameObject(position, size, symbol) {
            _health = health;
        }

        void Update() override = 0;

    private:
        float _health;
    };

}  // namespace Game

#endif  // ENTITYALIVE_H
