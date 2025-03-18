/*
** EPITECH PROJECT, 2023
** team
** File description:
** zappy
*/

#include "Team.hpp"

Team::Team(std::string teamName, SDL_Renderer *renderer, int index)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, 255);
    _renderer = renderer;
    _teamColor.a = 255;
    _teamColor.r = dist(gen);
    _teamColor.g = dist(gen);
    _teamColor.b = dist(gen);
    _index = index;
    _teamName = teamName;
    SDL_Surface *surface;
    TTF_Font *Font;
    Font = TTF_OpenFont("gui/src/sprites/PoliceGame.TTF", 25);
    if (Font == NULL) throw std::runtime_error("Font not found");
    if ((surface = TTF_RenderText_Solid(Font, teamName.c_str(), _teamColor)) == NULL) return;
    if ((_texte = SDL_CreateTextureFromSurface(_renderer, surface)) == NULL) return;
    int texteX = 1920 - surface->w - 25;
    int texteY = 10 * (index + 1) + index * surface->h;
    _texteRect.x = texteX;
    _texteRect.y = texteY;
    _texteRect.w = surface->w;
    _texteRect.h = surface->h;
}

Team::~Team()
{
}

SDL_Color Team::getColor()
{
    return _teamColor;
}

void Team::update()
{
    SDL_RenderCopy(_renderer, _texte, NULL, &_texteRect);
}

bool Team::isTeam(std::string name)
{
    if (name.compare(_teamName) == 0) return true;
    return false;
}

void Team::victory()
{
    SDL_Surface *surface;
    TTF_Font *Font;
    Font = TTF_OpenFont("gui/src/sprites/PoliceGame.TTF", 75);
    if (Font == NULL) throw std::runtime_error("Font not found for victory");
    std::string victoryTexte = "Victory: ";
    victoryTexte.append(_teamName);
    if ((surface = TTF_RenderText_Solid(Font, victoryTexte.c_str(), _teamColor)) == NULL) return;
    if ((_texte = SDL_CreateTextureFromSurface(_renderer, surface)) == NULL) return;
    int texteX = 1920 / 2 - surface->w / 2;
    int texteY = 1080 / 2 - surface->h / 2;
    _texteRect.x = texteX;
    _texteRect.y = texteY;
    _texteRect.w = surface->w;
    _texteRect.h = surface->h;
    SDL_RenderCopy(_renderer, _texte, NULL, &_texteRect);
}

int Team::getIndex()
{
    return _index;
}