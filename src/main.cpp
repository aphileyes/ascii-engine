#include <format>
#include <iostream>

#include "Game/Game.h"

static_assert(_WIN32, "This engine only works on windows platform.");

int main() {
    try {
        Game::Game game(50, 5, 60.0);
        game.Run();
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
