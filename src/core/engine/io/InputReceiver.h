//
// Created by Aphile on 30.07.2025.
//

#ifndef INPUT_H
#define INPUT_H
#include "IInput.h"

namespace IO {

    class InputReceiver : public IO::IInput {
    public:
        InputReceiver();
        void Update() override;
        std::vector<IO::InputEvent> GetInputEvents() const override;

    private:
        std::vector<IO::InputEvent> _current_frame_input_events;
        std::vector<IO::InputEvent> _last_frame_input_events;
    };

}  // namespace IO

#endif  //INPUT_H
