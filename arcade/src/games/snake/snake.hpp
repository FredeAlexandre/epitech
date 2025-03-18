/*
** EPITECH PROJECT, 2023
** snake
** File description:
** arcade
*/

#ifndef _SNAKE_
#define _SNAKE_

#include "arcade.hpp"
#include <list>
#include "SnakeEntity.hpp"
#include "BasicEntity.hpp"

class GameSnake : public arcade::IGame{
    public:
        GameSnake();
        ~GameSnake();
        std::list<std::shared_ptr<arcade::ecs::IEntity>> init();
        void update(std::list<std::shared_ptr<arcade::ecs::IEntity>> &entities);
        void randomiseApple();
        void exit(std::list<std::shared_ptr<arcade::ecs::IEntity>> &entities);
        arcade::WindowSize getWindowSize() const override { return {1920, 1080};}
    private:
        std::shared_ptr<SnakeEntity> snake;
        std::list<std::shared_ptr<arcade::ecs::IEntity>> entities;
        std::shared_ptr<BasicEntity> AppleSprite;
        std::shared_ptr<arcade::components::PositionComponent> posAppleSprite;
        std::shared_ptr<arcade::components::TextComponent> textSprite;
        std::shared_ptr<arcade::components::ClockComponent> clockComponent;
        std::shared_ptr<arcade::components::ScoreComponent> scoreComponent;
        std::shared_ptr<arcade::components::EndComponent> endComponent;
        bool _isAlive = true;
        int last_time = 0;
};

#endif /* !_SNAKE_ */
