/*
** EPITECH PROJECT, 2022
** arcade_ecs.hpp
** File description:
** Definition of the ECS layer of the Arcade project
*/

#include <string>

#ifndef _ARCADE_ECS_ICOMPONENT_
    #define _ARCADE_ECS_ICOMPONENT_

namespace arcade {
    namespace ecs {
        class IComponent {
            public:
                virtual ~IComponent() = default;

                virtual std::string getId(void) const = 0;

                virtual bool operator==(const arcade::ecs::IComponent &other) const = 0;
                virtual bool operator!=(const arcade::ecs::IComponent &other) const = 0;

                virtual bool operator==(const std::string &id) const = 0;
                virtual bool operator!=(const std::string &id) const = 0;
        };
    };
};

#endif
