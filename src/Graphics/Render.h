//
// Created by Aphile on 14.07.2025.
//

#ifndef RENDER_H
#define RENDER_H

#include <windows.h>

#include <vector>

namespace Graphics {
    class Render {
    public:
        Render(const unsigned int& width, const unsigned int& height, const double& fps);

        void Draw(int x_pos, int y_pos, char symbol);
        void ClearOutput();
        void RenderFrame();

    private:
        unsigned int _width, _height;
        double _frames_per_second;
        std::vector<std::vector<char>> _front_frame_buffer;
        std::vector<std::vector<char>> _back_frame_buffer;
    };

} // namespace Graphics

#endif // RENDER_H
