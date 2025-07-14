//
// Created by Aphile on 14.07.2025.
//

#ifndef RENDER_H
#define RENDER_H
#include <utility>
#include <vector>
#include <bits/basic_string.h>

namespace Graphics {
    class Render {
    public:
        Render(const int &width, const int &height, const double &fps);
        // ~Render();

        void Clear();
        void Draw(const int x, const int y, const char symbol);
        void SetSymbol();
        void RenderFrame();

    private:
        int _width, _height;
        double _framesPerSecond;
        std::vector<std::vector<char>> _frameBuffer;
        std::vector<std::vector<char>> _backFrameBuffer;
    };

} // Graphics

#endif //RENDER_H
