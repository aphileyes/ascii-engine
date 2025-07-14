//
// Created by Aphile on 14.07.2025.
//

#include "Render.h"

#include <algorithm>
#include <format>
#include <iostream>
#include <string>

#include "../Exceptions/RenderException.h"

namespace Graphics {

    Render::Render(const unsigned int width, const unsigned int height, const double fps) {
        if (width == 0 || height == 0) {
            throw Exceptions::RenderException("Width and height must be greater than 0.");
        }

        if (fps <= 0) {
            throw Exceptions::RenderException("Fps must be greater than 0.");
        }

        _width = width;
        _height = height;
        _frames_per_second = fps;

        _front_frame_buffer.resize(width, std::vector<char>(height, ' '));
        _back_frame_buffer.resize(width, std::vector<char>(height, '.'));

        SetCursorVisibility(false);
        SetCursorPosition(0, 0);
    }

    void Render::ClearOutput() {
        for (auto& row: _back_frame_buffer) {
            std::ranges::fill(row.begin(), row.end(), ' ');
        }
    }

    void Render::FillScene(unsigned char symbol) {
        for (auto& row: _back_frame_buffer) {
            std::ranges::fill(row.begin(), row.end(), '.');
        }
    }

    void Render::Draw(const Coordinates& coordinates, const unsigned char symbol = '.') {
        if (coordinates.x > GetWidth() || coordinates.y > GetHeight()) {
            throw Exceptions::RenderException(
                    std::format("Coordinates out of range: (x: {}, y: {}). Valid range is: x: [0, {}], y: [0, {}].",
                                coordinates.x, coordinates.y, _width, _height));
        }
        _back_frame_buffer[coordinates.x][coordinates.y] = symbol;
    }

    void Render::RenderFrame() {
        for (int x = 0; x < _width; ++x) {
            for (int y = 0; y < _height; ++y) {
                if (_front_frame_buffer[x][y] != _back_frame_buffer[x][y]) {
                    SetCursorPosition(x, y);
                    std::cout << _back_frame_buffer[x][y];
                    _front_frame_buffer[x][y] = _back_frame_buffer[x][y];
                }
            }
        }
        std::cout << std::flush;

        FillScene('.');
        SetCursorPosition(0, 0);
    }

    void Render::SetCursorPosition(const int x, const int y) {
#ifndef _WIN32
        throw Exceptions::RenderException("SetCursorPosition not working outside windows platform.");
#endif
        const HANDLE console_handle = GetStdHandle(STD_OUTPUT_HANDLE);
        if (console_handle == INVALID_HANDLE_VALUE) {
            throw Exceptions::RenderException("Failed to get console handle.");
        }

        const COORD coord = {static_cast<SHORT>(x), static_cast<SHORT>(y)};
        if (!SetConsoleCursorPosition(console_handle, coord)) {
            throw Exceptions::RenderException("Failed to set console cursor position.");
        }
    }

    void Render::SetCursorVisibility(const bool visible) {
        const HANDLE console_handle = GetStdHandle(STD_OUTPUT_HANDLE);

        if (console_handle == INVALID_HANDLE_VALUE) {
            throw Exceptions::RenderException("Failed to get console handle.");
        }

        CONSOLE_CURSOR_INFO cursor_info;
        GetConsoleCursorInfo(console_handle, &cursor_info);

        cursor_info.bVisible = visible;
        SetConsoleCursorInfo(console_handle, &cursor_info);
    }

    // --- GETTERS --- GETTERS --- GETTERS --- GETTERS --- GETTERS --- GETTERS ---

    unsigned int Render::GetWidth() const { return _width - 1; }
    unsigned int Render::GetHeight() const { return _height - 1; }
    double Render::GetFramesPerSecond() const { return _frames_per_second; }

} // namespace Graphics
