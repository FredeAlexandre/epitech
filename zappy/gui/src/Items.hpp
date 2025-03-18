/*
** EPITECH PROJECT, 2023
** Items
** File description:
** zappy
*/

#ifndef _ITEMS_
#define _ITEMS_
#include "Connector.hpp"
#include <SDL2/SDL.h>
#include <map>

class Items {
    public:
        Items(Connector *connector, SDL_Renderer *renderer);
        ~Items();

        void update();
        void setMapSize(std::pair<int, int> size);
        void setTile(int x, int y, int q0, int q1, int q2, int q3, int q4, int q5, int q6);
    private:
        std::pair<int, int> _mapSize;
        std::pair<int, int> _itemSize;
        std::map<std::pair<int, int>, std::list<int>> _tilesContent;
        int _xStart;
        int _yStart;
        int _widthTile;
        int _heightTile;
        Connector *_connector;
        SDL_Renderer *_renderer;
        SDL_Texture *_stones;
        SDL_Texture *_beef;
};

#endif /* !_ITEMS_ */
