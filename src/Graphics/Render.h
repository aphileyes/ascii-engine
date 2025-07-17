//
// Created by Aphile 14.07.2025.
//

#ifndef RENDER_H
#define RENDER_H

#include <memory>
#include <vector>
#include <windows.h>

#include "../Utils/Console.h"

namespace Game {
    class GameObject;
}
namespace Graphics {
    struct Coordinates {
        unsigned int x;
        unsigned int y;
    };

    class IRender {
    public:
        virtual ~IRender() = default;

        virtual void Draw(const std::unique_ptr<Game::GameObject>& game_object) = 0;
        virtual void ResetFrame() = 0;
        virtual void RenderFrame() = 0;
        [[nodiscard]] virtual unsigned int GetWidth() const = 0;
        [[nodiscard]] virtual unsigned int GetHeight() const = 0;
        [[nodiscard]] virtual double GetFramesPerSecond() const = 0;

    protected:
        IRender() = default;
    };

    class ASCIIRender final : public IRender {
    public:
        ASCIIRender(unsigned int width, unsigned int height, double fps, std::unique_ptr<Utils::IConsole> console);

        void RenderFrame() override;
        void ResetFrame() override;
        void Draw(const std::unique_ptr<Game::GameObject>& game_object) override;

        [[nodiscard]] unsigned int GetWidth() const override;
        [[nodiscard]] unsigned int GetHeight() const override;
        [[nodiscard]] double GetFramesPerSecond() const override;

    private:
        unsigned int _width;
        unsigned int _height;

        double _frames_per_second;

        std::unique_ptr<Utils::IConsole> _console;

        std::vector<std::vector<char>> _front_frame_buffer;
        std::vector<std::vector<char>> _back_frame_buffer;
    };

} // namespace Graphics

#endif // RENDER_H
