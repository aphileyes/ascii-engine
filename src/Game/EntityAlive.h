//
// Created by Aphile on 19.07.2025.
//

#ifndef ENTITYALIVE_H
#define ENTITYALIVE_H
#include "GameObject.h"

namespace Game {

    class EntityAlive : public GameObject {
    public:
        EntityAlive(Position position, Size size, char symbol, float health);

        [[nodiscard]]
        float GetHealth() const {
            return _health;
        };

        void SetHealth(float health) { _health = health; }

    private:
        float _health;
    };

}  // namespace Game

#endif  // ENTITYALIVE_H
