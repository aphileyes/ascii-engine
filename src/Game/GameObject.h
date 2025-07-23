//
// Created by Aphile on 14.07.2025.
//

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

namespace Game {

    class GameObject {
    public:
        struct Position {
            int x;
            int y;
        };

        struct Size {
            int width;
            int height;
        };

        GameObject(const Position& position, const Size& size, char symbol);
        virtual ~GameObject() = default;

        virtual void Update(float delta_time) = 0;

        void SetPosition(Position position);
        void SetSize(Size size);

        [[nodiscard]]
        int GetX() const;

        [[nodiscard]]
        int GetY() const;

        [[nodiscard]]
        int GetWidth() const;

        [[nodiscard]]
        int GetHeight() const;

        [[nodiscard]]
        char GetSymbol() const;

    private:
        char _symbol;
        Size _size;
        Position _position;
    };

}  // namespace Game

#endif  // GAMEOBJECT_H
