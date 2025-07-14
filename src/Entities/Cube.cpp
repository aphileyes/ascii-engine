//
// Created by Aphile on 14.07.2025.
//

#include "Cube.h"

#include "../Game/Game.h"

void Cube::Update() {
    SetPosition(GetX() + 3, 0);

    if (GetX() == 110) {
        SetPosition(0, 0);
    }
}
