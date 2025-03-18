/*
** EPITECH PROJECT, 2023
** SnakeEntity
** File description:
** arcade
*/

#include "SnakeEntity.hpp"

#include <iostream>

SnakeEntity::SnakeEntity()
{
    _direction = 6;
    _isAlive = true;
    _Parts.push_front(std::make_shared<SnakeParts>(25, 11, nullptr, true));
    _Parts.push_front(std::make_shared<SnakeParts>(24, 11, _Parts.front(), false));
    _Parts.push_front(std::make_shared<SnakeParts>(23, 11, _Parts.front(), false));
    _Parts.push_front(std::make_shared<SnakeParts>(22, 11, _Parts.front(), false));
    inputsComponent = Helper::addComponent<arcade::components::GetInputsComponent>(*this);
    taille = 1;
}

SnakeEntity::~SnakeEntity()
{
}


void SnakeEntity::checkCollision()
{
    int headX = _Parts.back()->get_Coord().front();
    int headY = _Parts.back()->get_Coord().back();
    std::list<std::shared_ptr<SnakeParts>>::iterator it;
    if (taille <= 2) return;
    std::shared_ptr<SnakeParts> Head = _Parts.back();
    _Parts.pop_back();
    for (it = _Parts.begin(); it != _Parts.end(); it++) {
        if (headX == (*it)->get_Coord().front() && headY == (*it)->get_Coord().back()) _isAlive = false;
    }
    _Parts.push_back(Head);
}

void SnakeEntity::checkDirection()
{
    arcade::enums::Input input;

    _spacePress = false;
    for (auto input : inputsComponent->inputs) {
        switch (input) {
            case arcade::enums::Input::Left:
                if (_direction != 6)
                    _direction = 4;
                break;
            case arcade::enums::Input::Right:
                if (_direction != 4)
                    _direction = 6;
                break;
            case arcade::enums::Input::Up:
                if (_direction != 2)
                    _direction = 8;
                break;
            case arcade::enums::Input::Down:
                if (_direction != 8)
                    _direction = 2;
                break;
            case arcade::enums::Input::Space:
                _spacePress = true;
                break;
            default:
                break;
        }
    }
}

bool SnakeEntity::spacePress()
{
    return _spacePress;
}

void SnakeEntity::move()
{
    std::list<std::shared_ptr<SnakeParts>>::reverse_iterator it;
    int difX = 0;
    int difY = 0;

    switch (_direction) {
        case 2:
            difY = 1;
            break;
        case 4:
            difX = -1;
            break;
        case 6:
            difX = 1;
            break;
        case 8:
            difY = -1;
            break;
        default:
            break;
    }
    for (it = _Parts.rbegin(); it != _Parts.rend(); it++) {
        if ((*it)->moveCoord(difX, difY) == -1) {
            _isAlive = false;
            return;
        }
        (*it)->actualiseCoord();
    }
}

int SnakeEntity::checkEatApple(int coordAppleX, int coordAppleY, std::list<std::shared_ptr<arcade::ecs::IEntity>> &entities)
{
    int headX = _Parts.back()->get_Coord().front();
    int headY = _Parts.back()->get_Coord().back();

    int queueX = _Parts.front()->get_Coord().front();
    int queueY = _Parts.front()->get_Coord().back();

    if (headX == coordAppleX && headY == coordAppleY) {
        _Parts.push_front(std::make_shared<SnakeParts>(queueX, queueY, _Parts.front(), false));
        entities.push_front(_Parts.front());
        taille++;
        return 1;
    }
    return 0;
}

bool SnakeEntity::isAlive()
{
    return _isAlive;
}

std::list<std::shared_ptr<SnakeParts>> &SnakeEntity::getEntities()
{
    return _Parts;
}

int SnakeEntity::getScore()
{
    return taille - 1;
}