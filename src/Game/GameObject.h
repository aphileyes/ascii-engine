//
// Created by Aphile on 14.07.2025.
//

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <string>

namespace Game {

    class GameObject {
    public:
        GameObject(unsigned int x, unsigned int y, unsigned int width, unsigned int height, char symbols);
        ~GameObject() {}

        void Update(unsigned int x, unsigned int y);

        void SetPosition(unsigned int x, unsigned int y);
        void SetSize(unsigned int width, unsigned int height);

        unsigned int GetX() const;
        unsigned int GetY() const;
        unsigned int GetWidth() const;
        unsigned int GetHeight() const;

    private:
        unsigned int _x;
        unsigned int _y;
        unsigned int _width;
        unsigned int _height;
        std::string _symbols;
    };

} // namespace Game

#endif // GAMEOBJECT_H
