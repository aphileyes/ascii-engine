//
// Created by Aphile on 17.07.2025.
//

#ifndef TESTSCENE_H
#define TESTSCENE_H
#include <vector>

#include "../Game/Game.h"

namespace Scenes {

    class TestScene final : public Game::Scene {
    public:
        TestScene(int width, int height);
    };

}  // namespace Scenes

#endif  // TESTSCENE_H
