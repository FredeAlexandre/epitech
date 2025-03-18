/*
** EPITECH PROJECT, 2023
** Map
** File description:
** zappy
*/

#include "Map.hpp"


Map::Map(Connector *connector, SDL_Renderer *renderer): _connector(connector), _renderer(renderer)
{
    _width = 10;
    _height = 10;
    SDL_Surface* background = SDL_LoadBMP("gui/src/sprites/SpaceBackground.bmp");
    if (!background) {
        std::cerr << "Failed to load sprite sheet: " << SDL_GetError() << std::endl;
        return;
    }
    SDL_Surface* grass = SDL_LoadBMP("gui/src/sprites/GrassTile.bmp");
    if (!grass) {
        std::cerr << "Failed to load sprite sheet: " << SDL_GetError() << std::endl;
        return;
    }
    SDL_Surface* dirt = SDL_LoadBMP("gui/src/sprites/DirtTile.bmp");
    if (!dirt) {
        std::cerr << "Failed to load sprite sheet: " << SDL_GetError() << std::endl;
        return;
    }
    _background = SDL_CreateTextureFromSurface(renderer, background);
    _grass = SDL_CreateTextureFromSurface(renderer, grass);
    _dirt = SDL_CreateTextureFromSurface(renderer, dirt);
    SDL_FreeSurface(background);
    SDL_FreeSurface(grass);
    SDL_FreeSurface(dirt);
    _xStart = (1920 - 750) / 2;
    _yStart = (1080 - 750) / 2;
    _widthTile = 750 / _width;
    _heightTile = 750 / _height;
}

Map::~Map()
{
    if (_background)
        SDL_DestroyTexture(_background);
    if (_grass)
        SDL_DestroyTexture(_grass);
    if (_dirt)
        SDL_DestroyTexture(_dirt);
}

void Map::setMapSize(std::pair<int, int> size)
{
    _width = size.first;
    _height = size.second;
}

void Map::update()
{
    SDL_Rect backgroundRect = {0, 0, 1920, 1080};
    SDL_Rect grassRect = {_xStart, _yStart, _widthTile, _heightTile};

    SDL_RenderCopy(_renderer, _background, NULL, &backgroundRect);
    for (int x = 0; x < _width; x++) {
        for (int y = 0; y < _height; y++) {
            grassRect.x = _xStart + (_heightTile * x);
            grassRect.y = _yStart + (_widthTile * y);
            SDL_RenderCopy(_renderer, _grass, NULL, &grassRect);
        }
    }
    SDL_Rect dirtRect = {_xStart, _yStart + (_widthTile * _height), _widthTile, _heightTile / 3};
    for (int y = 0; y < _height; y++) {
        dirtRect.x = _xStart + (_widthTile * y);
        SDL_RenderCopy(_renderer, _dirt, NULL, &dirtRect);
    }
}

std::list<int> Map::getTileSize()
{
    std::list<int> tileSize;
    tileSize.push_back(_heightTile);
    tileSize.push_front(_widthTile);
    return tileSize;
}
