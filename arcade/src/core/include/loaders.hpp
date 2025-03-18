/*
** EPITECH PROJECT, 2022
** arcade.hpp
** File description:
** The common layer of the Arcade project
*/

#include <iostream>
#include <dlfcn.h>

#include "arcade.hpp"

#ifndef _ARCADE_CORE_LOADER_
    #define _ARCADE_CORE_LOADER_

typedef arcade::IGame *(*GetGameType)(void);
typedef arcade::IGraphic *(*GetGraphicType)(void);
typedef void (*DestroyGameType)(arcade::IGame *);
typedef void (*DestroyGraphicType)(arcade::IGraphic *);

class Loader {
    public:
        Loader(const std::string &path);

        ~Loader();

    protected:
        void *Handler = nullptr;
};

class GameLoader : public Loader, public arcade::IGame {
    public:
        GameLoader(const std::string &name, const std::string &path);
        ~GameLoader();

        void reload(void);
        std::list<std::shared_ptr<arcade::ecs::IEntity>> init(void) override;
        void update(std::list<std::shared_ptr<arcade::ecs::IEntity>> &entities) override;
        arcade::WindowSize getWindowSize(void) const override;
        const std::string& getName(void) const;

    private:
        GetGameType GetGame;
        DestroyGameType DestroyGame;
        arcade::IGame *Game = nullptr;
        std::string Name;
};

class GraphicLoader : public Loader, public arcade::IGraphic {
    public:
        GraphicLoader(const std::string &name, const std::string &path);
        ~GraphicLoader();

        void reload(void);
        void init(arcade::GraphicInit value) override;
        void update(std::list<std::shared_ptr<arcade::ecs::IEntity>> &entities) override;
        const std::string& getName(void) const;

    private:
        GetGraphicType GetGraphic;
        DestroyGraphicType DestroyGraphic;
        arcade::IGraphic *Graphic = nullptr;;
        std::string Name;
};

#endif
