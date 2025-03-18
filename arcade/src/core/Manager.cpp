/*
** EPITECH PROJECT, 2022
** arcade.hpp
** File description:
** The common layer of the Arcade project
*/

#include <memory>
#include <filesystem>

#include "manager.hpp"

Manager::Manager()
{
    Menu = new GameLoader("Menu", "./lib/arcade_menu.so");

    for (const auto& entry : std::filesystem::directory_iterator(LIB_FOLDER)) {
        if (!entry.is_regular_file()) continue;
        std::string name = entry.path().filename().string();
        if (fileLoaders.find(name) == fileLoaders.end()) continue;
        LibType type = fileLoaders.at(name);
        if (type == Graphic) {
            if (LOGS)
                std::cout << "[MANAGER] Loading graphic: " << name << std::endl;
            Graphics.push_back(new GraphicLoader(name, entry.path().string()));
        }
        if (type == Game) {
            if (LOGS)
                std::cout << "[MANAGER] Loading game: " << name << std::endl;
            Games.push_back(new GameLoader(name, entry.path().string()));
        }
    }
}

Manager::~Manager()
{
    for (auto &game : Games) {
        delete game;
    }
    for (auto &graphic : Graphics) {
        delete graphic;
    }
    delete Menu;
}

std::list<std::shared_ptr<arcade::ecs::IEntity>> Manager::startGame(void)
{
    arcade::IGame *game;
    if (isMenu) {
        game = Menu;
    } else {
        game = getGame();
    }
    auto entities = game->init();
    arcade::WindowSize size = game->getWindowSize();
    GraphicStartData = { size.width, size.height };
    return entities;
}

void Manager::startGraphic(void)
{
    auto graphic = getGraphic();
    getGraphic()->init(GraphicStartData);
}

std::list<std::shared_ptr<arcade::ecs::IEntity>> Manager::nextGame(void)
{
    if (LOGS)
        std::cout << std::endl << std::endl << std::endl << std::endl;
    if (isMenu) {
        isMenu = false;
        return startGame();
    }
    getGame()->reload();
    GameIndex = (GameIndex + 1) % Games.size();
    return startGame();
}

void Manager::prevGame(void)
{
    getGame()->reload();
    GameIndex = (GameIndex - 1) % Games.size();
    startGame();
}

std::list<std::shared_ptr<arcade::ecs::IEntity>> Manager::restartGame(void)
{
    getGame()->reload();
    return startGame();
}

void Manager::nextGraphic(void)
{
    getGraphic()->reload();
    GraphicIndex = (GraphicIndex + 1) % Graphics.size();
    startGraphic();
}

void Manager::prevGraphic(void)
{
    getGraphic()->reload();
    GraphicIndex = (GraphicIndex - 1) % Graphics.size();
    startGraphic();
}

std::list<std::shared_ptr<arcade::ecs::IEntity>> Manager::backToMenu(void)
{
    getGame()->reload();
    isMenu = true;
    return startGame();
}

Manager::FrameResult Manager::frame(std::list<std::shared_ptr<arcade::ecs::IEntity>> &entities)
{
    if (isMenu) {
        if (LOGS)
            std::cout << "[MANAGER] Frame Update Menu" << std::endl;
        if (actualScore > 0) {
            if (LOGS)
                std::cout << "[MANAGER] Actual Score: " << actualScore << std::endl;
            for (auto entity : entities) {
                auto scoreComp = Helper::getComponent<arcade::components::ScoreComponent>(*entity);
                if (scoreComp) {
                    if (LOGS)
                        std::cout << "[MANAGER] Score component FOUND !!!!" << std::endl;
                    scoreComp->score += actualScore;
                }
            }
            actualScore = 0;
        }
        Menu->update(entities);
        for (auto entity : entities) {
            auto endComp = Helper::getComponent<arcade::components::EndComponent>(*entity);
            if (endComp && endComp->end) {
                return Manager::FrameResult::Enter;
            }
        }
    } else {
        if (LOGS)
            std::cout << "[MANAGER] Frame Update Game" << std::endl;
        getGame()->update(entities);
        int score = 0;
        for (auto entity : entities) {
            auto scoreComp = Helper::getComponent<arcade::components::ScoreComponent>(*entity);
            if (scoreComp) {
                score += scoreComp->score;
            }
        }
        actualScore = score;
        if (LOGS)
            std::cout << "[MANAGER] Score: " << score << std::endl;
        for (auto entity : entities) {
            auto endComp = Helper::getComponent<arcade::components::EndComponent>(*entity);
            if (endComp && endComp->end) {
                return Manager::FrameResult::Return;
            }
        }
    }
    if (LOGS)
        std::cout << "[MANAGER] Frame Update Graphic" << std::endl;
    getGraphic()->update(entities);
    return Manager::FrameResult::Continue;
}
