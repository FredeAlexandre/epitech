/*
** EPITECH PROJECT, 2023
** NibblerEntity
** File description:
** arcade
*/

#include "NibblerEntity.hpp"

NibblerEntity::NibblerEntity()
{
    _direction = 6;
    _isAlive = true;
    _Parts.push_front(std::make_shared<NibblerParts>(25, 15, nullptr, true));
    _Parts.push_front(std::make_shared<NibblerParts>(24, 15, _Parts.front(), false));
    _Parts.push_front(std::make_shared<NibblerParts>(23, 15, _Parts.front(), false));
    _Parts.push_front(std::make_shared<NibblerParts>(22, 15, _Parts.front(), false));
    inputsComponent = Helper::addComponent<arcade::components::GetInputsComponent>(*this);
    taille = 1;
}

NibblerEntity::~NibblerEntity()
{
}

void NibblerEntity::checkCollision()
{
    int headX = _Parts.back()->get_Coord().front();
    int headY = _Parts.back()->get_Coord().back();
    std::list<std::shared_ptr<NibblerParts>>::iterator it;
    if (taille <= 2) return;
    std::shared_ptr<NibblerParts> Head = _Parts.back();
    _Parts.pop_back();
    for (it = _Parts.begin(); it != _Parts.end(); it++) {
        if (headX == (*it)->get_Coord().front() && headY == (*it)->get_Coord().back()) _isAlive = false;
    }
    _Parts.push_back(Head);
}

void NibblerEntity::checkDirection()
{
    arcade::enums::Input input;

    while (inputsComponent->inputs.size() != 0) {
        input = inputsComponent->inputs.front();
        inputsComponent->inputs.pop_front();
        switch(input) {
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
            default:
                break;
        }
    }
}

//this function will check the head's surroundings and automatically reorient the player
//if they are in a corner
//returns true if the snake should not move
//returns false otherwise
bool NibblerEntity::checkSurroundings(std::list<std::shared_ptr<arcade::ecs::IEntity>> &entities)
{
    bool top = false, right = false, left = false, bottom = false;
    float x = 0, y = 0, cmpx = 0, cmpy = 0;
    auto snakePosComp =  Helper::getComponent<arcade::components::PositionComponent>(*_Parts.back().get());
    std::shared_ptr<arcade::components::PositionComponent> PosComp = nullptr;

    x = snakePosComp.get()->x;
    y = snakePosComp.get()->y;
    for (auto it = entities.begin(); it != entities.end(); ++it) {
        if (it->get()->getId() != "wall")
            continue;
        PosComp = Helper::getComponent<arcade::components::PositionComponent>(*it->get());
        if (PosComp == nullptr)
            continue;
        cmpx = PosComp.get()->x;
        cmpy = PosComp.get()->y;
        if (x + 30 == cmpx && y == cmpy)
            right = true;
        if (x - 30 == cmpx && y == cmpy)
            left = true;
        if (x == cmpx && y + 30 == cmpy)
            bottom = true;
        if (x == cmpx && y - 30 == cmpy)
            top = true;
    }

    //facing right
    if (_direction == 6 && right == true) {
        if (!top && !bottom) return true;
        if (top) _direction = 2;
        else if (bottom) _direction = 8;
    }
    //facing left
    else if (_direction == 4 && left == true) {
        if (!top && !bottom) return true;
        if (top) _direction = 2;
        else if (bottom) _direction = 8;
    }
    //facing bottom
    else if (_direction == 2 && bottom == true) {
        if (!left && !right) return true;
        if (left) _direction = 6;
        else if (right) _direction = 4;
    }
    //facing top
    else if (_direction == 8 && top == true) {
        if (!left && !right) return true;
        if (left) _direction = 6;
        else if (right) _direction = 4;
    }
    return false;
}

std::list<std::shared_ptr<NibblerParts>> NibblerEntity::getParts()
{
    return _Parts;
}

int NibblerEntity::AddPart(std::list<std::shared_ptr<arcade::ecs::IEntity>> &entities)
{
    int queueX = _Parts.front()->get_Coord().front();
    int queueY = _Parts.front()->get_Coord().back();

    _Parts.push_front(std::make_shared<NibblerParts>(queueX, queueY, _Parts.front(), false));
        entities.push_front(_Parts.front());
        taille++;
        return 1;
}

void NibblerEntity::move()
{
    std::list<std::shared_ptr<NibblerParts>>::reverse_iterator it;
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

int NibblerEntity::checkEatApple(int coordAppleX, int coordAppleY, std::list<std::shared_ptr<arcade::ecs::IEntity>> &entities)
{
    int headX = _Parts.back()->get_Coord().front();
    int headY = _Parts.back()->get_Coord().back();

    int queueX = _Parts.front()->get_Coord().front();
    int queueY = _Parts.front()->get_Coord().back();

    if (headX == coordAppleX && headY == coordAppleY) {
        _Parts.push_front(std::make_shared<NibblerParts>(queueX, queueY, _Parts.front(), false));
        entities.push_front(_Parts.front());
        taille++;
        return 1;
    }
    return 0;
}

bool NibblerEntity::isAlive()
{
    return _isAlive;
}

std::list<std::shared_ptr<NibblerParts>> &NibblerEntity::getEntities()
{
    return _Parts;
}

int NibblerEntity::getScore()
{
    return taille - 1;
}

bool NibblerEntity::spacePress()
{
    return _spacePress;
}
