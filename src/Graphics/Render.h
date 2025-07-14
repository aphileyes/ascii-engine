//
// Created by Aphile 14.07.2025.
//

#ifndef RENDER_H
#define RENDER_H

#include <memory>
#include <vector>
#include <windows.h>

namespace Game {
    class GameObject;
}
namespace Graphics {

    struct Coordinates {
        unsigned int x;
        unsigned int y;
    };

    class Render {
    public:
        Render(unsigned int width, unsigned int height, double fps);

        void Draw(const Coordinates& coordinates, unsigned char symbol);
        void DrawGameObject(const std::unique_ptr<Game::GameObject>& game_object);
        void ClearOutput();
        void RenderFrame();
        auto FillScene(unsigned char symbol = '.') -> void;
        static void SetCursorPosition(int x, int y);
        static void SetCursorVisibility(bool visible);
        unsigned int GetWidth() const;
        unsigned int GetHeight() const;
        double GetFramesPerSecond() const;


    private:
        unsigned int _width;
        unsigned int _height;

        double _frames_per_second;

        std::vector<std::vector<char>> _front_frame_buffer;
        std::vector<std::vector<char>> _back_frame_buffer;
    };

} // namespace Graphics

#endif // RENDER_H
