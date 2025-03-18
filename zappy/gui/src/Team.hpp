/*
** EPITECH PROJECT, 2023
** team
** File description:
** zappy
*/

#ifndef _TEAM_
#define _TEAM_

#include <random>
#include <SDL2/SDL_ttf.h>
#include <iostream>

class Team {
    public:
        Team(std::string teamName, SDL_Renderer *renderer, int index);
        ~Team();

        void update();
        SDL_Color getColor();
        bool isTeam(std::string name);
        void victory();
        int getIndex();
    private:
    int _index;
    std::string _teamName;
    SDL_Color _teamColor;
    SDL_Renderer *_renderer;
    SDL_Texture *_texte;
    SDL_Rect _texteRect;
};

#endif /* !_TEAM_ */
