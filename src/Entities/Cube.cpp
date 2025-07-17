//
// Created by Aphile on 14.07.2025.
//

#include "Cube.h"

#include "../Game/Game.h"

void Cube::Update(float delta_time) {
    SetPosition(GetX() + 1, 0);

    if (GetX() == 110) {
        SetPosition(0, 0);
    }
}
