//
// Created by Aphile on 17.07.2025.
//

#include "ASCIIRender.h"

#include <algorithm>
#include <iostream>

namespace Graphics {

    ASCIIRender::ASCIIRender(int width, int height, int fps, std::unique_ptr<Utils::Console> console) {
        if (width <= 0 || height <= 0) {
            throw std::invalid_argument("Width and height must be greater than 0.");
        }

        _width = width;
        _height = height;

        if (fps < 0) {
            throw std::runtime_error("Fps must be 0 (disable fps lock) or greater.");
        }

        _frames_per_second = fps;

        _front_frame_buffer.resize(width, std::vector(height, ' '));
        _back_frame_buffer.resize(width, std::vector(height, '.'));

        _console = std::move(console);

        _console->SetCursorPosition(0, 0);
        _console->SetCursorVisibility(false);
    }

    void ASCIIRender::RenderFrame() {
        for (int y = 0; y < GetHeight(); ++y) {
            bool is_line_changed = false;
            std::string current_line;

            for (int x = 0; x < GetWidth(); ++x) {
                if (_front_frame_buffer[x][y] != _back_frame_buffer[x][y]) {
                    current_line += _back_frame_buffer[x][y];
                    _front_frame_buffer[x][y] = _back_frame_buffer[x][y];
                    is_line_changed = true;
                } else {
                    current_line += _front_frame_buffer[x][y];
                }
            }

            if (is_line_changed) {
                _console->SetCursorPosition(0, y);
                std::cout << current_line;
            }
        }
        ResetFrame();
    }

    void ASCIIRender::ResetFrame() {
        for (auto& row: _back_frame_buffer) {
            std::ranges::fill(row.begin(), row.end(), '.');
        }
    }

    void ASCIIRender::Draw(const std::shared_ptr<Game::GameObject>& game_object) {
        char symbol = game_object->GetSymbol();

        int object_width = game_object->GetX() + game_object->GetWidth();
        int object_height = game_object->GetY() + game_object->GetHeight();

        int x_clamp = std::clamp<int>(game_object->GetX(), 0, GetWidth());
        int y_clamp = std::clamp<int>(game_object->GetY(), 0, GetHeight());

        int x_object_width_clamp = std::clamp<int>(object_width, 0, GetWidth());
        int y_object_height_clamp = std::clamp<int>(object_height, 0, GetHeight());

        for (int x = x_clamp; x < x_object_width_clamp; ++x) {
            for (int y = y_clamp; y < y_object_height_clamp; ++y) {
                _back_frame_buffer[x][y] = symbol;
            }
        }
    }

    unsigned int ASCIIRender::GetWidth() const { return _width; }
    unsigned int ASCIIRender::GetHeight() const { return _height; }
    int ASCIIRender::GetFramesPerSecond() const { return _frames_per_second; }

}  // namespace Graphics
