//
// Created by Aphile on 14.07.2025.
//

#include "GameObject.h"

#include <stdexcept>

#include "../Graphics/Renders/ASCIIRender.h"
#include "boost/di.hpp"

namespace Game {

    GameObject::GameObject(Position position, Size size, char symbol) {
        if (position.x < 0 || position.y < 0) {
            throw std::invalid_argument("GameObject spawn position must be greater than less zero.");
        }

        _position = position;

        if (symbol == VK_SPACE) {
            throw std::invalid_argument("Symbol cannot be empty.");
        }

        _symbol = symbol;
        _size = size;
    }

    void GameObject::SetPosition(Position position) { _position = position; }

    void GameObject::SetSize(Size size) {
        if (size.width == 0 || size.height == 0) {
            throw std::invalid_argument("GameObject size cannot be empty.");
        }

        _size = size;
    }

    int GameObject::GetX() const { return _position.x; }
    int GameObject::GetY() const { return _position.y; }
    int GameObject::GetWidth() const { return _size.width; }
    int GameObject::GetHeight() const { return _size.height; }
    char GameObject::GetSymbol() const { return _symbol; }

}  // namespace Game
