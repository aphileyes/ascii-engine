//
// Created by Aphile on 14.07.2025.
//

#include "RenderException.h"

namespace Exceptions {
    RenderException::RenderException(const std::string &exception_str) {
        this->_message = exception_str;
    }

    const char* RenderException::what() const noexcept {
        return this->_message.c_str();
    }


} // Exceptions