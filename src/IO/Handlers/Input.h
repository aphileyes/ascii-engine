//
// Created by Aphile on 18.07.2025.
//

#ifndef WINDOWSINPUTHANDLER_H
#define WINDOWSINPUTHANDLER_H
#include <Windows.h>

#include "../IInput.h"

namespace IO {

    class Input final : public IInput {
    public:
        Input();
        void Update() override;
        std::vector<InputEvent> GetInputEvents() const override;

    private:
        std::vector<BYTE> _key_buffer;
        std::vector<InputEvent> _input_events;
    };

}  // namespace IO

#endif  // WINDOWSINPUTHANDLER_H
