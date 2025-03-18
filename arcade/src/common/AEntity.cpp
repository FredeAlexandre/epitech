/*
** EPITECH PROJECT, 2022
** arcade_ecs.hpp
** File description:
** Definition of the ECS layer of the Arcade project
*/

#include <memory>

#include "arcade.hpp"

bool arcade::ecs::AEntity::operator==(const arcade::ecs::IEntity &other) const
{
    return getId() == other.getId();
}

bool arcade::ecs::AEntity::operator!=(const arcade::ecs::IEntity &other) const
{
    return getId() != other.getId();
}

bool arcade::ecs::AEntity::operator==(const std::string &id) const
{
    return  getId() == id;
};

bool arcade::ecs::AEntity::operator!=(const std::string &id) const {
    return  getId() != id;
};

std::map<std::string, std::shared_ptr<arcade::ecs::IComponent>> &arcade::ecs::AEntity::getComponents(void)
{
    return Components;
}


std::shared_ptr<arcade::ecs::IComponent> arcade::ecs::AEntity::addComponent(const std::string &id)
{
    auto component = getComponent(id);
    if (component != nullptr)
        return component;
    Components[id] = Helper::createComponent(id);
    return Components.at(id);
}

std::shared_ptr<arcade::ecs::IComponent> arcade::ecs::AEntity::getComponent(const std::string &id)
{
    if (Components.find(id) == Components.end())
        return nullptr;
    return Components.at(id);
}
