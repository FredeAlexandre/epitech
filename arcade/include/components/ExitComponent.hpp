/*
** EPITECH PROJECT, 2022
** arcade_components.hpp
** File description:
** Definition of the basic components of the Arcade project
*/

#include <string>

#include "../ecs/AComponent.hpp"

#ifndef _ARCADE_COMPONENTS_EXIT_
    #define _ARCADE_COMPONENTS_EXIT_

namespace arcade {
    namespace components {
        struct ExitComponent : public arcade::ecs::AComponent {

            inline std::string getId(void) const override { return "exit"; };

            bool exit = false;
        };
    };
};

#endif
