//
// Created by Aphile on 14.07.2025.
//

#ifndef ACTOR_H
#define ACTOR_H
#include "EntityAlive.h"
#include "GameObject.h"

namespace Game {

    class Actor final : public EntityAlive {
    public:
        Actor(Position position, Size size, char symbol, float health);

        void Update(float delta_time) override;

    private:
        float _health;
    };

}  // namespace Game

#endif  // ACTOR_H
