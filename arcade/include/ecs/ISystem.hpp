/*
** EPITECH PROJECT, 2022
** arcade_ecs.hpp
** File description:
** Definition of the ECS layer of the Arcade project
*/

#include <string>
#include <list>
#include <memory>

#include "IEntity.hpp"

#ifndef _ARCADE_ECS_ISYSTEM_
    #define _ARCADE_ECS_ISYSTEM_

namespace arcade {
    namespace ecs {
        class ISystem {
            public:
                virtual ~ISystem() = default;

                virtual void update(std::list<std::shared_ptr<arcade::ecs::IEntity>> &entities) = 0;
        };
    };
};

#endif
