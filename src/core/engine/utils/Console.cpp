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

        if (!GetConsoleScreenBufferInfo(*_c_handle,
                                        &_console_screen_buffer_info_backup)) {
            throw std::runtime_error(
                "Failed to get console screen buffer info.");
        }
    }

    void Console::SetCursorPosition(const unsigned int x,
                                    const unsigned int y) const {
        const COORD coord = {static_cast<short>(x), static_cast<short>(y)};

        if (!SetConsoleCursorPosition(*_c_handle, coord)) {
            throw std::runtime_error("Failed to set console cursor position.");
        }
    }

    void Console::SetCursorVisibility(const bool visible) const {
        CONSOLE_CURSOR_INFO cursor_info;

        if (!GetConsoleCursorInfo(*_c_handle, &cursor_info)) {
            throw std::runtime_error("Failed to get console cursor info.");
        }

        cursor_info.bVisible = visible;

        if (!SetConsoleCursorInfo(*_c_handle, &cursor_info)) {
            throw std::runtime_error(
                "Failed to set console cursor visibility.");
        }
    }
    void Console::SetWindowBufferSize(const COORD& buffer_size) {
        if (!SetConsoleScreenBufferSize(*_c_handle, buffer_size)) {
            throw std::runtime_error(
                "Failed to set console screen buffer size.");
        }
    }
    void Console::SetWindowSize(const SMALL_RECT& window_size) {
        if (!SetConsoleWindowInfo(*_c_handle, true, &window_size)) {
            throw std::runtime_error("Failed to set console window size.");
        }
    }

}  // namespace Utils
