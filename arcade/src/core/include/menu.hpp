/*
** EPITECH PROJECT, 2022
** arcade.hpp
** File description:
** The common layer of the Arcade project
*/

#include <iostream>

#include "arcade.hpp"

#ifndef _ARCADE_CORE_MENU_
    #define _ARCADE_CORE_MENU_

using InputToString = std::map<arcade::enums::Input, std::string>;

const InputToString getInputToString = {
    {arcade::enums::Input::A, "a"},
    {arcade::enums::Input::B, "b"},
    {arcade::enums::Input::C, "c"},
    {arcade::enums::Input::D, "d"},
    {arcade::enums::Input::E, "e"},
    {arcade::enums::Input::F, "f"},
    {arcade::enums::Input::G, "g"},
    {arcade::enums::Input::H, "h"},
    {arcade::enums::Input::I, "i"},
    {arcade::enums::Input::J, "j"},
    {arcade::enums::Input::K, "k"},
    {arcade::enums::Input::L, "l"},
    {arcade::enums::Input::M, "m"},
    {arcade::enums::Input::N, "n"},
    {arcade::enums::Input::O, "o"},
    {arcade::enums::Input::P, "p"},
    {arcade::enums::Input::Q, "q"},
    {arcade::enums::Input::R, "r"},
    {arcade::enums::Input::S, "s"},
    {arcade::enums::Input::T, "t"},
    {arcade::enums::Input::U, "u"},
    {arcade::enums::Input::V, "v"},
    {arcade::enums::Input::W, "w"},
    {arcade::enums::Input::X, "x"},
    {arcade::enums::Input::Y, "y"},
    {arcade::enums::Input::Z, "z"},
    {arcade::enums::Input::Num0, "0"},
    {arcade::enums::Input::Num1, "1"},
    {arcade::enums::Input::Num2, "2"},
    {arcade::enums::Input::Num3, "3"},
    {arcade::enums::Input::Num4, "4"},
    {arcade::enums::Input::Num5, "5"},
    {arcade::enums::Input::Num6, "6"},
    {arcade::enums::Input::Num7, "7"},
    {arcade::enums::Input::Num8, "8"},
    {arcade::enums::Input::Num9, "9"},
    {arcade::enums::Input::Escape, " "},
};

class Menu : public arcade::IGame {
    public:
        std::list<std::shared_ptr<arcade::ecs::IEntity>> init(void) override;

        void update(std::list<std::shared_ptr<arcade::ecs::IEntity>> &entities) override;
        
        bool hasShiftKey(std::list<arcade::enums::Input> &inputs) const;

        bool hasBackSpace(std::list<arcade::enums::Input> &inputs) const;

        std::string getTextInputed(std::list<arcade::enums::Input> &inputs, std::shared_ptr<arcade::ecs::IEntity> &textbox);

        inline arcade::WindowSize getWindowSize(void) const override { return { 1920, 1080 }; }
    
    private:
        std::list<std::shared_ptr<arcade::ecs::IEntity>> Entities;
        std::string username = "";

        bool intialized = false;
};

class TextBox : public arcade::ecs::AEntity {
    public:
        inline std::string getId(void) const { return "TextBox"; }

        TextBox(arcade::components::TextComponent::Position hp,  arcade::components::TextComponent::Position vp);
};

#endif
