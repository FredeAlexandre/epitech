/*
** EPITECH PROJECT, 2022
** arcade_components.hpp
** File description:
** Definition of the basic components of the Arcade project
*/

#include <string>

#include "../ecs/AComponent.hpp"

#ifndef _ARCADE_COMPONENTS_CLOCK_
    #define _ARCADE_COMPONENTS_CLOCK_

namespace arcade {
    namespace components {
        struct ClockComponent : public arcade::ecs::AComponent {

            inline std::string getId(void) const override { return "clock"; };

            int64_t timestamp;
            int64_t duration;
        };
    };
};

#endif
