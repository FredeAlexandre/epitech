/*
** EPITECH PROJECT, 2022
** arcade.hpp
** File description:
** The common layer of the Arcade project
*/

#include <dlfcn.h>

#include <string>

#include "loaders.hpp"

GameLoader::GameLoader(const std::string &name, const std::string &path) : Loader(path)
{
    Name = name;
    GetGame = reinterpret_cast<GetGameType>(dlsym(Handler, "getGame"));
    DestroyGame = reinterpret_cast<DestroyGameType>(dlsym(Handler, "destroyGame"));
    Game = GetGame();
}

GameLoader::~GameLoader()
{
    DestroyGame(Game);
}

void GameLoader::reload()
{
    DestroyGame(Game);
    Game = GetGame();
}

std::list<std::shared_ptr<arcade::ecs::IEntity>> GameLoader::init(void)
{
    return Game->init();
}

void GameLoader::update(std::list<std::shared_ptr<arcade::ecs::IEntity>> &entities)
{
    Game->update(entities);
}

arcade::WindowSize GameLoader::getWindowSize(void) const
{
    return Game->getWindowSize();
}

const std::string &GameLoader::getName(void) const
{
    return Name;
}
