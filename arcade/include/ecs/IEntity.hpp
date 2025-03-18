/*
** EPITECH PROJECT, 2022
** arcade_ecs.hpp
** File description:
** Definition of the ECS layer of the Arcade project
*/

#include <string>
#include <map>
#include <memory>
#include <typeindex>

#include "IComponent.hpp"

#ifndef _ARCADE_ECS_IENTITY_
    #define _ARCADE_ECS_IENTITY_

namespace arcade {
    namespace ecs {
        class IEntity {
            public:
                virtual ~IEntity() = default;

                virtual std::string getId(void) const = 0;
                virtual std::map<std::string, std::shared_ptr<arcade::ecs::IComponent>> &getComponents(void) = 0;

                virtual bool operator==(const arcade::ecs::IEntity &other) const = 0;
                virtual bool operator!=(const arcade::ecs::IEntity &other) const = 0;

                virtual bool operator==(const std::string &id) const = 0;
                virtual bool operator!=(const std::string &id) const = 0;

                virtual std::shared_ptr<arcade::ecs::IComponent> addComponent(const std::string &id) = 0;
                virtual std::shared_ptr<arcade::ecs::IComponent> getComponent(const std::string &id) = 0;
        };
    };
};

#endif
