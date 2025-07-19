//
// Created by Aphile on 15.07.2025.
//

#ifndef CONSOLE_H
#define CONSOLE_H

#include <memory>
#include <windows.h>

namespace Utils {

    class Console {
    public:
        Console();
        void SetCursorPosition(unsigned int x, unsigned int y) const;
        void SetCursorVisibility(bool visible) const;
        void SetWindowSize(COORD size) const;

    private:
        std::unique_ptr<HANDLE> _c_handle;
    };

}  // namespace Utils

#endif  // CONSOLE_H
