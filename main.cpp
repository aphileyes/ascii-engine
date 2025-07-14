#include "Graphics/Render.h"

int main() {

    Graphics::Render render(10, 10, 60.0);

    render.Draw(11, 11, ' ');

    return 0;
}
