#include <Windows.h>
#include <pplwin.h>

#include <iostream>
#include <ostream>
#include <random>
#include <thread>

#include "core/engine/Engine.h"


int main() {
    SetConsoleOutputCP(CP_UTF8);
    try {
        Engine::Engine engine;
        engine.Run();
    } catch (std::exception& e) {
        system("cls");
        std::cout << "EXCEPTION: " << e.what() << std::endl;
    }

    return 0;
}
