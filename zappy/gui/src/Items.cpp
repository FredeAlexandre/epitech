/*
** EPITECH PROJECT, 2023
** items
** File description:
** zappy
*/

#include "Items.hpp"

Items::Items(Connector *connector, SDL_Renderer *renderer)
{
    _connector = connector;
    _renderer = renderer;
    _mapSize = {10, 10};
    _xStart = (1920 - 750) / 2;
    _yStart = (1080 - 750) / 2;
    _widthTile = 750 / _mapSize.first;
    _heightTile = 750 / _mapSize.second;
    _itemSize.first = _widthTile / 3;
    _itemSize.second = _heightTile / 3;
    SDL_Surface* stone = SDL_LoadBMP("gui/src/sprites/Gem_Collection.bmp");
    if (!stone) {
        std::cerr << "Failed to load sprite sheet: " << SDL_GetError() << std::endl;
        return;
    }
    SDL_Surface* beef = SDL_LoadBMP("gui/src/sprites/beef.bmp");
    if (!beef) {
        std::cerr << "Failed to load sprite sheet: " << SDL_GetError() << std::endl;
        return;
    }
    _beef = SDL_CreateTextureFromSurface(renderer, beef);
    SDL_FreeSurface(beef);
    _stones = SDL_CreateTextureFromSurface(renderer, stone);
    SDL_FreeSurface(stone);
}

Items::~Items()
{
    if (_beef)
        SDL_DestroyTexture(_beef);
    if (_stones)
        SDL_DestroyTexture(_stones);
}

void Items::setMapSize(std::pair<int, int> size)
{
    _mapSize = size;
}
void Items::setTile(int x, int y, int q0, int q1, int q2, int q3, int q4, int q5, int q6)
{
    std::list<int> content = {q0, q1, q2, q3, q4, q5, q6};
    _tilesContent[{x, y}] = content;
}

void Items::update()
{
    _connector->getAllTileContent();
    for (int x = 0; x < _mapSize.first; x++) {
        for (int y = 0; y < _mapSize.second; y++) {
            int xPixel = _xStart + x * _widthTile;
            int yPixel = _yStart + y * _heightTile;
            std::list<int> tile = _tilesContent.at({x,y});
            if (tile.front() != 0) {
                SDL_Rect destRect = {xPixel + _itemSize.first, yPixel + (2 * _itemSize.second), _itemSize.first, _itemSize.second};
                SDL_RenderCopy(_renderer, _beef, NULL, &destRect);
            }
            tile.pop_front();
            for (int i = 0; tile.size() != 0; i++) {
                if (tile.front() != 0) {
                    SDL_Rect srcRect = {0, i * 533, 457, 533};
                    int multiplierY = 0;
                    int multiplierX = i;
                    if (i > 2) {
                        multiplierY = 1;
                        multiplierX = i - 3;
                    }
                    SDL_Rect destRect = {xPixel + (multiplierX * _itemSize.first), yPixel + multiplierY * _itemSize.second, _itemSize.first, _itemSize.second};
                    SDL_RenderCopy(_renderer, _stones, &srcRect, &destRect);
                }
                tile.pop_front();
            }
        }
    }
}