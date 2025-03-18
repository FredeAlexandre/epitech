/*
** EPITECH PROJECT, 2022
** arcade.hpp
** File description:
** The common layer of the Arcade project
*/

#include <dlfcn.h>

#include <string>

#include "loaders.hpp"

GraphicLoader::GraphicLoader(const std::string &name, const std::string &path) : Loader(path)
{
    Name = name;
    GetGraphic = reinterpret_cast<GetGraphicType>(dlsym(Handler, "getGraphic"));
    DestroyGraphic = reinterpret_cast<DestroyGraphicType>(dlsym(Handler, "destroyGraphic"));
    Graphic = GetGraphic();
}

GraphicLoader::~GraphicLoader()
{
    DestroyGraphic(Graphic);
}

void GraphicLoader::reload()
{
    DestroyGraphic(Graphic);
    Graphic = GetGraphic();
}

void GraphicLoader::init(arcade::GraphicInit value)
{
    Graphic->init(value);
}

void GraphicLoader::update(std::list<std::shared_ptr<arcade::ecs::IEntity>> &entities)
{
    Graphic->update(entities);
}

const std::string &GraphicLoader::getName(void) const
{
    return Name;
}
