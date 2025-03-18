/*
** EPITECH PROJECT, 2023
** snake
** File description:
** arcade
*/
#include "snake.hpp"

GameSnake::GameSnake()
{
    snake = std::make_shared<SnakeEntity>();
    Helper::addComponent<arcade::components::EndComponent>(*snake);
}

GameSnake::~GameSnake()
{
}

void GameSnake::exit(std::list<std::shared_ptr<arcade::ecs::IEntity>> &entities)
{
    endComponent->end = true;
}

void GameSnake::update(std::list<std::shared_ptr<arcade::ecs::IEntity>> &entities)
{
    int wait_value = 50 - scoreComponent->score;
    snake->checkDirection();
    if (snake->spacePress() == true) wait_value = wait_value - 10;
    if (clockComponent->duration + last_time < wait_value) {
        last_time += clockComponent->duration;
        return;
    }
    last_time = 0;
    scoreComponent->score = snake->getScore();
    textSprite->value = std::to_string(scoreComponent->score);
    if (_isAlive == false) {
        exit(entities);
        return;
    }
    snake->checkCollision();
    snake->move();

    if (snake->checkEatApple((posAppleSprite->x - 210) / 30, (posAppleSprite->y - 210) / 30, entities) == 1) randomiseApple();
    _isAlive = snake->isAlive();
}

std::list<std::shared_ptr<arcade::ecs::IEntity>> GameSnake::init()
{
    auto end = std::make_shared<BasicEntity>("end");
    endComponent = Helper::addComponent<arcade::components::EndComponent>(*end);
    entities.push_front(end);
    auto score = std::make_shared<BasicEntity>("score");
    scoreComponent = Helper::addComponent<arcade::components::ScoreComponent>(*score);
    entities.push_front(score);
    auto clock = std::make_shared<BasicEntity>("clock");
    clockComponent = Helper::addComponent<arcade::components::ClockComponent>(*clock);
    entities.push_front(clock);

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
    entities.push_front(background);

    auto backgroundBlack = std::make_shared<BasicEntity>("backgroundBlack");
    auto posBackgroundBlack = Helper::addComponent<arcade::components::PositionComponent>(*backgroundBlack);
    posBackgroundBlack->x = 210;
    posBackgroundBlack->y = 210;
    posBackgroundBlack->z = 0;
    posBackgroundBlack->rotation = 0;
    auto spriteBackgroundBlack = Helper::addComponent<arcade::components::SpriteSheetComponent>(*backgroundBlack);
    spriteBackgroundBlack->source = SPRITE_SOURCE "blackScreen.jpg";
    auto sizeBackgroundBlack = Helper::addComponent<arcade::components::SizeComponent>(*backgroundBlack);
    sizeBackgroundBlack->width = 1500;
    sizeBackgroundBlack->height = 660;
    auto spriteComponentBackgroundBlack = Helper::addComponent<arcade::components::SpriteComponent>(*backgroundBlack);
    spriteComponentBackgroundBlack->width = 1500;
    spriteComponentBackgroundBlack->height = 660;
    spriteComponentBackgroundBlack->x = 0;
    spriteComponentBackgroundBlack->y = 0;
    spriteComponentBackgroundBlack->color = arcade::enums::Color::Black;
    entities.push_front(backgroundBlack);

    auto textEntity = std::make_shared<BasicEntity>("texte");
    textSprite = Helper::addComponent<arcade::components::TextComponent>(*textEntity);
    textSprite->value = std::to_string(scoreComponent->score);
    textSprite->horizontalPosition = arcade::components::TextComponent::End;
    textSprite->verticalPosition = arcade::components::TextComponent::Start;
    textSprite->size = 50;
    entities.push_front(textEntity);

    AppleSprite = std::make_shared<BasicEntity>("apple");
    posAppleSprite = Helper::addComponent<arcade::components::PositionComponent>(*AppleSprite);
    randomiseApple();
    auto spriteApple = Helper::addComponent<arcade::components::SpriteSheetComponent>(*AppleSprite);
    spriteApple->source = SPRITE_SOURCE "apple.png";
    auto sizeApple = Helper::addComponent<arcade::components::SizeComponent>(*AppleSprite);
    sizeApple->width = 30;
    sizeApple->height = 30;
    auto spriteComponentApple = Helper::addComponent<arcade::components::SpriteComponent>(*AppleSprite);
    spriteComponentApple->width = 600;
    spriteComponentApple->height = 600;
    spriteComponentApple->x = 0;
    spriteComponentApple->y = 0;
    spriteComponentApple->color = arcade::enums::Color::Red;
    entities.push_front(AppleSprite);

    entities.push_front(snake);
    std::list<std::shared_ptr<SnakeParts>>::iterator it;
    for (it = snake->getEntities().begin(); it != snake->getEntities().end(); it++) {
        entities.push_front(*it);
    }
    return entities;
}

void GameSnake::randomiseApple()
{
    srand(time(0));
    posAppleSprite->x = 210 + 30 * (rand() % 49);
    posAppleSprite->y = 210 + 30 * (rand() % 21);
    posAppleSprite->z = 0;
    posAppleSprite->rotation = 0;
}