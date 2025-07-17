//
// Created by Aphile on 14.07.2025.
//

#include "GameObject.h"

#include <stdexcept>

namespace Game {

    GameObject::GameObject(const unsigned int x, unsigned int y, const unsigned int width, const unsigned int height,
                           char symbol) {

        if (width == 0 || height == 0) {
            throw std::invalid_argument("Width and height must be greater than zero.");
        }

        // 32 ascii code = ' '
        // Nam takogo ne nado.
        if (symbol == 32) {
            throw std::invalid_argument("Symbol cannot be empty.");
        }

        _x = x;
        _y = y;
        _width = width;
        _height = height;
        _symbol = symbol;
    }

    void GameObject::SetPosition(unsigned int x, unsigned int y) {
        _x = x;
        _y = y;
    }

    void GameObject::SetSize(const unsigned int width, const unsigned int height) {
        if (width == 0 || height == 0) {
            throw std::invalid_argument("Width and height must be greater than zero.");
        }
        _width = width;
        _height = height;
    }

    unsigned int GameObject::GetX() const { return _x; }
    unsigned int GameObject::GetY() const { return _y; }
    unsigned int GameObject::GetWidth() const { return _width; }
    unsigned int GameObject::GetHeight() const { return _height; }
    char GameObject::GetSymbol() const { return _symbol; }

} // namespace Game
