/*
** EPITECH PROJECT, 2023
** B-OOP-400-TLS-4-1-arcade-alexandre.frede
** File description:
** level
*/

#ifndef LEVEL_HPP_
#define LEVEL_HPP_

#include "arcade.hpp"
#include "WallEntity.hpp"
#include "BasicEntity.hpp"


#define SPRITE_SOURCE "./sprites/nibbler/"

class Level {
    public:
        Level();
        Level(float x, float y, float scale);
        ~Level();
        void MakeLayout();
        void spawnMap(std::list<std::shared_ptr<arcade::ecs::IEntity>> &entities);
        std::shared_ptr<WallEntity> spawnWall(int x, int y);
        std::map<std::pair<int, int>, std::shared_ptr<arcade::ecs::IEntity>> getWalls();
        bool isWall(int, int);
        void AppleMaker(float x, float y);
    private:
        std::map<std::pair<int, int>, std::shared_ptr<arcade::ecs::IEntity>> _wallCollection;
        std::list<std::shared_ptr<BasicEntity>> _AppleCollection;
        float _gridX;
        float _gridY;
        float _gridScale;
};

#endif /* !LEVEL_HPP_ */
