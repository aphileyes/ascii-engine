//
// Created by Aphile on 18.07.2025.
//

#include "Input.h"

#include <Windows.h>
#include <numeric>

namespace IO {

    Input::Input() {
        _key_buffer.resize(128);
        std::iota(_key_buffer.begin(), _key_buffer.end(), 0);
    }

    void Input::Update() {
        _input_events.clear();

        for (const auto& key_code: _key_buffer) {
            if (GetAsyncKeyState(key_code)) {
                _input_events.push_back({KEY_PRESSED, key_code});
            }
        }

        // for (int i = 0; i < _key_buffer.size(); ++i) {
        //     _key_buffer.push_back(i);
        // }

        // BYTE keyboard_state[256];
        // if (GetKeyboardState(keyboard_state)) {
        //     for (int key = 0; key < 256; ++key) {
        //         if (GetAsyncKeyState(keyboard_state[key])) {
        //             _input_events.push_back({KEY_PRESSED, static_cast<char>(key)});
        //         }
        //     }
        // } else {
        //     throw std::runtime_error(std::format("Failed to get keyboard state. Last error: {}", GetLastError()));
        // }

        // if (GetKeyState('W') & 0x80) {
        //     _input_events.push_back({KEY_PRESSED, 'W'});
        // }
        //
        // if (GetKeyState('A') & 0x80) {
        //     _input_events.push_back({KEY_PRESSED, 'A'});
        // }
        //
        // if (GetKeyState('S') & 0x80) {
        //     _input_events.push_back({KEY_PRESSED, 'S'});
        // }
        //
        // if (GetKeyState('D') & 0x80) {
        //     _input_events.push_back({KEY_PRESSED, 'D'});
        // }
    }

    std::vector<InputEvent> Input::GetInputEvents() const { return _input_events; }

}  // namespace IO
