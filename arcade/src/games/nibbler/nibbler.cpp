/*
** EPITECH PROJECT, 2023
** nibbler
** File description:
** arcade
*/
#include "nibbler.hpp"

GameNibbler::GameNibbler()
{
    nibbler = std::make_shared<NibblerEntity>();
    score = 0;
}

GameNibbler::~GameNibbler()
{
}

void GameNibbler::exit(std::list<std::shared_ptr<arcade::ecs::IEntity>> &entities)
{
    endComponent->end = true;
}

//this functions searches for apples located at the same place as the head, and removes it from the entities list
void GameNibbler::EatApple(std::list<std::shared_ptr<arcade::ecs::IEntity>> &entities)
{
    auto snakePosComp =  Helper::getComponent<arcade::components::PositionComponent>(*nibbler.get()->getParts().back().get());
    std::shared_ptr<arcade::components::PositionComponent> applePosComp = nullptr;

    float x = snakePosComp.get()->x;
    float y = snakePosComp.get()->y;

    for (auto it = entities.begin(); it != entities.end(); ++it) {
        if (it->get()->getId() != "apple")
            continue;
        applePosComp = Helper::getComponent<arcade::components::PositionComponent>(*it->get());
        if (LOGS)
            std::cout << "applePos:" << applePosComp.get()->x << ", " << applePosComp.get()->y << std::endl;
        if (applePosComp.get()->x != x ||applePosComp.get()->y != y)
            continue;
        if (LOGS)    
            std::cout << "eating" << std::endl;
        nibbler.get()->AddPart(entities);
        //ugly deletion, need to look at this properly later
        it->get()->getId() = "deadApple";
        applePosComp.get()->x = 10000;
        applePosComp.get()->x = 10000;
    }
}

void GameNibbler::update(std::list<std::shared_ptr<arcade::ecs::IEntity>> &entities)
{
    bool wait = false;
    int wait_value = 50 - scoreComponent->score;

    _entities = entities;
    nibbler->checkDirection();
    wait = nibbler->checkSurroundings(entities);
    if (nibbler->spacePress() == true) wait_value = wait_value - 10;
    if (clockComponent->duration + last_time < wait_value) {
        last_time += clockComponent->duration;
        return;
    }
    last_time = 0;
    scoreComponent->score = nibbler->getScore();
    textSprite->value = std::to_string(scoreComponent->score);
    if (_isAlive == false) {
        exit(entities);
        return;
    }
    nibbler->checkCollision();
    if (!wait)
        nibbler->move();
    EatApple(entities);
    if (checkAllApples())
        exit(entities);
    _isAlive = nibbler->isAlive();
}

std::list<std::shared_ptr<arcade::ecs::IEntity>> GameNibbler::init()
{
    auto end = std::make_shared<BasicEntity>("end");
    endComponent = Helper::addComponent<arcade::components::EndComponent>(*end);
    _entities.push_front(end);
    auto score = std::make_shared<BasicEntity>("score");
    scoreComponent = Helper::addComponent<arcade::components::ScoreComponent>(*score);
    _entities.push_front(score);
    auto clock = std::make_shared<BasicEntity>("clock");
    clockComponent = Helper::addComponent<arcade::components::ClockComponent>(*clock);
    _entities.push_front(clock);
    
    //background
    auto background = std::make_shared<BasicEntity>("background");
    auto posBackground = Helper::addComponent<arcade::components::PositionComponent>(*background);
    posBackground->x = 0;
    posBackground->y = 0;
    posBackground->z = 0;
    posBackground->rotation = 0;
    auto spriteBackground =  Helper::addComponent<arcade::components::SpriteSheetComponent>(*background);
    spriteBackground->source = SPRITE_SOURCE "background.jpg";
    auto sizeBackground = Helper::addComponent<arcade::components::SizeComponent>(*background);
    sizeBackground->width = 1920;
    sizeBackground->height = 1080;
    auto spriteComponentBackground = Helper::addComponent<arcade::components::SpriteComponent>(*background);
    spriteComponentBackground->width = 509;
    spriteComponentBackground->height = 339;
    spriteComponentBackground->x = 0;
    spriteComponentBackground->y = 0;
    spriteComponentBackground->color = arcade::enums::Color::Green;
    _entities.push_front(background);

    //backgroundblack
    auto backgroundBlack = std::make_shared<BasicEntity>("backgroundBlack");
    auto posBackgroundBlack = Helper::addComponent<arcade::components::PositionComponent>(*backgroundBlack);
    posBackgroundBlack->x = 780;
    posBackgroundBlack->y = 360;
    posBackgroundBlack->z = 0;
    posBackgroundBlack->rotation = 0;
    auto spriteBackgroundBlack = Helper::addComponent<arcade::components::SpriteSheetComponent>(*backgroundBlack);
    spriteBackgroundBlack->source = SPRITE_SOURCE "blackScreen.jpg";
    auto sizeBackgroundBlack = Helper::addComponent<arcade::components::SizeComponent>(*backgroundBlack);
    sizeBackgroundBlack->width = 360;
    sizeBackgroundBlack->height = 360;
    auto spriteComponentBackgroundBlack = Helper::addComponent<arcade::components::SpriteComponent>(*backgroundBlack);
    spriteComponentBackgroundBlack->width = 1500;
    spriteComponentBackgroundBlack->height = 660;
    spriteComponentBackgroundBlack->x = 0;
    spriteComponentBackgroundBlack->y = 0;
    spriteComponentBackgroundBlack->color = arcade::enums::Color::Black;
    _entities.push_front(backgroundBlack);

    //text
    auto textEntity = std::make_shared<BasicEntity>("texte");
    textSprite = Helper::addComponent<arcade::components::TextComponent>(*textEntity);
    textSprite->value = std::to_string(scoreComponent-> score);
    textSprite->horizontalPosition = arcade::components::TextComponent::End;
    textSprite->verticalPosition = arcade::components::TextComponent::Start;
    textSprite->size = 50;
    _entities.push_front(textEntity);

    //level
    auto level = Level(780, 360, 30);
    level.MakeLayout();
    level.spawnMap(_entities);

    //nibbler
    _entities.push_front(nibbler);
    std::list<std::shared_ptr<NibblerParts>>::iterator it;
    for (it = nibbler->getEntities().begin(); it != nibbler->getEntities().end(); it++) {
        _entities.push_front(*it);
    }
    return _entities;
}

//returns true if all apples in the entities list have been consumed
//returns false otherwise
bool GameNibbler::checkAllApples()
{
    for (auto it = _entities.begin(); it != _entities.end(); ++it) {
        if (it->get()->getId() == "apple")
            return false;
    }
    return true;
}
