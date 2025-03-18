/*
** EPITECH PROJECT, 2022
** arcade_components.hpp
** File description:
** Definition of the basic components of the Arcade project
*/

#include <string>

#include "../ecs/AComponent.hpp"

#ifndef _ARCADE_COMPONENTS_SIZE_
    #define _ARCADE_COMPONENTS_SIZE_

namespace arcade {
    namespace components {
        struct SizeComponent : public arcade::ecs::AComponent {
            inline std::string getId(void) const override { return "size"; };
            float width;
            float height;
            float depth;
        };
    };
};

#endif
