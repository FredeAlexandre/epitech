/*
** EPITECH PROJECT, 2022
** arcade.hpp
** File description:
** The common layer of the Arcade project
*/

#include "arcade.hpp"

class Pacman : public arcade::IGame
{
    public:
        std::list<std::shared_ptr<arcade::ecs::IEntity>> init(void) override
        {
            std::list<std::shared_ptr<arcade::ecs::IEntity>> Empty;
            return Empty;
        }

        void update(std::list<std::shared_ptr<arcade::ecs::IEntity>> &entities) override
        {
            (void)entities;
        }
        
        inline arcade::WindowSize getWindowSize(void) const { return {1920, 1080}; }
};

extern "C" {
    arcade::IGame *getGame(void)
    {
        return new Pacman();
    }

    void destroyGame(arcade::IGame *game)
    {
        delete game;
    }
};