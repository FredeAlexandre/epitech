/*
** EPITECH PROJECT, 2023
** Zappy [WSL: Ubuntu]
** File description:
** Core
*/

#pragma once

#include "Client.hpp"
#include <SDL2/SDL.h>
#include "Connector.hpp"
#include "Items.hpp"
#include "Trantor.hpp"
#include "Egg.hpp"

#define BUFFER_SIZE 1024

class Core {
    public:
        Core(int argc, char **argv);

        ~Core();
        void setMachine(int argc, char **argv);
        void setPort(int argc, char **argv);

        void initialize(void);
        void initializeGraphic(void);
        void initializeNet(void);
        void initializeGame(void);

        void loop(void);

        void loopGraphic(void);
        void loopNet(void);
        void loopGame(void);

        void handleMessage(std::string message);

        void updateTrantors(void);
        void updateEggs(void);
        void updateTeams(void);

        void msz(int x, int y);
        void bct(int x, int y, int q0, int q1, int q2, int q3, int q4, int q5, int q6);
        void tna(std::string teamName);
        void pnw(int id, int x, int y, int orientation, int level, std::string teamName);
        void ppo(int id, int x, int y, int orientation);
        void plv(int id, int level);
        void pin(int id, int x, int y, int q0, int q1, int q2, int q3, int q4, int q5, int q6);
        void pex(int id);
        void pbc(int id, std::string message);
        void pic(int x, int y, int level, std::list<int> players);
        void pie(int x, int y, bool result);
        void pfk(int id);
        void pdr(int id, int resource);
        void pgt(int id, int resource);
        void pdi(int id);
        void enw(int egg, int player, int x, int y);
        void ebo(int egg);
        void edi(int egg);
        void sgt(int timeUnit);
        void sst(int timeUnit);
        void seg(std::string teamName);
        void smg(std::string message);
        void suc(void);
        void sbp(void);

        size_t split(const std::string &txt, std::vector<std::string> &strs, char ch);
        int safeStoi(std::string str);

    private:
        int _port = 0;
        std::string _machine = "localhost";

        TCPsocket _socket = nullptr;
        SDLNet_SocketSet _socketSet = nullptr;

        SDL_Renderer *_renderer = nullptr;
        SDL_Window *_window = nullptr;

        bool _running = true;

        std::list<Trantor *> _trantors;
        std::list<Egg *> _eggs;
        Map *_map = nullptr;
        Items *_items = nullptr;
        Connector *_connector = nullptr;
        std::list<Team *> _teams;
};
