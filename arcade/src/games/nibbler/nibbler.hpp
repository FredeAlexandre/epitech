/*
** EPITECH PROJECT, 2023
** nibbler
** File description:
** arcade
*/

#ifndef _nibbler_
#define _nibbler_

#include "arcade.hpp"
#include <list>
#include "NibblerEntity.hpp"
#include "BasicEntity.hpp"
#include <iostream>
#include "Level.hpp"

class GameNibbler : public arcade::IGame{
    public:
        GameNibbler();
        ~GameNibbler();
        std::list<std::shared_ptr<arcade::ecs::IEntity>> init();
        void update(std::list<std::shared_ptr<arcade::ecs::IEntity>> &entities);
        void exit(std::list<std::shared_ptr<arcade::ecs::IEntity>> &entities);
        arcade::WindowSize getWindowSize() const override { return {1920, 1080};}
        bool checkAllApples();
        void EatApple(std::list<std::shared_ptr<arcade::ecs::IEntity>> &entities);
    private:
        std::shared_ptr<NibblerEntity> nibbler;
        std::list<std::shared_ptr<arcade::ecs::IEntity>> _entities;
        std::shared_ptr<arcade::components::TextComponent> textSprite;
        std::shared_ptr<arcade::components::ClockComponent> clockComponent;
        std::shared_ptr<arcade::components::ScoreComponent> scoreComponent;
        std::shared_ptr<arcade::components::EndComponent> endComponent;
        bool _isAlive = true;
        int score;
        int last_time = 0;
};

#endif /* !_nibbler_ */
