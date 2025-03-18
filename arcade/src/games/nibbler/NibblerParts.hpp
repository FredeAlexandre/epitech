/*
** EPITECH PROJECT, 2023
** NibblerParts
** File description:
** arcade
*/

#ifndef _nibblerPART_
#define _nibblerPART_

#include "arcade.hpp"

#define SPRITE_SOURCE "./sprites/nibbler/"

class NibblerParts : public arcade::ecs::AEntity {
    public:
        NibblerParts(int coordX, int coordY, std::shared_ptr<NibblerParts> next, bool isHead);
        ~NibblerParts();

        inline std::string getId(void) const override { return "nibbler_parts"; };
        std::list<int> get_Coord();
        int moveCoord(int x, int y);
        std::list<int> prev_get_Coord();
        void actualiseCoord();
        void checkRotationHead();
    protected:
        std::shared_ptr<NibblerParts> _next;
        std::list<int> _coords;
        std::list<int> _prevCoords;
        std::shared_ptr<arcade::components::PositionComponent> pos;
        std::shared_ptr<arcade::components::SpriteSheetComponent> sprite;
        std::shared_ptr<arcade::components::SizeComponent> size;
        std::shared_ptr<arcade::components::SpriteComponent> spriteComponent;
    private:
};

#endif /* !_nibblerPART_ */
