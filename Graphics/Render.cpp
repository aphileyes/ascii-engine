//
// Created by Aphile on 14.07.2025.
//

#include "Render.h"

#include <string>

#include "../Exceptions/RenderException.h"

namespace Graphics {
    Render::Render(const int &width, const int &height, const double &fps)
    : _width(width), _height(height), _framesPerSecond(fps) {

    }

    void Render::Clear() {
        for (auto &row : _backFrameBuffer) {
            fill(row.begin(), row.end(), ' ');
        }
    }

    void Render::Draw(const int x, const int y, const char symbol = '.') {
        // if (x > _width || y > _height || y < 0 || x < 0) {
        if (0 < x < _width || 0 < y < _height) {
            throw Exceptions::RenderException("I can draw within 0 <-> " + std::to_string(_width) + "x & 0 <-> " + std::to_string(_height) + "y coordinates. Your coord trying to draw out of range.");
        }

        for (int iteratorX = 0; iteratorX < _width; iteratorX++) {
            for (int iteratorY = 0; iteratorY < _height; iteratorY++) {
                _backFrameBuffer[iteratorX][iteratorY] = symbol;
            }
        }
    }


} // Graphics