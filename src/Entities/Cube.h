//
// Created by Aphile on 14.07.2025.
//

#ifndef CUBE_H
#define CUBE_H
#include "../Game/GameObject.h"


class Cube final : public Game::GameObject {
public:
    Cube(const unsigned int x, const unsigned int y, const unsigned int width, const unsigned int height,
         const char symbol) : GameObject(x, y, width, height, symbol) {}

    void Update(float delta_time) override;
};


#endif // CUBE_H
