/*
** EPITECH PROJECT, 2022
** arcade_ecs.hpp
** File description:
** Definition of the ECS layer of the Arcade project
*/

#include <string>

#include "IComponent.hpp"

#ifndef _ARCADE_ECS_ACOMPONENT_
    #define _ARCADE_ECS_ACOMPONENT_

namespace arcade {
    namespace ecs {
        class AComponent : public arcade::ecs::IComponent {
            public:
                bool operator==(const arcade::ecs::IComponent &other) const override;
                bool operator!=(const arcade::ecs::IComponent &other) const override;

                bool operator==(const std::string &id) const override;
                bool operator!=(const std::string &id) const override;
        };
    };
};

#endif
