//
// Created by Aphile on 15.07.2025.
//

#include "Console.h"

#include <stdexcept>

namespace Utils {

    Console::Console() {
        _c_handle = std::make_unique<HANDLE>(GetStdHandle(STD_OUTPUT_HANDLE));

        if (*_c_handle == INVALID_HANDLE_VALUE) {
            throw std::runtime_error("Failed to get console handle.");
        }
    }

    void Console::SetCursorPosition(const unsigned int x, const unsigned int y) const {
        const COORD coord = {static_cast<short>(x), static_cast<short>(y)};

        if (!SetConsoleCursorPosition(*_c_handle, coord)) {
            throw std::runtime_error("Failed to set console cursor position.");
        }
    }

    void Console::SetCursorVisibility(const bool visible) const {
        CONSOLE_CURSOR_INFO cursor_info;
        GetConsoleCursorInfo(*_c_handle, &cursor_info);
        cursor_info.bVisible = visible;

        if (!SetConsoleCursorInfo(*_c_handle, &cursor_info)) {
            throw std::runtime_error("Failed to set console cursor visibility.");
        }
    }
    void Console::SetWindowSize(const COORD size) const {
        if (!SetConsoleScreenBufferSize(*_c_handle, size)) {
            throw std::runtime_error("Failed to set console screen buffer size.");
        }
    }

}  // namespace Utils
