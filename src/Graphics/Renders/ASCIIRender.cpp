//
// Created by Aphile on 17.07.2025.
//

#include "ASCIIRender.h"

#include <algorithm>
#include <iostream>

#include "../../Exceptions/RenderException.h"

namespace Graphics {
    ASCIIRender::ASCIIRender(const unsigned int width, const unsigned int height, const double fps,
                             std::unique_ptr<Utils::IConsole> console) :
        _width(width), _height(height), _frames_per_second(fps), _console(std::move(console)) {
        if (width == 0 || height == 0) {
            throw Exceptions::RenderException("Width and height must be greater than 0.");
        }

        if (fps <= 0) {
            throw Exceptions::RenderException("Fps must be greater than 0.");
        }

        _front_frame_buffer.resize(width, std::vector<char>(height, ' '));
        _back_frame_buffer.resize(width, std::vector<char>(height, ' '));

        _console->SetCursorPosition(0, 0);
        _console->SetCursorVisibility(false);
    }

    void ASCIIRender::RenderFrame() {
        for (unsigned int y = 0; y < GetHeight(); ++y) {
            bool is_line_changed = false;
            std::string current_line;

            for (unsigned int x = 0; x < GetWidth(); ++x) {
                // Рисуем только то, что обновилось, иначе -
                // в current_line добавляется информация из предыдущего кадра.

                // TODO: придумать такую реализацию, чтобы можно было воспользоваться memcpy
                // TODO: для экстра оптимизации.
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
            std::ranges::fill(row.begin(), row.end(), ' ');
        }
    }

    void ASCIIRender::Draw(const std::unique_ptr<Game::GameObject>& game_object) {
        const unsigned int x_start = game_object->GetX();
        const unsigned int y_start = game_object->GetY();

        const unsigned int object_width = game_object->GetWidth();
        const unsigned int object_height = game_object->GetHeight();

        const char symbol = game_object->GetSymbol();

        if (x_start + object_width > this->GetWidth() || y_start + object_height > this->GetHeight() ||
            x_start > this->GetWidth() || y_start > this->GetHeight()) {
            throw Exceptions::RenderException(
                    std::format("Coordinates out of range: (x: {}, y: {}). Valid range is: x: [0, {}], y: [0, {}].",
                                x_start + object_width, y_start + object_height, _width, _height));
        }

        for (unsigned int x = x_start; x < x_start + object_width && x < _width; ++x) {
            for (unsigned int y = y_start; y < y_start + object_height && y < _height; ++y) {
                _back_frame_buffer[x][y] = symbol;
            }
        }
    }

    unsigned int ASCIIRender::GetWidth() const { return _width; }
    unsigned int ASCIIRender::GetHeight() const { return _height; }
    double ASCIIRender::GetFramesPerSecond() const { return _frames_per_second; }

}  // namespace Graphics
