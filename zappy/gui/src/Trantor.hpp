/*
** EPITECH PROJECT, 2023
** Trantor
** File description:
** zappy
*/

#ifndef _TRANTOR_
#define _TRANTOR_

#include "Animator.hpp"
#include "Connector.hpp"
#include "Team.hpp"

class Trantor {
    public:
        Trantor(int playerId, Connector *connector, std::list<int> tileSize, SDL_Renderer *renderer, Team *team);
        ~Trantor();

        void update();
        void isDead();
        void isIncantated();
        void isMoving();
        void dropRessource();
        void collectRessource();
        void checkPosition();
        void move();
        void endIncantated();
        void layingEgg();
        int getIndex();
        void broadcast();
        void turn(int orientation);
        std::string getTeamName();
        void setPlayerPosition(std::list<int> position);
    private:
        int _playerId;
        Animator *_animator;
        std::string _teamName;
        std::list<int> _position;
        std::list<int> _lastPosition;
        std::list<int> _pixelPosition;
        std::list<int> _lastPixelPosition;
        Connector *_connector;
        std::list<int> _tileSize;
        int _spriteSize;
        bool _moving;
        bool _broadcast;
        bool _isAlive;
        SDL_Texture *_megaphone;
        SDL_Renderer *_renderer;
        Team *_team;
};

#endif /* !_TRANTOR_ */
