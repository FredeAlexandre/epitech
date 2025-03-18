/*
** EPITECH PROJECT, 2022
** arcade.hpp
** File description:
** The common layer of the Arcade project
*/

#include <iostream>
#include <dlfcn.h>
#include "../../games/snake/snake.hpp"
#include "ncurse.hpp"
#include <thread>
#include <unistd.h>
#include <chrono>

class ExitEntity : public arcade::ecs::AEntity
{
    public:
        ExitEntity() { addComponent("exit"); }

        inline std::string getId(void) const override { return "exit"; };
        bool isExited(void) {
            return Helper::getComponent<arcade::components::ExitComponent>(*this)->exit;
        }
};

void test(arcade::IGame *snake, arcade::IGraphic *sdl2)
{
    std::list<std::shared_ptr<arcade::ecs::IEntity>> listEntity;
    arcade::GraphicInit *graph = new arcade::GraphicInit();
    std::shared_ptr<ExitEntity> exiter = std::make_shared<ExitEntity>();

    auto lastUpdate = std::chrono::system_clock::now().time_since_epoch();

    listEntity = snake->init();
    graph->width = snake->getWindowSize().width;
    graph->height = snake->getWindowSize().height;
    sdl2->init(*graph);
    listEntity.push_back(exiter);
    while (!exiter->isExited()) {
        auto duration = std::chrono::system_clock::now().time_since_epoch() - lastUpdate;
        lastUpdate = std::chrono::system_clock::now().time_since_epoch();
        for (auto entity : listEntity) {
            auto clock = Helper::getComponent<arcade::components::ClockComponent>(*entity);
            if (clock == nullptr) continue;
            clock->timestamp = std::chrono::duration_cast<std::chrono::seconds>(lastUpdate).count();
            clock->duration = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
        }
        snake->update(listEntity);
        sdl2->update(listEntity);

        std::this_thread::sleep_for(std::chrono::milliseconds(1000/30) - std::chrono::duration_cast<std::chrono::milliseconds>(duration));
    }
}

int main(int ac, char **av)
{
    std::cout << "SDL2 started" << std::endl;
    void *snake_handler = dlopen("../../lib/arcade_snake.so", RTLD_LAZY);
    void *sdl2_handler = dlopen("../../lib/arcade_ncurses.so", RTLD_LAZY);
    arcade::IGame* (*getGame)(void) = (arcade::IGame *(*)(void))dlsym(snake_handler, "getGame");
    arcade::IGraphic* (*getGraphic)(void) = (arcade::IGraphic *(*)(void))dlsym(sdl2_handler, "getGraphic");

    arcade::IGame *snake = getGame();
    arcade::IGraphic *sdl2 = getGraphic();
    test(snake, sdl2);
    dlclose(snake_handler);
    dlclose(sdl2_handler);
    std::cout << "SDL2 exited" << std::endl;
    return 0;
}
