#include <iostream>
#include "Graphics/Render.h"

int main() {
    try {
        Graphics::Render render(5, 5, 60.0);

        while (true) {
            render.RenderFrame();
        }
    } catch (std::exception& e) {
        std::cerr << e.what();
    }
    return 0;
}
