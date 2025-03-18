/*
** EPITECH PROJECT, 2022
** arcade
** File description:
** The common layer of the Arcade project
*/

#include "ncurse.hpp"
#include "unistd.h"

#include <iostream>

extern "C" {
    arcade::IGraphic *getGraphic(void)
    {
        return new Ncurse();
    }

    void destroyGraphic(arcade::IGraphic *graphic)
    {
        delete graphic;
    }
};

Ncurse::Ncurse()
{
};

Ncurse::~Ncurse()
{
    nocbreak();
    endwin();
};

void Ncurse::init(arcade::GraphicInit value)
{
    initscr();
    start_color();
    clear();
    noecho();
    cbreak();
    nodelay(stdscr, true);
    keypad(stdscr, TRUE);

    getmaxyx(stdscr, rows, cols);

    pixelPerColumns = _value.width / cols;
    pixelPerLines = _value.height / rows;
    _value = value;
}

void Ncurse::printRectangle(int x, int y, int height, int width, int color)
{
    int startX = x / pixelPerColumns;
    int startY = y / pixelPerLines;
    int endX = (x + width) / pixelPerColumns;
    int endY = (y + height) / pixelPerLines;

    int cells = (endX - startX) * (endY - startY);

    init_pair(color, color, color);

    attron(COLOR_PAIR(color));
    if (cells > 1) {
        for(int a = startX; a <= endX; a++) {
            for(int b = startY; b <= endY; b++) {
                mvprintw(b, a, " ");
            }
        }
    } else {
        mvprintw(startY, startX, " ");
    }
    refresh();
    attroff(COLOR_PAIR(color));
}

void Ncurse::DrawText(std::shared_ptr<arcade::components::TextComponent> &component)
{
    int startX;
    int startY;
    if (component->horizontalPosition == arcade::components::TextComponent::Start) {
        startX = 0;
    } else if (component->horizontalPosition == arcade::components::TextComponent::Center) {
        startX = (cols / 2) - (component->value.size() / 2);
    } else if (component->horizontalPosition == arcade::components::TextComponent::End) {
        startX = cols - component->value.size();
    }

    if (component->verticalPosition == arcade::components::TextComponent::Start) {
        startY = 0;
    } else if (component->verticalPosition == arcade::components::TextComponent::Center) {
        startY = (rows / 2);
    } else if (component->verticalPosition == arcade::components::TextComponent::End) {
        startY = rows;
    }

    init_pair(99, COLOR_WHITE, COLOR_BLACK);

    attron(COLOR_PAIR(99));
    mvprintw(startY, startX, component->value.c_str());
    refresh();
    attroff(COLOR_PAIR(99));
}

void Ncurse::DrawSprite(std::shared_ptr<arcade::components::SpriteComponent> &sprite, std::shared_ptr<arcade::components::SizeComponent> &size, std::shared_ptr<arcade::components::PositionComponent> &position)
{
    switch (sprite->color) {
        case arcade::enums::Color::Black:
            printRectangle(position->x, position->y, size->height, size->width, COLOR_BLACK);
            break;
        case arcade::enums::Color::Red:
            printRectangle(position->x, position->y, size->height, size->width, COLOR_RED);
            break;
        case arcade::enums::Color::Green:
            printRectangle(position->x, position->y, size->height, size->width, COLOR_GREEN);
            break;
        case arcade::enums::Color::Yellow:
            printRectangle(position->x, position->y, size->height, size->width, COLOR_YELLOW);
            break;
        case arcade::enums::Color::Blue:
            printRectangle(position->x, position->y, size->height, size->width, COLOR_BLUE);
            break;
        case arcade::enums::Color::Magenta:
            printRectangle(position->x, position->y, size->height, size->width, COLOR_MAGENTA);
            break;
        case arcade::enums::Color::Cyan:
            printRectangle(position->x, position->y, size->height, size->width, COLOR_CYAN);
            break;
        case arcade::enums::Color::White:
            printRectangle(position->x, position->y, size->height, size->width, COLOR_WHITE);
            break;
        default:
            break;
    }
}

void Ncurse::DrawEntity(std::shared_ptr<arcade::ecs::IEntity> entity)
{

    auto spriteTexte = Helper::getComponent<arcade::components::TextComponent>(*entity);

    if (spriteTexte) return DrawText(spriteTexte);

    auto spriteComponent = Helper::getComponent<arcade::components::SpriteComponent>(*entity);
    auto spriteSize = Helper::getComponent<arcade::components::SizeComponent>(*entity);
    auto spritePosition = Helper::getComponent<arcade::components::PositionComponent>(*entity);

    if (spriteSize && spritePosition && spriteComponent) return DrawSprite(spriteComponent, spriteSize, spritePosition);
}

void Ncurse::update(std::list<std::shared_ptr<arcade::ecs::IEntity>> &entities)
{
    std::list<std::shared_ptr<arcade::ecs::IEntity>>::reverse_iterator it;

    pixelPerColumns = _value.width / cols;
    pixelPerLines = _value.height / rows;
    clear();
    for (it = entities.rbegin(); it != entities.rend(); it++) {
        DrawEntity(*it);
    }

    std::list<arcade::enums::Input> inputs;

    int key = getch();

    while (key != ERR) {
        if (getKeyToInput.find(key) != getKeyToInput.end()) {
            inputs.push_back(getKeyToInput.at(key));
        }
        key = getch();
    }

    giveInputs(entities, inputs);
}

void Ncurse::giveInputs(std::list<std::shared_ptr<arcade::ecs::IEntity>> &entities, std::list<arcade::enums::Input> &keys)
{
    std::list<std::shared_ptr<arcade::ecs::IEntity>> tmp = entities;
    std::shared_ptr<arcade::components::GetInputsComponent> inputsComp;

    for (auto it = tmp.begin(); it != tmp.end(); it++) {
        inputsComp = Helper::getComponent<arcade::components::GetInputsComponent>(*(it->get()));
        if (inputsComp == nullptr) continue;
        inputsComp->inputs = keys;
    }
}
