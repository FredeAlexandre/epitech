/*
** EPITECH PROJECT, 2023
** main
** File description:
** zappy_gui
*/

#include <iostream>
#include <string.h>
#include "Core.hpp"

static void displayHelp() {
    std::cout << "USAGE: ./zappy_gui -p port -h machine" << std::endl;
    std::cout << "\tport\tis the port number" << std::endl;
    std::cout << "\tmachine\tis the name of the machine; localhost by default" << std::endl;
}

static int checkArg(int argc) {
    if (argc < 3) {
        std::cerr << "Invalid argument, launch ./zappy_gui --help" << std::endl;
        return 84;
    }
    return 0;
}

int main(int argc, char **argv)
{
    if (argc > 1 && strcmp(argv[1], "--help") == 0) {
        displayHelp();
        return 0;
    }
    if (checkArg(argc) == 84)
        return 84;
    try {
        Core core(argc, argv);
        core.initialize();
        core.loop();
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    return 0;
}