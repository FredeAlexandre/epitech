/*
** EPITECH PROJECT, 2022
** arcade.hpp
** File description:
** The common layer of the Arcade project
*/

#include "components/GetInputsComponent.hpp"
#include "components/PositionComponent.hpp"
#include "components/SizeComponent.hpp"
#include "components/SpriteComponent.hpp"
#include "components/SpriteSheetComponent.hpp"
#include "components/TextComponent.hpp"
#include "components/ExitComponent.hpp"
#include "components/ClockComponent.hpp"
#include "components/ScoreComponent.hpp"
#include "components/EndComponent.hpp"

#include "core/ABI.hpp"
#include "core/IGame.hpp"
#include "core/IGraphic.hpp"

#include "ecs/AComponent.hpp"
#include "ecs/AEntity.hpp"
#include "ecs/IComponent.hpp"
#include "ecs/IEntity.hpp"
#include "ecs/ISystem.hpp"

#include "enums/Color.hpp"
#include "enums/Input.hpp"

#ifndef _ARCADE_
    #define _ARCADE_

#define LOGS false

class Helper {
    public:
        static std::shared_ptr<arcade::ecs::IComponent> createComponent(const std::string &id);

        template<typename T>
        static std::shared_ptr<T> addComponent(arcade::ecs::IEntity &entity);

        template<typename T>
        static std::shared_ptr<T> getComponent(arcade::ecs::IEntity &entity);
};

#endif
