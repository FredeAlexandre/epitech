/*
** EPITECH PROJECT, 2023
** connector
** File description:
** zappy
*/

#include "Connector.hpp"
#include <string>
#include <sstream>
#include <iostream>

void Connector::send(std::string prompt)
{
    int bytesSent = SDLNet_TCP_Send(_socket, (prompt + "\n").c_str(), prompt.length() + 1);
    if (bytesSent < (prompt.length() + 1)) {
        std::cerr << "SDLNet_TCP_Send() failed: " << SDLNet_GetError() << std::endl;
        throw std::runtime_error(SDLNet_GetError());
    }
}

void Connector::getMapSize()
{
    send("msz");
}

void Connector::getTileContent(int givedX, int givedY)
{
    std::string prompt = "bct " + std::to_string(givedX) + " " + std::to_string(givedY);
    send(prompt);
}

void Connector::getAllTileContent()
{
    send("mct");
}

void Connector::getTeamName()
{
    send("tna");
}

void Connector::getPlayerLevel(int playerId)
{
    send("plv " + std::to_string(playerId));
}

void Connector::getPlayerPosition(int playerId)
{
    send("ppo " + std::to_string(playerId));
}

void Connector::getPlayerInventory(int playerId)
{
    send("pin " + std::to_string(playerId));
}

void Connector::getTimeUnit()
{
    send("sgt");
}

void Connector::setTimUnit(int timeUnit)
{
    send("sst " + std::to_string(timeUnit));
}
