/*
** EPITECH PROJECT, 2023
** B-OOP-400-TLS-4-1-arcade-alexandre.frede
** File description:
** level
*/

#include "Level.hpp"

Level::Level(): _gridX(0), _gridY(0)
{
    MakeLayout();
    _gridScale = 100;
}

Level::Level(float x, float y, float scale): _gridX(x), _gridY(y), _gridScale(scale)
{
}

Level::~Level()
{
}

void Level::AppleMaker(float x, float y)
{
    std::shared_ptr<BasicEntity> Apple = std::make_shared<BasicEntity>("apple");
    auto posApple = Helper::addComponent<arcade::components::PositionComponent>(*Apple);
    auto spriteApple = Helper::addComponent<arcade::components::SpriteSheetComponent>(*Apple);
    auto sizeApple = Helper::addComponent<arcade::components::SizeComponent>(*Apple);
    auto spriteComponentApple = Helper::addComponent<arcade::components::SpriteComponent>(*Apple);

    sizeApple->width = 30;
    sizeApple->height = 30;
    spriteApple->source = SPRITE_SOURCE "apple.png";
    posApple.get()->x = x;
    posApple.get()->y = y;
    posApple.get()->z = 0;
    posApple.get()->rotation = 0;
    spriteComponentApple->width = 600;
    spriteComponentApple->height = 600;
    spriteComponentApple->x = 0;
    spriteComponentApple->y = 0;
    spriteComponentApple->color = arcade::enums::Color::Red;
    _AppleCollection.push_back(Apple);
}

