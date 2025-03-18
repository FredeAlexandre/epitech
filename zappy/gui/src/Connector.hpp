/*
** EPITECH PROJECT, 2023
** Connector
** File description:
** zappy
*/

#ifndef _CONNECTOR_
#define _CONNECTOR_

#include <iostream>
#include <list>
#include <sstream>

#include <SDL2/SDL_net.h>

class Connector {
    public:
        Connector(TCPsocket socket, SDLNet_SocketSet socketSet) : _socket(socket), _socketSet(socketSet) {};

        void getMapSize();
        void getTileContent(int x, int y);
        void getAllTileContent();
        void getTeamName();
        void getPlayerPosition(int playerId);
        void getPlayerLevel(int playerId);
        void getPlayerInventory(int playerId);
        void getTimeUnit();
        void setTimUnit(int timeUnit);

        void send(std::string prompt);

    private:
        TCPsocket _socket;
        SDLNet_SocketSet _socketSet;
};

#endif /* !_CONNECTOR_ */
