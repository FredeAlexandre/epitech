/*
** EPITECH PROJECT, 2023
** egg
** File description:
** zappy
*/

#ifndef _EGG_
#define _EGG_
#include "Map.hpp"
#include "Team.hpp"
class Egg {
    public:
        Egg(int index, SDL_Renderer *renderer, int x, int y, Map *map, Team *team);
        ~Egg();

        void update();
        int getIndex();
    private:
        int _index;
        std::list<int> _tileSize;
        SDL_Texture *_egg;
        SDL_Renderer *_renderer;
        std::list<int> _position;
};

#endif /* !_EGG_ */
