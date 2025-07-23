//
// Created by Aphile on 18.07.2025.
//

#ifndef INPUT_H
#define INPUT_H
#include <Windows.h>
#include <map>

#include "../IInput.h"

namespace IO {

    class Input final : public IInput {
    public:
        Input();
        void Update() override;

        [[nodiscard]]
        std::vector<InputEvent> GetInputEvents() const override;

    private:
        std::vector<BYTE> _keys;
        std::vector<bool> _last_frame_input;

        std::vector<InputEvent> _input_events;
    };

}  // namespace IO

#endif  // INPUT_H
