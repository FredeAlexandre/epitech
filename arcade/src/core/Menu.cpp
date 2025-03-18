/*
** EPITECH PROJECT, 2022
** arcade.hpp
** File description:
** The common layer of the Arcade project
*/

#include <memory>
#include <filesystem>

#include "menu.hpp"

extern "C" {
    arcade::IGame *getGame(void)
    {
        return new Menu();
    }

    void destroyGame(arcade::IGame *game)
    {
        delete game;
    }
};

std::list<std::shared_ptr<arcade::ecs::IEntity>> Menu::init(void)
{
    if (intialized) {

        for (auto entity : Entities) {
            if (entity->getId() == "TextBox") {
                auto inputsComponent = Helper::getComponent<arcade::components::GetInputsComponent>(*entity);
                inputsComponent->inputs.clear();
                auto endComponent = Helper::getComponent<arcade::components::EndComponent>(*entity);
                endComponent->end = false;
                break;
            }
        }
        
        return Entities;
    }
    intialized = true;
    auto textbox = std::make_shared<TextBox>(arcade::components::TextComponent::Position::Center, arcade::components::TextComponent::Position::Center);
    Helper::getComponent<arcade::components::TextComponent>(*textbox)->value = "Name: , Score: 0";
    Helper::addComponent<arcade::components::GetInputsComponent>(*textbox);
    Helper::addComponent<arcade::components::ScoreComponent>(*textbox);
    Helper::addComponent<arcade::components::EndComponent>(*textbox);
    Entities.push_back(textbox);
    return Entities;
}

void Menu::update(std::list<std::shared_ptr<arcade::ecs::IEntity>> &entities)
{

    std::shared_ptr<arcade::ecs::IEntity> textbox;
    for (auto &entity : entities) {
        if (entity->getId() == "TextBox") {
            textbox = entity;
            break;
        }
    }
    if (!textbox) return;
    if (LOGS)
        std::cout << "TextBox found !" << std::endl;

    
    auto text = Helper::getComponent<arcade::components::TextComponent>(*textbox);

    auto scoreComponent = Helper::getComponent<arcade::components::ScoreComponent>(*textbox);
    text->value = "Name: " + username + ", Score: " + std::to_string(scoreComponent->score);

    auto inputs = Helper::getComponent<arcade::components::GetInputsComponent>(*textbox)->inputs;

    if (inputs.size() == 0) return;

    if (LOGS)
        std::cout << "Inputs found !" << std::endl;

    bool removeLast = hasBackSpace(inputs);
    if (removeLast) {
        if (username.size() > 0) {
            username.pop_back();
        }
    }
    bool isUpper = hasShiftKey(inputs);
    std::string inputed = getTextInputed(inputs, textbox);
    if (isUpper) {
        for (auto &c : inputed) c = std::toupper(c);
    }
    if (LOGS)
        std::cout << "Key inputed: " << inputed << std::endl;
    username += inputed;
}

bool Menu::hasShiftKey(std::list<arcade::enums::Input> &inputs) const
{
    for (auto input : inputs) {
        if (input == arcade::enums::Input::LShift) return true;
    }
    return false;
}

bool Menu::hasBackSpace(std::list<arcade::enums::Input> &inputs) const
{
    for (auto input : inputs) {
        if (input == arcade::enums::Input::BackSpace) return true;
    }
    return false;
}

std::string Menu::getTextInputed(std::list<arcade::enums::Input> &inputs, std::shared_ptr<arcade::ecs::IEntity> &textbox)
{
    std::string result = "";

    for (auto input : inputs) {
        if (input == arcade::enums::Input::Return) {
            if (LOGS)
                std::cout << "[MENU]: Return key pressed !" << std::endl;
            auto end = Helper::getComponent<arcade::components::EndComponent>(*textbox);
            end->end = true;
            return result;
        }
        if (getInputToString.find(input) == getInputToString.end()) continue;
        result += getInputToString.at(input);
    }

    return result;
}

TextBox::TextBox(arcade::components::TextComponent::Position hp,  arcade::components::TextComponent::Position vp)
{
    auto text = Helper::addComponent<arcade::components::TextComponent>(*this);
    text->horizontalPosition = hp;
    text->verticalPosition = vp;
    text->size = 16;
}