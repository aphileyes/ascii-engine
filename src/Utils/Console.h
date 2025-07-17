//
// Created by Aphile on 15.07.2025.
//

#ifndef CONSOLE_H
#define CONSOLE_H

#include <memory>
#include <stdexcept>
#include <windows.h>


namespace Utils {

    struct IConsole {
        virtual void SetCursorPosition(unsigned int x, unsigned int y) const = 0;
        virtual void SetCursorVisibility(bool visible) const = 0;
        virtual ~IConsole() = default;
    };

    class Console final : public IConsole {
    public:
        Console();
        void SetCursorPosition(unsigned int x, unsigned int y) const override;
        void SetCursorVisibility(bool visible) const override;

    private:
        std::unique_ptr<HANDLE> _console_handle;
    };

} // namespace Utils

#endif // CONSOLE_H
