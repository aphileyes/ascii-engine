//
// Created by Aphile on 14.07.2025.
//

#ifndef CUBE_H
#define CUBE_H
#include "../Game/GameObject.h"


class Cube final : public Game::GameObject {
public:
    Cube(unsigned int x, unsigned int y, unsigned int width, unsigned int height, char symbol) :
        GameObject(x, y, width, height, symbol) {}

    void Update() override;
};


#endif // CUBE_H
