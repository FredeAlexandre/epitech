/*
** EPITECH PROJECT, 2023
** Ncursearcade
** File description:
** _Ncurse_
*/

#ifndef _Ncurse_
#define _Ncurse_

#include "arcade.hpp"
#include <ncurses.h>
#include <curses.h>
#include <map>
#define FONT_SOURCE "../../Font/"

using KeyToInput = std::map<int, arcade::enums::Input>;

const KeyToInput getKeyToInput = {
    {'a', arcade::enums::A},
    {'b', arcade::enums::B},
    {'c', arcade::enums::C},
    {'d', arcade::enums::D},
    {'e', arcade::enums::E},
    {'f', arcade::enums::F},
    {'g', arcade::enums::G},
    {'h', arcade::enums::H},
    {'i', arcade::enums::I},
    {'j', arcade::enums::J},
    {'k', arcade::enums::K},
    {'l', arcade::enums::L},
    {'m', arcade::enums::M},
    {'n', arcade::enums::N},
    {'o', arcade::enums::O},
    {'p', arcade::enums::P},
    {'q', arcade::enums::Q},
    {'r', arcade::enums::R},
    {'s', arcade::enums::S},
    {'t', arcade::enums::T},
    {'u', arcade::enums::U},
    {'v', arcade::enums::V},
    {'w', arcade::enums::W},
    {'x', arcade::enums::X},
    {'y', arcade::enums::Y},
    {'z', arcade::enums::Z},
    {'0', arcade::enums::Num0},
    {'1', arcade::enums::Num1},
    {'2', arcade::enums::Num2},
    {'3', arcade::enums::Num3},
    {'4', arcade::enums::Num4},
    {'5', arcade::enums::Num5},
    {'6', arcade::enums::Num6},
    {'7', arcade::enums::Num7},
    {'8', arcade::enums::Num8},
    {'9', arcade::enums::Num9},
    {' ', arcade::enums::Space},
    {10, arcade::enums::Return},
    {27, arcade::enums::Escape},
    {KEY_F(1), arcade::enums::F1},
    {KEY_F(2), arcade::enums::F2},
    {KEY_F(3), arcade::enums::F3},
    {KEY_F(4), arcade::enums::F4},
    {259, arcade::enums::Up},
    {258, arcade::enums::Down},
    {260, arcade::enums::Left},
    {261, arcade::enums::Right},
};

class Ncurse : public arcade::IGraphic {
    public:
        Ncurse();
        ~Ncurse();
        void init(arcade::GraphicInit value);
        void update(std::list<std::shared_ptr<arcade::ecs::IEntity>> &entities);
        void printRectangle(int x, int y, int height, int width, int color);
        void DrawEntity(std::shared_ptr<arcade::ecs::IEntity> entity);
        void DrawText(std::shared_ptr<arcade::components::TextComponent> &component);
        void DrawSprite(std::shared_ptr<arcade::components::SpriteComponent> &sprite, std::shared_ptr<arcade::components::SizeComponent> &size, std::shared_ptr<arcade::components::PositionComponent> &position);
        void giveInputs(std::list<std::shared_ptr<arcade::ecs::IEntity>> &entities, std::list<arcade::enums::Input> &keys);
    protected:
        int pixelPerColumns;
        int pixelPerLines;
        int rows = 0;
        int cols = 0;
        arcade::GraphicInit _value = {0, 0};
};
#endif /* !_Ncurse_ */
