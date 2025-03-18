/*
** EPITECH PROJECT, 2022
** arcade_components.hpp
** File description:
** Definition of the basic components of the Arcade project
*/

#include <string>

#include "../ecs/AComponent.hpp"

#ifndef _ARCADE_COMPONENTS_SCORE_
    #define _ARCADE_COMPONENTS_SCORE_

namespace arcade {
    namespace components {
        struct ScoreComponent : public arcade::ecs::AComponent {
            inline std::string getId(void) const override { return "score"; };
            
            int score;
        };
    };
};

#endif
