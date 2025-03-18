/*
** EPITECH PROJECT, 2022
** arcade_components.hpp
** File description:
** Definition of the basic components of the Arcade project
*/

#include <string>
#include <list>

#include "../ecs/AComponent.hpp"
#include "../enums/Input.hpp"

#ifndef _ARCADE_COMPONENTS_GET_INPUTS_
    #define _ARCADE_COMPONENTS_GET_INPUTS_

namespace arcade {
    namespace components {
        struct GetInputsComponent : public arcade::ecs::AComponent {
            inline std::string getId(void) const override { return "get_inputs"; };
            
            std::list<arcade::enums::Input> inputs;
        };
    };
};

#endif
