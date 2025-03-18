/*
** EPITECH PROJECT, 2022
** arcade.hpp
** File description:
** The common layer of the Arcade project
*/

#include <string>
#include <list>
#include <memory>

#include "../ecs/ISystem.hpp"

#ifndef _ARCADE_ECS_IGAME_
    #define _ARCADE_ECS_IGAME_

namespace arcade {

    struct WindowSize {
        int width;
        int height;
    };

    class IGame : public arcade::ecs::ISystem {
        public:
            virtual ~IGame() = default;

            virtual std::list<std::shared_ptr<arcade::ecs::IEntity>> init(void) = 0;

            virtual void update(std::list<std::shared_ptr<arcade::ecs::IEntity>> &entities) = 0;

            virtual WindowSize getWindowSize(void) const = 0;
    };
};

#endif
