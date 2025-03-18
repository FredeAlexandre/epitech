/*
** EPITECH PROJECT, 2023
** SnakeParts
** File description:
** arcade
*/

#include "SnakeParts.hpp"

SnakeParts::SnakeParts(int coordX, int coordY, std::shared_ptr<SnakeParts> next, bool isHead)
{
    sprite = Helper::addComponent<arcade::components::SpriteSheetComponent>(*this);
    spriteComponent = Helper::addComponent<arcade::components::SpriteComponent>(*this);
    size = Helper::addComponent<arcade::components::SizeComponent>(*this);
    pos = Helper::addComponent<arcade::components::PositionComponent>(*this);
    _coords.push_back(coordY);
    _coords.push_front(coordX);
    _next = next;
    sprite->source = SPRITE_SOURCE "snakePart.png";
    if (isHead == true) sprite->source = SPRITE_SOURCE "Head.jpg";
    size->width = 30;
    size->height = 30;
    spriteComponent->width = 288;
    spriteComponent->height = 288;
    spriteComponent->x = 0;
    spriteComponent->y = 0;
    spriteComponent->color = arcade::enums::Color::Green;
    pos->rotation = 0;
    actualiseCoord();
}

SnakeParts::~SnakeParts()
{
}

std::list<int> SnakeParts::get_Coord()
{
    return _coords;
}

std::list<int> SnakeParts::prev_get_Coord()
{
    return _prevCoords;
}


void SnakeParts::checkRotationHead()
{
    if (_coords.front() > _prevCoords.front()) {
        pos->rotation = 0;
    }
    if (_coords.front() < _prevCoords.front()) {
        pos->rotation = 180;
    }
    if (_coords.back() > _prevCoords.back()) {
        pos->rotation = 90;
    }
    if (_coords.back() < _prevCoords.back()) {
        pos->rotation = 270;
    }
}

int SnakeParts::moveCoord(int x, int y)
{
    if (_next == nullptr) {
        _prevCoords = _coords;
        if (_coords.front() + x >= 50 || _coords.front() + x < 0) return -1;
        if (_coords.back() + y >= 22 || _coords.back() + y < 0) return -1;
        _coords.front() += x;
        _coords.back() += y;
        actualiseCoord();
        checkRotationHead();
        return 0;
    }
    if (_next->prev_get_Coord().front() != _coords.front() || _next->prev_get_Coord().back() != _coords.back()) {
        _prevCoords = _coords;
        _coords.front() = _next->prev_get_Coord().front();
        _coords.back() = _next->prev_get_Coord().back();
    }
    actualiseCoord();
    return 0;
}

void SnakeParts::actualiseCoord()
{
    pos->x = _coords.front() * 30 + 210;
    pos->y = _coords.back() * 30 + 210;
    pos->z = 0;
}
