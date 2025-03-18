/*
** EPITECH PROJECT, 2022
** arcade.hpp
** File description:
** The common layer of the Arcade project
*/

#include <thread>
#include <memory>
#include <filesystem>

#include "core.hpp"

void Core::loop(void)
{
    if (LOGS)
        std::cout << "[CORE] Start loop" << std::endl;
    updateEntities(manager.startGame());
    if (LOGS)
        std::cout << "[CORE] Entities generated game starting" << std::endl;
    manager.startGraphic();
    if (LOGS)
        std::cout << "[CORE] Graphic lib starting" << std::endl;

    while (isRunning()) {
        update_clock();
        auto result = manager.frame(Entities);
        if (result == Manager::FrameResult::Enter) {
            updateEntities(manager.nextGame());
        }
        if (result == Manager::FrameResult::Return) {
            updateEntities(manager.backToMenu());
        }
        check_inputs();
        std::this_thread::sleep_for(std::chrono::milliseconds(1000/FRAME_RATE));
    }

    if (LOGS)
        std::cout << "[CORE] End loop" << std::endl;
}

void Core::update_clock(void)
{
    if (LOGS)
        std::cout << "[CORE] Updating clocks" << std::endl;
    auto duration = std::chrono::system_clock::now().time_since_epoch() - lastUpdate;
    lastUpdate = std::chrono::system_clock::now().time_since_epoch();
    int64_t timestamp = std::chrono::duration_cast<std::chrono::seconds>(lastUpdate).count();
    int64_t duration_ = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
    for (auto entity : Entities) {
        auto clock = Helper::getComponent<arcade::components::ClockComponent>(*entity);
        if (clock == nullptr) continue;
            if (LOGS)
                std::cout << "[CORE] Clock found !" << std::endl;
        clock->timestamp = timestamp;
        clock->duration = duration_;
    }
}

void Core::check_inputs(void)
{
    if (LOGS)
        std::cout << "[CORE] Check inputs" << std::endl;
    auto inputs = Helper::getComponent<arcade::components::GetInputsComponent>(*coreEntity)->inputs;
    for (auto input : inputs) {
        if (input == NEXT_GRAPHIC) {
            if (LOGS)
                std::cout << "[CORE][EVENT] \"NEXT_GRAPHIC\"" << std::endl;
            manager.nextGraphic();
        }
        if (input == NEXT_GAME) {
            if (LOGS)
                std::cout << "[CORE][EVENT] \"NEXT_GAME\"" << std::endl;
            updateEntities(manager.nextGame());
        }
        if (input == RESTART_GAME) {
            if (LOGS)
                std::cout << "[CORE][EVENT] \"RESTART_GAME\"" << std::endl;
            updateEntities(manager.restartGame());
        }
        if (input == LEAVE_GAME) {
            if (LOGS)
                std::cout << "[CORE][EVENT] \"LEAVE_GAME\"" << std::endl;
            updateEntities(manager.backToMenu());
        }
        if (input == EXIT_ARCADE) {
            if (LOGS)
                std::cout << "[CORE][EVENT] \"EXIT_ARCADE\"" << std::endl;
            Helper::getComponent<arcade::components::ExitComponent>(*coreEntity)->exit = true;
        }
    }
}

void Core::updateEntities(std::list<std::shared_ptr<arcade::ecs::IEntity>> entities)
{
    Entities = entities;
    Entities.push_back(coreEntity);
}

bool Core::isRunning(void) const
{
    return !Helper::getComponent<arcade::components::ExitComponent>(*coreEntity)->exit;
}
