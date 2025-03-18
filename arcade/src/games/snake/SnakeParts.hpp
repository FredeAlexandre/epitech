/*
** EPITECH PROJECT, 2023
** snakeParts
** File description:
** arcade
*/

#ifndef _SNAKEPART_
#define _SNAKEPART_

#include "arcade.hpp"

#define SPRITE_SOURCE "./sprites/snake/"

class SnakeParts : public arcade::ecs::AEntity {
    public:
        SnakeParts(int coordX, int coordY, std::shared_ptr<SnakeParts> next, bool isHead);
        ~SnakeParts();

        inline std::string getId(void) const override { return "snake_parts"; };
        std::list<int> get_Coord();
        int moveCoord(int x, int y);
        std::list<int> prev_get_Coord();
        void actualiseCoord();
        void checkRotationHead();
    protected:
        std::shared_ptr<SnakeParts> _next;
        std::list<int> _coords;
        std::list<int> _prevCoords;
        std::shared_ptr<arcade::components::PositionComponent> pos;
        std::shared_ptr<arcade::components::SpriteSheetComponent> sprite;
        std::shared_ptr<arcade::components::SizeComponent> size;
        std::shared_ptr<arcade::components::SpriteComponent> spriteComponent;
    private:
};

#endif /* !_SNAKEPART_ */
