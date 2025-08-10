//
// Created by Aphile on 30.07.2025.
//

#include "InputReceiver.h"

#include <Windows.h>

#include <numeric>
namespace IO {

    InputReceiver::InputReceiver() {
        _current_frame_input_events.resize(256);
        _last_frame_input_events.resize(256);

        for (int key = 0; key < _current_frame_input_events.size(); ++key) {
            _current_frame_input_events[key] = {IO::KEY_RELEASED, key};
            _last_frame_input_events[key] = {IO::KEY_RELEASED, key};
        }
    }

    void InputReceiver::Update() {
        _current_frame_input_events.clear();

        for (int key = 0; key < 256; ++key) {
            auto key_state = GetAsyncKeyState(key);
            auto is_key_pressed_in_current_frame = key_state & IO::KEY_PRESSED_MASK;

            if (is_key_pressed_in_current_frame && _last_frame_input_events[key].type != IO::KEY_PRESSED) {
                _current_frame_input_events.push_back({IO::KEY_PRESSED, key});
            } else if (is_key_pressed_in_current_frame && _last_frame_input_events[key].type == IO::KEY_PRESSED) {
                _current_frame_input_events.push_back({IO::KEY_HOLD, key});
            } else if (!is_key_pressed_in_current_frame && _last_frame_input_events[key].type == IO::KEY_PRESSED) {
                _current_frame_input_events.push_back({IO::KEY_RELEASED, key});
            }
            _last_frame_input_events[key].type = is_key_pressed_in_current_frame ? IO::KEY_PRESSED : IO::KEY_RELEASED;
        }
    }

    std::vector<IO::InputEvent> InputReceiver::GetInputEvents() const {
        return _current_frame_input_events;
    }

}  // namespace IO