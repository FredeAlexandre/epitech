/*
** EPITECH PROJECT, 2023
** egg
** File description:
** zappy
*/

#include "Egg.hpp"

Egg::Egg(int index, SDL_Renderer *renderer, int x, int y, Map *map, Team *team)
{
    _index = index;
    _renderer = renderer;
    SDL_Surface* egg = SDL_LoadBMP("gui/src/sprites/TrantorEgg.bmp");
    if (!egg) {
        std::cerr << "Failed to load sprite sheet: " << SDL_GetError() << std::endl;
        return;
    }
    _egg = SDL_CreateTextureFromSurface(_renderer, egg);
    SDL_FreeSurface(egg);
    SDL_SetTextureColorMod(_egg, team->getColor().r, team->getColor().g, team->getColor().b);
    _tileSize = map->getTileSize();
    int _xStart = (1920 - 750) / 2;
    int _yStart = (1080 - 750) / 2;
    _position.push_front(_xStart + (x * _tileSize.front()));
    _position.push_back(_yStart + (y * _tileSize.back()));
}

Egg::~Egg()
{
    if (_egg)
        SDL_DestroyTexture(_egg);
}

void Egg::update()
{
    SDL_Rect egg = {_position.front() + _tileSize.front() / 4, _position.back() + _tileSize.back() / 2, _tileSize.front() / 2, _tileSize.back() / 2};
    SDL_RenderCopy(_renderer, _egg, NULL, &egg);
}

int Egg::getIndex()
{
    return _index;
}
