/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** Client
*/

#include "Client.hpp"

Client::Client(int port, std::string machine)
: _port(port), _machine(machine) {}

void Client::createSocket(void)
{
    IPaddress serverIP;

    if (SDLNet_Init() < 0)
        throw(std::invalid_argument("SDL2_Init() failed"));
    if (SDLNet_ResolveHost(&serverIP, _machine.c_str(), _port) == -1)
        throw(std::invalid_argument("SDL2_ResolveHost() failed"));
    _socket = SDLNet_TCP_Open(&serverIP);
    if (!_socket)
        throw(std::invalid_argument("SDLNet_TCP_Open() failed"));
    _socketSet = SDLNet_AllocSocketSet(1);
    if (!_socketSet)
        throw(std::invalid_argument("SDLNet_AllocSocketSet() failed"));
    if (SDLNet_TCP_AddSocket(_socketSet, _socket) == -1)
        throw(std::invalid_argument("SDLNet_TCP_AddSocket() failed"));
}

void Client::destroySocket(void)
{
    SDLNet_TCP_Close(_socket);
    SDLNet_FreeSocketSet(_socketSet);
    SDLNet_Quit();
}

TCPsocket Client::getSocket(void)
{
    return _socket;
}

SDLNet_SocketSet Client::getSocketSet(void)
{
    return _socketSet;
}
