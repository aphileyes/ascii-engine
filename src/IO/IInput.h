//
// Created by Aphile on 15.07.2025.
//

#ifndef IINPUT_H
#define IINPUT_H

#include <vector>

namespace IO {

#define KEY_PRESSED_MASK 0x8000

    enum InputType {
        KEY_PRESSED = 0,
        KEY_HOLD = 1,
        KEY_RELEASED = 2,
    };

    struct InputEvent {
        InputType type;
        int key_code;
    };

    class IInput {
    public:
        virtual ~IInput() = default;
        virtual void Update() = 0;

        [[nodiscard]]
        virtual std::vector<InputEvent> GetInputEvents() const = 0;

    protected:
        IInput() = default;
    };

}  // namespace IO

#endif  // IINPUT_H
