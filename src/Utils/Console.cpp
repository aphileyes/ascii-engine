//
// Created by Aphile on 15.07.2025.
//

#include "Console.h"

namespace Utils {

    Console::Console() {
        _console_handle = std::make_unique<HANDLE>(GetStdHandle(STD_OUTPUT_HANDLE));

        if (*_console_handle == INVALID_HANDLE_VALUE) {
            throw std::runtime_error("Failed to get console handle.");
        }
    }

    void Console::SetCursorPosition(const unsigned int x, const unsigned int y) const {
        const COORD coord = {static_cast<SHORT>(x), static_cast<SHORT>(y)};

        if (!SetConsoleCursorPosition(*_console_handle, coord)) {
            throw std::runtime_error("Failed to set console cursor position.");
        }
    }

    void Console::SetCursorVisibility(const bool visible) const {
        CONSOLE_CURSOR_INFO cursor_info;
        GetConsoleCursorInfo(*_console_handle, &cursor_info);
        cursor_info.bVisible = visible;

        if (!SetConsoleCursorInfo(*_console_handle, &cursor_info)) {
            throw std::runtime_error("Failed to set console cursor visibility.");
        }
    }

} // namespace Utils
