/*
** EPITECH PROJECT, 2022
** arcade_components.hpp
** File description:
** Definition of the basic components of the Arcade project
*/

#include <string>

#include "../ecs/AComponent.hpp"

#ifndef _ARCADE_COMPONENTS_POSITION_
    #define _ARCADE_COMPONENTS_POSITION_

namespace arcade {
    namespace components {
        struct PositionComponent : public arcade::ecs::AComponent {
            inline std::string getId(void) const override { return "position"; };
            int x;
            int y;
            int z;
            int rotation;
        };
    };
};

#endif
