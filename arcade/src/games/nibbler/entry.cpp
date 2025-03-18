/*
** EPITECH PROJECT, 2022
** arcade.hpp
** File description:
** The common layer of the Arcade project
*/

#include "nibbler.hpp"

extern "C" {
    arcade::IGame *getGame(void)
    {
        return new GameNibbler();
    }

    void destroyGame(arcade::IGame *game)
    {
        delete game;
    }
};