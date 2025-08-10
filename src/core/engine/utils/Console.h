//
// Created by Aphile on 15.07.2025.
//

#ifndef CONSOLE_H
#define CONSOLE_H

#include <windows.h>
#include <memory>

namespace Utils {

    class Console {
    public:
        Console();
        void SetCursorPosition(unsigned int x, unsigned int y) const;
        void SetCursorVisibility(bool visible) const;
        void SetWindowBufferSize(const COORD& buffer_size);
        void SetWindowSize(const SMALL_RECT& window_size);

    private:
        std::unique_ptr<HANDLE> _c_handle;
        CONSOLE_SCREEN_BUFFER_INFO _console_screen_buffer_info_backup;
    };

}  // namespace Utils

#endif  // CONSOLE_H
