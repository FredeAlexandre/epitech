/*
** EPITECH PROJECT, 2022
** arcade_ecs.hpp
** File description:
** Definition of the ECS layer of the Arcade project
*/

#include <string>
#include <typeindex>

#include "IEntity.hpp"

#ifndef _ARCADE_ECS_AENTITY_
    #define _ARCADE_ECS_AENTITY_

namespace arcade {
    namespace ecs {
        class AEntity : public arcade::ecs::IEntity {
            public:
                bool operator==(const arcade::ecs::IEntity &other) const override;
                bool operator!=(const arcade::ecs::IEntity &other) const override;

                bool operator==(const std::string &id) const override;
                bool operator!=(const std::string &id) const override;

                std::map<std::string, std::shared_ptr<arcade::ecs::IComponent>> &getComponents(void) override;


                std::shared_ptr<arcade::ecs::IComponent> addComponent(const std::string &id) override;
                std::shared_ptr<arcade::ecs::IComponent> getComponent(const std::string &id) override;

            protected:
                std::map<std::string, std::shared_ptr<arcade::ecs::IComponent>> Components;
        };
    };
};

#endif
