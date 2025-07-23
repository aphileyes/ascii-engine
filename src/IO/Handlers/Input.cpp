//
// Created by Aphile on 18.07.2025.
//

#include "Input.h"

#include <Windows.h>
#include <numeric>

namespace IO {

    Input::Input() {
        _keys.resize(128);
        std::iota(_keys.begin(), _keys.end(), 0);
        _last_frame_input.resize(_keys.size(), false);
    }

    void Input::Update() {
        _input_events.clear();

        for (const auto& key_code: _keys) {
            const auto key_state = GetAsyncKeyState(key_code);

            bool is_pressed = (key_state & KEY_PRESSED_MASK) != 0;

            if (is_pressed && !_last_frame_input[key_code]) {
                _input_events.push_back({KEY_PRESSED, key_code});
            } else if (is_pressed && _last_frame_input[key_code]) {
                _input_events.push_back({KEY_HOLD, key_code});
            } else if (!is_pressed && _last_frame_input[key_code]) {
                _input_events.push_back({KEY_RELEASED, key_code});
            }
            _last_frame_input[key_code] = is_pressed;
        }
    }

    std::vector<InputEvent> Input::GetInputEvents() const { return _input_events; }

}  // namespace IO
