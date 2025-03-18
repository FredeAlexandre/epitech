/*
** EPITECH PROJECT, 2022
** arcade_ecs.hpp
** File description:
** Definition of the ECS layer of the Arcade project
*/

#include "arcade.hpp"

bool arcade::ecs::AComponent::operator!=(const arcade::ecs::IComponent &other) const
{
    return getId() != other.getId();
}

bool arcade::ecs::AComponent::operator==(const arcade::ecs::IComponent &other) const
{
    return  getId() == other.getId();
}

bool arcade::ecs::AComponent::operator!=(const std::string &id) const
{
    return  getId() != id;
}

bool arcade::ecs::AComponent::operator==(const std::string &id) const
{
    return  getId() == id;
}
