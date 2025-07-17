//
// Created by Aphile on 14.07.2025.
//

#include "Cube.h"

#include <Windows.h>

#include "../Game/Game.h"

void Cube::Update(float delta_time) {
    if (GetAsyncKeyState('W') & 0x8000) {  // 0x8000 проверяет, нажата ли клавиша
        SetPosition(GetWidth(), GetHeight() - 1);
    }
    if (GetAsyncKeyState('A') & 0x8000) {
        SetPosition(GetWidth() - 1, GetHeight());
    }
    if (GetAsyncKeyState('S') & 0x8000) {
        SetPosition(GetWidth(), GetHeight() + 1);
    }
    if (GetAsyncKeyState('D') & 0x8000) {
        SetPosition(GetWidth() + 1, GetHeight());
    }
}
