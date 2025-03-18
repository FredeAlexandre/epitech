/*
** EPITECH PROJECT, 2023
** map
** File description:
** zappy
*/

#ifndef _MAP_
#define _MAP_
    #include "Connector.hpp"
    #include <SDL2/SDL.h>

class Map {
    public:
        Map(Connector *connector, SDL_Renderer *renderer);
        ~Map();

        void update();
        std::list<int> getTileSize();
        void setMapSize(std::pair<int, int> size);
    private:
        SDL_Renderer *_renderer;
        SDL_Texture *_grass;
        SDL_Texture *_background;
        SDL_Texture *_dirt;
        Connector *_connector;
        int _width;
        int _height;
        int _widthTile;
        int _heightTile;
        int _xStart;
        int _yStart;
};

#endif /* !_MAP_ */
