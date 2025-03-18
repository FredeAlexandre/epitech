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

#ifndef _ARCADE_ECS_IGRAPHIC_
    #define _ARCADE_ECS_IGRAPHIC_

namespace arcade {
    struct GraphicInit {
        int width;
        int height;
    };

    class IGraphic : public arcade::ecs::ISystem {
        public:
            virtual ~IGraphic() = default;

            virtual void init(GraphicInit value) = 0;

            virtual void update(std::list<std::shared_ptr<arcade::ecs::IEntity>> &entities) = 0;
    };
};

#endif
