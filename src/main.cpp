#include <iostream>
#include "Graphics/Render.h"

int main() {
    try {
        Graphics::Render render(50, 10, 60.0);

        int posX = 0;

        while (true) {
            render.RenderFrame();

            render.Draw(posX % render.GetWidth(), 0, '*');
            posX++;
        }
    } catch (std::exception& e) {
        std::cerr << e.what();
    }
    return 0;
}
