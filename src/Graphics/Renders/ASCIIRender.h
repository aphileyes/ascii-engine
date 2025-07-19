//
// Created by Aphile on 17.07.2025.
//

#ifndef ASCIIRENDER_H
#define ASCIIRENDER_H
#include <vector>

#include "../../Utils/Console.h"
#include "../IRender.h"

namespace Graphics {

    class ASCIIRender final : public IRender {
    public:
        ASCIIRender(int width, int height, int fps, std::unique_ptr<Utils::Console> console);

        void Draw(const std::shared_ptr<Game::GameObject>& game_object) override;
        void ResetFrame() override;
        void RenderFrame() override;

        [[nodiscard]]
        unsigned GetWidth() const override;
        [[nodiscard]]
        unsigned GetHeight() const override;
        [[nodiscard]]
        int GetFramesPerSecond() const override;

    private:
        unsigned int _width;
        unsigned int _height;

        int _frames_per_second;

        std::unique_ptr<Utils::Console> _console;

        std::vector<std::vector<char>> _front_frame_buffer;
        std::vector<std::vector<char>> _back_frame_buffer;
    };

}  // namespace Graphics

#endif  // ASCIIRENDER_H
