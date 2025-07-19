//
// Created by Aphile on 15.07.2025.
//

#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include <vector>

namespace IO {
    enum InputType {
        KEY_PRESSED,
        KEY_RELEASED,
    };

    struct InputEvent {
        InputType type;
        int key_code;
    };

    class IInput {
    public:
        virtual ~IInput() = default;
        virtual void Update() = 0;
        virtual std::vector<InputEvent> GetInputEvents() const = 0;

    protected:
        IInput() = default;
    };

}  // namespace IO

#endif  // INPUTMANAGER_H
