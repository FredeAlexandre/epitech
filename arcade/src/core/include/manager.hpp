/*
** EPITECH PROJECT, 2022
** arcade.hpp
** File description:
** The common layer of the Arcade project
*/

#include <string>
#include <vector>

#include "loaders.hpp"

#ifndef _ARCADE_CORE_MANAGER_
    #define _ARCADE_CORE_MANAGER_

    #define LIB_FOLDER "./lib/"

enum LibType { Unkwon, Game, Graphic };

using FileLoaderMap = std::map<std::string, LibType>;

const FileLoaderMap fileLoaders = {
    { "arcade_ndk++.so", Graphic },
    { "arcade_aalib.so", Graphic },
    { "arcade_libcaca.so", Graphic },
    { "arcade_allegro5.so", Graphic },
    { "arcade_xlib.so", Graphic },
    { "arcade_gtk+.so", Graphic },
    { "arcade_sfml.so", Graphic },
    { "arcade_irrlicht.so", Graphic },
    { "arcade_opengl.so", Graphic },
    { "arcade_vulkan.so", Graphic },
    {"arcade_ncurses.so", Graphic },
    { "arcade_qt5.so", Graphic },
    { "arcade_sdl2.so", Graphic },
    { "arcade_snake.so", Game },
    { "arcade_nibbler.so", Game },
    { "arcade_pacman.so", Game },
    { "arcade_qix.so", Game },
    { "arcade_centipede.so", Game },
    { "arcade_solarfox.so", Game },
};

class Manager {
    public:
        Manager();
        ~Manager();

        enum FrameResult { Continue, Enter, Return };

        std::list<std::shared_ptr<arcade::ecs::IEntity>> startGame(void);
        void startGraphic(void);

        std::list<std::shared_ptr<arcade::ecs::IEntity>> backToMenu(void);

        std::list<std::shared_ptr<arcade::ecs::IEntity>> nextGame(void);
        void prevGame(void);

        std::list<std::shared_ptr<arcade::ecs::IEntity>> restartGame(void);

        void nextGraphic(void);
        void prevGraphic(void);

        FrameResult frame(std::list<std::shared_ptr<arcade::ecs::IEntity>> &entities);

        GameLoader *getGame(void) const { return Games[GameIndex]; }
        GraphicLoader *getGraphic(void) const { return Graphics[GraphicIndex]; }

    private:
        std::vector<GameLoader *> Games;
        int GameIndex = 0;
        std::vector<GraphicLoader *> Graphics;
        int GraphicIndex = 0;

        arcade::IGame* Menu;
        bool isMenu = true;

        std::string LibFolder;
        arcade::GraphicInit GraphicStartData;

        int actualScore = 0;
};

#endif