//grid is 12 by 12 cells of _gridScale
//only one HARD CODED map for now
//declare the level in a list to transfer over at the global entities list
void Level::MakeLayout()
{
    std::pair<int,int> handler = std::make_pair(0, 0);
    auto wallee = std::make_shared<WallEntity>(3, 4);

    //fill top line
    for (int  i = 0; i < 12; i++) {
        handler.second = i;
        _wallCollection[handler] = std::static_pointer_cast<arcade::ecs::IEntity>(std::make_shared<WallEntity>(_gridX + handler.first * _gridScale,
            _gridY + handler.second * _gridScale));
    }
    //fill left column
    handler.second = 0;
    for (int j = 1; j < 12; j ++) {
        handler.first = j;
        _wallCollection[handler] = std::static_pointer_cast<arcade::ecs::IEntity>(std::make_shared<WallEntity>(_gridX + handler.first * _gridScale,
            _gridY + handler.second * _gridScale));
    }
    //fill right column
    handler.second = 11;
    for (int j = 1; j < 12; j++) {
        handler.first = j;
        _wallCollection[handler] = std::static_pointer_cast<arcade::ecs::IEntity>(std::make_shared<WallEntity>(_gridX + handler.first * _gridScale,
            _gridY + handler.second * _gridScale));
    }
    //fill bottom line
    handler.first = 11;
    for (int i = 1; i < 11; i++) {
        handler.second = i;
        _wallCollection[handler] = std::static_pointer_cast<arcade::ecs::IEntity>(std::make_shared<WallEntity>(_gridX + handler.first * _gridScale,
            _gridY + handler.second * _gridScale));
    }
    //apples
    AppleMaker(_gridX + _gridScale, _gridY + _gridScale);
    AppleMaker(_gridX + _gridScale * 3, _gridY + _gridScale);
    AppleMaker(_gridX + _gridScale * 6, _gridY + _gridScale);
    AppleMaker(_gridX + _gridScale * 8, _gridY + _gridScale);
    AppleMaker(_gridX + _gridScale * 10, _gridY + _gridScale * 2);
    AppleMaker(_gridX + _gridScale * 2, _gridY + _gridScale * 3);
    AppleMaker(_gridX + _gridScale * 5, _gridY + _gridScale * 3);
    AppleMaker(_gridX + _gridScale * 8, _gridY + _gridScale * 3);
    AppleMaker(_gridX + _gridScale * 1, _gridY + _gridScale * 5);
    AppleMaker(_gridX + _gridScale * 5, _gridY + _gridScale * 5);
    AppleMaker(_gridX + _gridScale * 7, _gridY + _gridScale * 5);
    AppleMaker(_gridX + _gridScale * 10, _gridY + _gridScale * 5);
    AppleMaker(_gridX + _gridScale * 1, _gridY + _gridScale * 7);
    AppleMaker(_gridX + _gridScale * 4, _gridY + _gridScale * 7);
    AppleMaker(_gridX + _gridScale * 6, _gridY + _gridScale * 7);
    AppleMaker(_gridX + _gridScale * 8, _gridY + _gridScale * 7);
    AppleMaker(_gridX + _gridScale * 3, _gridY + _gridScale * 8);
    AppleMaker(_gridX + _gridScale * 5, _gridY + _gridScale * 8);
    AppleMaker(_gridX + _gridScale * 8, _gridY + _gridScale * 8);
    AppleMaker(_gridX + _gridScale * 10, _gridY + _gridScale * 8);
    AppleMaker(_gridX + _gridScale * 1, _gridY + _gridScale * 10);
    AppleMaker(_gridX + _gridScale * 4, _gridY + _gridScale * 10);
    //add obstacles here
    handler.first = 4; handler.second = 1;
    _wallCollection[handler] = std::static_pointer_cast<arcade::ecs::IEntity>(std::make_shared<WallEntity>(_gridX + handler.first * _gridScale,_gridY + handler.second * _gridScale));
    handler.second = 2;
    for (int i = 2; i < 9; i += 2) {
        handler.first = i;
        _wallCollection[handler] = std::static_pointer_cast<arcade::ecs::IEntity>(std::make_shared<WallEntity>(_gridX + handler.first * _gridScale,_gridY + handler.second * _gridScale));
    }
    handler.first = 9;
    for (int j = 2; j < 10; j++) {
        handler.second = j;
        if (j == 5 || j == 8) continue;
        _wallCollection[handler] = std::static_pointer_cast<arcade::ecs::IEntity>(std::make_shared<WallEntity>(_gridX + handler.first * _gridScale,_gridY + handler.second * _gridScale));
    }
    handler.second = 4;
    for (int i = 2; i < 8; i++) {
        handler.first = i;
        _wallCollection[handler] = std::static_pointer_cast<arcade::ecs::IEntity>(std::make_shared<WallEntity>(_gridX + handler.first * _gridScale,_gridY + handler.second * _gridScale));
    }
    handler.first = 2;
    for (int j = 6; j < 10; j++) {
        handler.second = j;
        _wallCollection[handler] = std::static_pointer_cast<arcade::ecs::IEntity>(std::make_shared<WallEntity>(_gridX + handler.first * _gridScale,_gridY + handler.second * _gridScale));
    }
    handler.second = 6;
    for (int i = 4; i < 9; i ++) {
        handler.first = i;
        if (i == 7) continue;
        _wallCollection[handler] = std::static_pointer_cast<arcade::ecs::IEntity>(std::make_shared<WallEntity>(_gridX + handler.first * _gridScale,_gridY + handler.second * _gridScale));
    }
    handler.second = 9;
    for (int i = 3; i < 10; i+= 2) {
        handler.first = i;
        _wallCollection[handler] = std::static_pointer_cast<arcade::ecs::IEntity>(std::make_shared<WallEntity>(_gridX + handler.first * _gridScale,_gridY + handler.second * _gridScale));
    }
    handler.first = 7; handler.second = 8;
    _wallCollection[handler] = std::static_pointer_cast<arcade::ecs::IEntity>(std::make_shared<WallEntity>(_gridX + handler.first * _gridScale,_gridY + handler.second * _gridScale));
    handler.first = 5; handler.second = 10;
    _wallCollection[handler] = std::static_pointer_cast<arcade::ecs::IEntity>(std::make_shared<WallEntity>(_gridX + handler.first * _gridScale,_gridY + handler.second * _gridScale));

}

//puts all the walls as entities in the entities list for display
void Level::spawnMap(std::list<std::shared_ptr<arcade::ecs::IEntity>> &entities)
{
    std::pair<int, int> handler = std::make_pair<int, int>(0,0);
    std::shared_ptr<arcade::ecs::IEntity> currWall;

    for (int i = 0; i <= 11; i++) {
        for (int j = 0; j <= 11; j++) {
            handler.first = i;
            handler.second = j;
            if (_wallCollection[handler] != nullptr) {
                currWall = _wallCollection[handler];
                entities.push_front(currWall);
                if (LOGS)
                    std::cout << "wall: " << Helper::getComponent<arcade::components::PositionComponent>(*currWall).get()->x << ", " << Helper::getComponent<arcade::components::PositionComponent>(*currWall).get()->y << std::endl;
            }
        }
    }
    for (auto it = _AppleCollection.begin(); it != _AppleCollection.end(); ++it) {
        if (LOGS)
            std::cout << "apple added" << std::endl;
        entities.push_front(*it);
    }
}

bool Level::isWall(int x, int y)
{
    std::pair<int,int> couple = std::make_pair(x, y);
    
    if (_wallCollection[couple] == nullptr)
        return false; 
    return true;
}

std::map<std::pair<int, int>, std::shared_ptr<arcade::ecs::IEntity>> Level::getWalls()
{
    return _wallCollection;
}