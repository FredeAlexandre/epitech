/*
** EPITECH PROJECT, 2022
** arcade_components.hpp
** File description:
** Definition of the basic components of the Arcade project
*/

#include <string>

#include "../ecs/AComponent.hpp"
#include "../enums/Color.hpp"

#ifndef _ARCADE_COMPONENTS_SPRITE_
    #define _ARCADE_COMPONENTS_SPRITE_

namespace arcade {
    namespace components {
        struct SpriteComponent : public arcade::ecs::AComponent {
            inline std::string getId(void) const override { return "sprite"; };
            
            int x;
            int y;
            int width;
            int height;

            arcade::enums::Color color;
        };
    };
};

#endif
