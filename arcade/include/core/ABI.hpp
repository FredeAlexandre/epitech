/*
** EPITECH PROJECT, 2022
** arcade.hpp
** File description:
** The common layer of the Arcade project
*/

#include <string>
#include <list>
#include <memory>

#include "IGame.hpp"
#include "IGraphic.hpp"

#ifndef _ARCADE_ECS_ABI_
    #define _ARCADE_ECS_ABI_

extern "C" {
    arcade::IGame *getGame(void);
    void destroyGame(arcade::IGame *);
    arcade::IGraphic *getGraphic(void);
    void destroyGraphic(arcade::IGraphic *);
};

#endif
