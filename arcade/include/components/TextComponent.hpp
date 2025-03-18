/*
** EPITECH PROJECT, 2022
** arcade_components.hpp
** File description:
** Definition of the basic components of the Arcade project
*/

#include <string>

#include "../ecs/AComponent.hpp"

#ifndef _ARCADE_COMPONENTS_TEXT_
    #define _ARCADE_COMPONENTS_TEXT_

namespace arcade {
    namespace components {
        struct TextComponent : public arcade::ecs::AComponent {
            enum Position { Start, Center, End};

            inline std::string getId(void) const override { return "text"; };

            std::string value;
            int size;

            Position horizontalPosition = Center;
            Position verticalPosition = Center;
        };
    };
};

#endif
