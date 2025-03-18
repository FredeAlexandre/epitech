/*
** EPITECH PROJECT, 2022
** arcade.hpp
** File description:
** The common layer of the Arcade project
*/

#include <list>
#include <memory>
#include <chrono>

#include "arcade.hpp"
#include "manager.hpp"
#include "loaders.hpp"
#include "menu.hpp"

#ifndef _ARCADE_CORE_CORE_
    #define _ARCADE_CORE_CORE_

#define FRAME_RATE 30

#define NEXT_GRAPHIC arcade::enums::Input::F1
#define NEXT_GAME arcade::enums::Input::F2
#define RESTART_GAME arcade::enums::Input::F3
#define LEAVE_GAME arcade::enums::Input::F4
#define EXIT_ARCADE arcade::enums::Input::Escape

class CoreEntity : public arcade::ecs::AEntity {
    public:
        CoreEntity() {
            Helper::addComponent<arcade::components::ExitComponent>(*this);
            Helper::addComponent<arcade::components::GetInputsComponent>(*this);
        }

        inline std::string getId(void) const { return "core_entity"; }

};

class Core {
    public:
        void loop(void);

        void update_clock(void);

        void check_inputs(void);

        bool isRunning(void) const;

        void updateEntities(std::list<std::shared_ptr<arcade::ecs::IEntity>> entities);

    private:
        std::shared_ptr<CoreEntity> coreEntity = std::make_shared<CoreEntity>();
        std::list<std::shared_ptr<arcade::ecs::IEntity>> Entities;
        Manager manager;
        std::chrono::system_clock::duration lastUpdate = std::chrono::system_clock::now().time_since_epoch();
};

#endif
