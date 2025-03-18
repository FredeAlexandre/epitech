/*
** EPITECH PROJECT, 2022
** arcade_ecs.hpp
** File description:
** Definition of the ECS layer of the Arcade project
*/

#include <memory>
#include <stdexcept>

#include "arcade.hpp"

std::shared_ptr<arcade::ecs::IComponent> Helper::createComponent(const std::string &id)
{
    if (id == "position")
        return std::make_shared<arcade::components::PositionComponent>();
    if (id == "get_inputs")
        return std::make_shared<arcade::components::GetInputsComponent>();
    if (id == "size")
        return std::make_shared<arcade::components::SizeComponent>();
    if (id == "sprite")
        return std::make_shared<arcade::components::SpriteComponent>();
    if (id == "sprite_sheet")
        return std::make_shared<arcade::components::SpriteSheetComponent>();
    if (id == "text")
        return std::make_shared<arcade::components::TextComponent>();
    if (id == "exit")
        return std::make_shared<arcade::components::ExitComponent>();
    if (id == "clock")
        return std::make_shared<arcade::components::ClockComponent>();
    if (id == "score")
        return std::make_shared<arcade::components::ScoreComponent>();
    if (id == "end")
        return std::make_shared<arcade::components::EndComponent>();
    throw std::runtime_error("Component not found");
}

template<typename T>
std::shared_ptr<T> Helper::addComponent(arcade::ecs::IEntity &entity)
{
    static_assert(std::is_base_of<arcade::ecs::IComponent, T>::value, "T must inherit from IComponent");
    std::type_index id = typeid(T);
    std::shared_ptr<arcade::ecs::IComponent> component = nullptr;
    if (id == typeid(arcade::components::PositionComponent))
        component = entity.addComponent("position");
    if (id == typeid(arcade::components::GetInputsComponent))
        component = entity.addComponent("get_inputs");
    if (id == typeid(arcade::components::SizeComponent))
        component = entity.addComponent("size");
    if (id == typeid(arcade::components::SpriteComponent))
        component = entity.addComponent("sprite");
    if (id == typeid(arcade::components::SpriteSheetComponent))
        component = entity.addComponent("sprite_sheet");
    if (id == typeid(arcade::components::TextComponent))
        component = entity.addComponent("text");
    if (id == typeid(arcade::components::ExitComponent))
        component = entity.addComponent("exit");
    if (id == typeid(arcade::components::ClockComponent))
        component = entity.addComponent("clock");
    if (id == typeid(arcade::components::ScoreComponent))
        component = entity.addComponent("score");
    if (id == typeid(arcade::components::EndComponent))
        component = entity.addComponent("end");
    if (component == nullptr) return nullptr;
    return std::dynamic_pointer_cast<T>(component);
}

template std::shared_ptr<arcade::components::SpriteComponent> Helper::addComponent(arcade::ecs::IEntity &entity);
template std::shared_ptr<arcade::components::SizeComponent> Helper::addComponent(arcade::ecs::IEntity &entity);
template std::shared_ptr<arcade::components::PositionComponent> Helper::addComponent(arcade::ecs::IEntity &entity);
template std::shared_ptr<arcade::components::GetInputsComponent> Helper::addComponent(arcade::ecs::IEntity &entity);
template std::shared_ptr<arcade::components::SpriteSheetComponent> Helper::addComponent(arcade::ecs::IEntity &entity);
template std::shared_ptr<arcade::components::TextComponent> Helper::addComponent(arcade::ecs::IEntity &entity);
template std::shared_ptr<arcade::components::ExitComponent> Helper::addComponent(arcade::ecs::IEntity &entity);
template std::shared_ptr<arcade::components::ClockComponent> Helper::addComponent(arcade::ecs::IEntity &entity);
template std::shared_ptr<arcade::components::ScoreComponent> Helper::addComponent(arcade::ecs::IEntity &entity);
template std::shared_ptr<arcade::components::EndComponent> Helper::addComponent(arcade::ecs::IEntity &entity);

template<typename T>
std::shared_ptr<T> Helper::getComponent(arcade::ecs::IEntity &entity)
{
    static_assert(std::is_base_of<arcade::ecs::IComponent, T>::value, "T must inherit from IComponent");
    std::type_index id = typeid(T);
    std::shared_ptr<arcade::ecs::IComponent> component = nullptr;
    if (id == typeid(arcade::components::PositionComponent))
        component = entity.getComponent("position");
    if (id == typeid(arcade::components::GetInputsComponent))
        component = entity.getComponent("get_inputs");
    if (id == typeid(arcade::components::SizeComponent))
        component = entity.getComponent("size");
    if (id == typeid(arcade::components::SpriteComponent))
        component = entity.getComponent("sprite");
    if (id == typeid(arcade::components::SpriteSheetComponent))
        component = entity.getComponent("sprite_sheet");
    if (id == typeid(arcade::components::TextComponent))
        component = entity.getComponent("text");
    if (id == typeid(arcade::components::ExitComponent))
        component = entity.getComponent("exit");
    if (id == typeid(arcade::components::ClockComponent))
        component = entity.getComponent("clock");
    if (id == typeid(arcade::components::ScoreComponent))
        component = entity.getComponent("score");
    if (id == typeid(arcade::components::EndComponent))
        component = entity.getComponent("end");
    if (component == nullptr) return nullptr;
    return std::dynamic_pointer_cast<T>(component);
}

template std::shared_ptr<arcade::components::SpriteComponent> Helper::getComponent(arcade::ecs::IEntity &entity);
template std::shared_ptr<arcade::components::SizeComponent> Helper::getComponent(arcade::ecs::IEntity &entity);
template std::shared_ptr<arcade::components::PositionComponent> Helper::getComponent(arcade::ecs::IEntity &entity);
template std::shared_ptr<arcade::components::GetInputsComponent> Helper::getComponent(arcade::ecs::IEntity &entity);
template std::shared_ptr<arcade::components::SpriteSheetComponent> Helper::getComponent(arcade::ecs::IEntity &entity);
template std::shared_ptr<arcade::components::TextComponent> Helper::getComponent(arcade::ecs::IEntity &entity);
template std::shared_ptr<arcade::components::ExitComponent> Helper::getComponent(arcade::ecs::IEntity &entity);
template std::shared_ptr<arcade::components::ClockComponent> Helper::getComponent(arcade::ecs::IEntity &entity);
template std::shared_ptr<arcade::components::ScoreComponent> Helper::getComponent(arcade::ecs::IEntity &entity);
template std::shared_ptr<arcade::components::EndComponent> Helper::getComponent(arcade::ecs::IEntity &entity);