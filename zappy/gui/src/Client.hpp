/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** Client
*/

#ifndef CLIENT_HPP_
    #define CLIENT_HPP_

    #include <SDL2/SDL_net.h>
    #include <iostream>
    #include <sys/socket.h>
    #include <arpa/inet.h>
    #include <unistd.h>
    #include <string.h>

class Client {
    public:
        Client() = default;
        Client(int port, std::string machine);
        ~Client() = default;
        TCPsocket getSocket(void);
        SDLNet_SocketSet getSocketSet(void);
        void createSocket(void);
        void destroySocket(void);

    private:
        int _port;
        std::string _machine;
        TCPsocket _socket;
        SDLNet_SocketSet _socketSet = SDLNet_AllocSocketSet(1);
};

#endif /* !CLIENT_HPP_ */
