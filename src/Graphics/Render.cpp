//
// Created by Aphile on 14.07.2025.
//

#include "Render.h"

#include <algorithm>
#include <iostream>
#include <string>

#include "../Exceptions/RenderException.h"

namespace Graphics {
    Render::Render(const unsigned int& width, const unsigned int& height, const double& fps) {
        _width = width;
        _height = height;
        _frames_per_second = fps;

        _front_frame_buffer.resize(height, std::vector<char>(width, '.'));
        _back_frame_buffer.resize(height, std::vector<char>(width, '.'));
    }

    void SetCursorPosition(const int x, const int y) {
#ifndef _WIN32
        throw Exceptions::RenderException("SetCursorPosition not working outside windows platform.");
#endif
        const HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        if (hConsole == INVALID_HANDLE_VALUE) {
            throw Exceptions::RenderException("Failed to get console handle.");
        }

        const COORD coord = {static_cast<SHORT>(x), static_cast<SHORT>(y)};
        if (!SetConsoleCursorPosition(hConsole, coord)) {
            throw Exceptions::RenderException("Failed to set console cursor position.");
        }
    }

    void SetCursorVisibility(const bool& visible) {
        const HANDLE console_handle = GetStdHandle(STD_OUTPUT_HANDLE);

        if (console_handle == INVALID_HANDLE_VALUE) {
            throw Exceptions::RenderException("Failed to get console handle.");
        }

        CONSOLE_CURSOR_INFO cursor_info;
        GetConsoleCursorInfo(console_handle, &cursor_info);

        if (cursor_info.dwSize != sizeof(CONSOLE_CURSOR_INFO)) {
            throw Exceptions::RenderException("Failed to get cursor info.");
        }

        cursor_info.bVisible = visible;
        SetConsoleCursorInfo(console_handle, &cursor_info);
    }

    void Render::ClearOutput() {
        for (auto& row: _back_frame_buffer) {
            std::ranges::fill(row.begin(), row.end(), ' ');
        }
    }

    void Render::Draw(const int x_pos, const int y_pos, const char symbol = '.') {
        if (x_pos > _width || y_pos > _height || y_pos < 0 || x_pos < 0) {
            throw Exceptions::RenderException("Coordinates out of range: (x: " + std::to_string(x_pos) +
                                              ", y: " + std::to_string(y_pos) + "). Valid range is x: [0, " +
                                              std::to_string(_width) + "], y: [0, " + std::to_string(_height) + "].");
        }
        _front_frame_buffer[x_pos][y_pos] = symbol;
        // _back_frame_buffer[x_pos][y_pos] = symbol;
    }

    void Render::RenderFrame() {
        for (int x = 0; x < _width; ++x) {
            for (int y = 0; y < _height; ++y) {
                SetCursorPosition(x, y);
                std::cout << _front_frame_buffer[x][y];
                // if (_front_frame_buffer[x][y] != _back_frame_buffer[x][y]) {
                //     SetCursorPosition(x, y);
                //     std::cout << _back_frame_buffer[x][y];
                //     _front_frame_buffer[x][y] = _back_frame_buffer[x][y];
                // }
            }
        }
        // std::cout << std::flush;
        SetCursorPosition(0, 0);
        ClearOutput();
    }

} // namespace Graphics
