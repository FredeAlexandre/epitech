/*
** EPITECH PROJECT, 2022
** arcade.hpp
** File description:
** The common layer of the Arcade project
*/

#include <iostream>

#include "core.hpp"

int main(int ac, char **av)
{
    try
    {
        Core core;
        core.loop();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    return 0;
}
