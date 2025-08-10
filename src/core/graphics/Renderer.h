//
// Created by Aphile on 17.07.2025.
//

#ifndef ASCIIRENDER_H
#define ASCIIRENDER_H
#include <vector>

#include "IRender.h"

namespace Graphics {

    class Renderer final : public IRender {
    public:
        Renderer(int width, int height);

        void DrawObject(const Component::Position& position, const Component::Size size,
                        const Component::Sprite& sprite) override;
        void ResetFrame() override;
        void RenderFrame() override;

        void SetStartRenderFromRow(int row_number);
        int GetStartRenderFromRow();

        [[nodiscard]] int GetWidth() const override;
        [[nodiscard]] int GetHeight() const override;

    private:
        int width_;
        int height_;

        int start_render_from_row_;

        std::vector<std::vector<char>> front_buffer_;
        std::vector<std::vector<char>> back_buffer_;
    };

}  // namespace Graphics

#endif  // ASCIIRENDER_H
