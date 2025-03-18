/*
** EPITECH PROJECT, 2023
** B-OOP-400-TLS-4-1-arcade-alexandre.frede
** File description:
** WallEntity
*/

#include "WallEntity.hpp"

WallEntity::WallEntity(float x, float y)
{
    auto pos = Helper::addComponent<arcade::components::PositionComponent>(*this);
    auto sprite = Helper::addComponent<arcade::components::SpriteComponent>(*this);
    auto spriteSheet = Helper::addComponent<arcade::components::SpriteSheetComponent>(*this);
    auto size = Helper::addComponent<arcade::components::SizeComponent>(*this);

    this->Id = "wall";
    pos.get()->x = x;
    pos.get()->y = y;
    pos.get()->z = 0;
    pos.get()->rotation = 0;
    spriteSheet.get()->source = "./sprites/nibbler/BasicWallSprite.png";
    sprite.get()->color = arcade::enums::Red;
    sprite.get()->height = 32;
    sprite.get()->width = 32;
    sprite.get()->x = 0;
    sprite.get()->y = 0;
    size.get()->height = 30; //to define
    size.get()->width = 30; //to define
}

WallEntity::~WallEntity()
{
}
