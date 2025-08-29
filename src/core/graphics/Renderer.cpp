//
// Created by Aphile on 17.07.2025.
//

#include "Renderer.h"

#include <Rend.h>

#include <algorithm>
#include <iostream>

#include "../../ecs/component/Position.h"
#include "../../ecs/component/Sprite.h"

namespace Graphics {

    Renderer::Renderer(int width, int height) {
        if (width <= 0 || height <= 0) {
            throw std::invalid_argument("Width and height must be greater than 0.");
        }

        width_ = width;
        height_ = height;

        front_buffer_.resize(width, std::vector(height, ' '));
        back_buffer_.resize(width, std::vector(height, '.'));
    }

    void Renderer::RenderFrame() {
        for (int y = start_render_from_row_; y < GetHeight(); ++y) {
            bool is_line_changed = false;
            std::string scanline;
            for (int x = 0; x < GetWidth(); ++x) {
                if (front_buffer_[x][y] != back_buffer_[x][y]) {
                    scanline += back_buffer_[x][y];
                    front_buffer_[x][y] = back_buffer_[x][y];
                    is_line_changed = true;
                } else {
                    scanline += front_buffer_[x][y];
                }
            }

            if (is_line_changed) {
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {0, static_cast<short>(y)});
                std::cout << scanline;
            }
        }
        ResetFrame();
    }

    void Renderer::ResetFrame() {
        for (auto& row : back_buffer_) {
            std::ranges::fill(row.begin(), row.end(), '.');
        }
    }

    void Renderer::DrawObject(const Component::Position& position, const Component::Size size, const Component::Sprite& sprite) {
        char symbol = sprite.symbol;

        int object_x = position.x;
        int object_y = position.y;

        int object_width = size.width;
        int object_height = size.height;

        int object_right = position.x + size.width;
        int object_bottom = position.y + size.height;

        int x_clamp = std::clamp<int>(object_x, 0, GetWidth());
        int y_clamp = std::clamp<int>(object_y, 0, GetHeight());

        int x_object_right_clamp = std::clamp<int>(object_right, 0, GetWidth());
        int y_object_bottom_clamp = std::clamp<int>(object_bottom, 0, GetHeight());

        for (int x = x_clamp; x < x_object_right_clamp; ++x) {
            for (int y = y_clamp; y < y_object_bottom_clamp; ++y) {
                back_buffer_[x][y] = symbol;
            }
        }
    }

    /* -------------------- GETTERS -------------------- */

    int Renderer::GetWidth() const {
        return width_;
    }

    int Renderer::GetHeight() const {
        return height_;
    }

    /* -------------------- SETTERS -------------------- */
}  // namespace Graphics
