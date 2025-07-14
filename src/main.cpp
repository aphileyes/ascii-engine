#include <format>
#include <iostream>

#include "Game/Game.h"

int main() {
    try {
        Game::Game game(120, 30, 60.0);
        game.Run();
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
