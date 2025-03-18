/*
** EPITECH PROJECT, 2022
** arcade.hpp
** File description:
** The common layer of the Arcade project
*/

#include "include/menu.hpp"
#include "include/manager.hpp"

#include <iostream>

int main(int ac, char **av)
{
    Menu menu;

    auto entities = menu.init();

    auto textComponent =  Helper::getComponent<arcade::components::TextComponent>(*entities.front());
    if (textComponent == nullptr) {
        std::cout << "(menu.t.cpp, init_text_value) KO: textComponent == nullptr" << std::endl;
        return 1;
    }

    auto inputsComponent = Helper::getComponent<arcade::components::GetInputsComponent>(*entities.front());
    if (inputsComponent == nullptr) {
        std::cout << "(menu.t.cpp, init_text_value) KO: inputsComponent == nullptr" << std::endl;
        return 1;
    }

    if (textComponent->value != "Enter Name:\n") {
        std::cout << "(menu.t.cpp, init_text_value) KO: value != \"Enter Name:\\n\"" << std::endl;
        return 1;
    } else {
        std::cout << "(menu.t.cpp, init_text_value) OK" << std::endl;
    }

    menu.update(entities);

    inputsComponent->inputs.clear();
    inputsComponent->inputs.push_back(arcade::enums::Input::A);
    inputsComponent->inputs.push_back(arcade::enums::Input::LShift);

    menu.update(entities);

    inputsComponent->inputs.clear();
    inputsComponent->inputs.push_back(arcade::enums::Input::L);

    menu.update(entities);

    inputsComponent->inputs.clear();
    inputsComponent->inputs.push_back(arcade::enums::Input::E);

    menu.update(entities);

    inputsComponent->inputs.clear();
    inputsComponent->inputs.push_back(arcade::enums::Input::X);

    menu.update(entities);

    if (textComponent->value != "Enter Name:\nAlex") {
        std::cout << "|" << textComponent->value << "|" << std::endl;
        std::cout << "(menu.t.cpp, update_text_value) KO: value != \"Enter Name:\\nAlex\"" << std::endl;
        return 1;
    } else {
        std::cout << "(menu.t.cpp, update_text_value) OK" << std::endl;
    }

    return 0;
}
