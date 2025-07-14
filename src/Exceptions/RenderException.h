//
// Created by Aphile on 14.07.2025.
//

#ifndef RENDEREXCEPTION_H
#define RENDEREXCEPTION_H
#include <exception>
#include <string>

namespace Exceptions {
    class RenderException final : public std::exception {
    public:
        // explicit RenderException(const std::string& exception_str);
        RenderException(const std::string& exception_str);
        [[nodiscard]] const char* what() const noexcept override;

    private:
        std::string _message;
    };
    ;
}; // namespace Exceptions

#endif // RENDEREXCEPTION_H
