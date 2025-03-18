/*
** EPITECH PROJECT, 2022
** arcade
** File description:
** The common layer of the Arcade project
*/
#include "sdl2.hpp"
#include "unistd.h"

#include <iostream>

extern "C" {
    arcade::IGraphic *getGraphic(void)
    {
        return new SDL2();
    }

    void destroyGraphic(arcade::IGraphic *graphic)
    {
        delete graphic;
    }
};

SDL2::SDL2()
{
};

SDL2::~SDL2()
{
    for (auto i : _TextureMap) {
        SDL_DestroyTexture(i.second);
    }
	SDL_DestroyRenderer(_renderer);
	SDL_DestroyWindow(_window);
    SDL_Quit();
    TTF_Quit();
};

void SDL2::init(arcade::GraphicInit value)
{
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
    _window = SDL_CreateWindow("Arcade", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, value.width, value.height, SDL_WINDOW_ALLOW_HIGHDPI);
    _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
    SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 0);
    _value = value;
}

void SDL2::DrawSprite(std::shared_ptr<arcade::ecs::IEntity> entity)
{
    SDL_Texture *texture;
    SDL_Rect texr;
    SDL_Color TextColor;
    SDL_Surface *surface;
    TTF_Font *Font;
    std::shared_ptr<arcade::components::SpriteSheetComponent> spriteSheet = Helper::getComponent<arcade::components::SpriteSheetComponent>(*entity);
    std::shared_ptr<arcade::components::SpriteComponent> spriteComponent = Helper::getComponent<arcade::components::SpriteComponent>(*entity);
    std::shared_ptr<arcade::components::SizeComponent> spriteSize = Helper::getComponent<arcade::components::SizeComponent>(*entity);
    std::shared_ptr<arcade::components::PositionComponent> spritePosition = Helper::getComponent<arcade::components::PositionComponent>(*entity);
    std::shared_ptr<arcade::components::TextComponent> spriteTexte = Helper::getComponent<arcade::components::TextComponent>(*entity);
    int sizeTexteX;
    int sizetexteY;
    int texteX;
    int texteY;

    if (spriteTexte != nullptr) {
        Font = TTF_OpenFont(FONT_SOURCE "PoliceGame.TTF", spriteTexte->size);
        TextColor.r = 255;
        TextColor.g = 255;
        TextColor.b = 255;
        if ((surface = TTF_RenderText_Solid(Font, spriteTexte->value.c_str(), TextColor)) == NULL) return;
        if ((texture = SDL_CreateTextureFromSurface(_renderer, surface)) == NULL) return;
        if (spriteTexte->horizontalPosition == arcade::components::TextComponent::Position::End) texteX = _value.width - surface->w - 25;
        if (spriteTexte->horizontalPosition == arcade::components::TextComponent::Position::Center) texteX = _value.width / 2 - surface->w / 2;
        if (spriteTexte->horizontalPosition == arcade::components::TextComponent::Position::Start) texteX = 25;
        if (spriteTexte->verticalPosition == arcade::components::TextComponent::Position::End) texteY = _value.height - surface->h - 10;
        if (spriteTexte->verticalPosition == arcade::components::TextComponent::Position::Center) texteY = (_value.height / 2) - (surface->h / 2);
        if (spriteTexte->verticalPosition == arcade::components::TextComponent::Position::Start) texteY = 10;
        texr.x = texteX;
        texr.y = texteY;
        texr.w = surface->w;
        texr.h = surface->h;
        SDL_RenderCopy(_renderer, texture, NULL, &texr);
        SDL_FreeSurface(surface);
        SDL_DestroyTexture(texture);
        TTF_CloseFont(Font);
        return;
    }
    if (spriteSheet == nullptr || spriteSize == nullptr || spritePosition == nullptr) {
        return;
    }
    std::map<std::string, SDL_Texture*>::iterator it = _TextureMap.find(spriteSheet->source);
    if (it == _TextureMap.end()) {
        texture = IMG_LoadTexture(_renderer, spriteSheet->source.c_str());
        _TextureMap[spriteSheet->source] = texture;
    } else {
        texture = _TextureMap[spriteSheet->source];
    }
    texr.x = spritePosition->x;
    texr.y = spritePosition->y;
    texr.w = spriteSize->width;
    texr.h = spriteSize->height;
    SDL_RenderCopyEx(_renderer, texture, NULL, &texr, spritePosition->rotation, NULL, SDL_FLIP_NONE);
}

void SDL2::exit(std::list<std::shared_ptr<arcade::ecs::IEntity>> &entities)
{
    std::list<std::shared_ptr<arcade::ecs::IEntity>>::iterator it;
    std::shared_ptr<arcade::components::ExitComponent> exitComp;

    for (it = entities.begin(); it != entities.end(); it++) {
        if ((exitComp = Helper::getComponent<arcade::components::ExitComponent>(*it->get())) != nullptr) {
            exitComp->exit = true;
        }
    }
}

void SDL2::update(std::list<std::shared_ptr<arcade::ecs::IEntity>> &entities)
{
    std::list<std::shared_ptr<arcade::ecs::IEntity>>::reverse_iterator it;
    SDL_Event event;

    std::list<arcade::enums::Input> inputs;

    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_KEYDOWN) {
            inputs.push_front(convertInput(event));
        }
        if (event.type == SDL_QUIT) {
            exit(entities);
        }
    }
    giveInputs(entities, inputs);
    SDL_RenderClear(_renderer);
    for (it = entities.rbegin(); it != entities.rend(); it++) {
        DrawSprite(*it);
    }
    SDL_RenderPresent(_renderer);
}

void SDL2::giveInputs(std::list<std::shared_ptr<arcade::ecs::IEntity>> &entities, std::list<arcade::enums::Input> &keys)
{
    std::list<std::shared_ptr<arcade::ecs::IEntity>> tmp = entities;
    std::shared_ptr<arcade::components::GetInputsComponent> inputsComp;

    for (auto it = tmp.begin(); it != tmp.end(); it++) {
        inputsComp = Helper::getComponent<arcade::components::GetInputsComponent>(*(it->get()));
        if (inputsComp == nullptr) continue;
        inputsComp->inputs = keys;
    }
}

arcade::enums::Input SDL2::convertInput(SDL_Event event)
{
    if (getKeyToInput.find(event.key.keysym.sym) == getKeyToInput.end()) return arcade::enums::Unknown;
    return getKeyToInput.at(event.key.keysym.sym);
}
