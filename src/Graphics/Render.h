//
// Создан Aphile 14.07.2025.
//

#ifndef RENDER_H
#define RENDER_H

#include <vector>
#include <windows.h>

namespace Graphics {
    class Render {
    public:
        Render(const unsigned int& width, const unsigned int& height, const double& fps);

        void Draw(unsigned int x_pos, unsigned int y_pos, unsigned char symbol);
        void ClearOutput();
        void RenderFrame();
        void FillScene(unsigned char symbol = '.');
        static void SetCursorPosition(const int x, const int y);
        static void SetCursorVisibility(const bool visible);
        unsigned int GetWidth() const;
        unsigned int GetHeight() const;

    private:
        unsigned int _width;
        unsigned int _height;

        double _frames_per_second;

        std::vector<std::vector<char>> _front_frame_buffer;
        std::vector<std::vector<char>> _back_frame_buffer;
    };

} // namespace Graphics

#endif // RENDER_H
