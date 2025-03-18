/*
** EPITECH PROJECT, 2023
** snake
** File description:
** arcade
*/
#include "../src/games/snake/snake.hpp"
#include "../src/graphicals/sdl2/sdl2.hpp"
#include <unistd.h>

int main(void)
{
    arcade::IGame *snake = new GameSnake();
    arcade::IGraphic *sdl2 = new SDL2();
    std::list<std::shared_ptr<arcade::ecs::IEntity>> listEntity;
    arcade::GraphicInit *graph = new arcade::GraphicInit();

    listEntity = snake->init();
    graph->width = snake->getWindowSize().width;
    graph->height = snake->getWindowSize().height;
    sdl2->init(*graph);
    while (1) {
        snake->update(listEntity);
        sdl2->update(listEntity);
        sleep(1);
    }
    return 0;
}