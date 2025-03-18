/*
** EPITECH PROJECT, 2023
** Zappy [WSL: Ubuntu]
** File description:
** Core
*/

#include <string.h>

#include "Core.hpp"

Core::Core(int argc, char **argv)
{
    setMachine(argc, argv);
    setPort(argc, argv);
}

Core::~Core()
{
    if (_renderer != nullptr) SDL_DestroyRenderer(_renderer);
    if (_window != nullptr) SDL_DestroyWindow(_window);
    SDL_Quit();

    if (_socket) SDLNet_TCP_Close(_socket);
    if (_socketSet) SDLNet_FreeSocketSet(_socketSet);
    SDLNet_Quit();

    if (_connector) delete  _connector;
    if (_map) delete _map;
    if (_items) delete _items;

    for (auto trantor : _trantors)
        delete trantor;
    
    for (auto egg : _eggs)
        delete egg;

    for (auto team : _teams)
        delete team;
}

void Core::setMachine(int argc, char **argv)
{
    for (int i = 0; i < argc; i++) {
        char *arg = argv[i];
        if (strcmp(arg, "-h") == 0) {
            if (i + 1 >= argc)
                throw(std::invalid_argument("The machine is missing"));
            _machine = argv[i + 1];
            return;
        }
    }
}

void Core::setPort(int argc, char **argv)
{
    for (int i = 0; i < argc; i++) {
        char *arg = argv[i];
        if (strcmp(arg, "-p") == 0) {
            if (i + 1 >= argc)
                throw(std::invalid_argument("The port is missing"));
            _port = atoi(argv[i + 1]);
            if (_port < 0)
                throw(std::invalid_argument("The port is invalid"));
            return;
        }
    }
}

void Core::initialize(void)
{
    initializeGraphic();
    initializeNet();
    initializeGame();
}

void Core::initializeGraphic(void)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        throw std::runtime_error(SDL_GetError());
    }

    if (TTF_Init() != 0) {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        throw std::runtime_error(SDL_GetError());
    }

    _window = SDL_CreateWindow("Zappy", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1920, 1080, SDL_WINDOW_SHOWN);
    if (_window == nullptr) {
        SDL_Log("Unable to create SDL window: %s", SDL_GetError());
        SDL_Quit();
        throw std::runtime_error(SDL_GetError());
    }

    _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
    if (_renderer == nullptr) {
        SDL_Log("Unable to create SDL renderer: %s", SDL_GetError());
        SDL_DestroyWindow(_window);
        SDL_Quit();
        throw std::runtime_error(SDL_GetError());
    }

    SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
    SDL_RenderClear(_renderer);
    SDL_RenderPresent(_renderer);
}

void Core::initializeNet(void)
{
    if (SDLNet_Init() < 0) {
        SDL_Log("Unable to initialize SDLNet: %s", SDLNet_GetError());
        throw std::runtime_error(SDLNet_GetError());
    }
    IPaddress server;

    if (SDLNet_ResolveHost(&server, _machine.c_str(), _port) == -1) {
        SDL_Log("SDLNet_ResolveHost: %s\n", SDLNet_GetError());
        throw std::runtime_error(SDLNet_GetError());
    }

    _socket = SDLNet_TCP_Open(&server);
    if (!_socket) {
        SDL_Log("SDLNet_TCP_Open: %s\n", SDLNet_GetError());
        throw std::runtime_error(SDLNet_GetError());
    }

    _socketSet = SDLNet_AllocSocketSet(1);
    if (_socketSet == nullptr) {
        SDL_Log("SDLNet_AllocSocketSet: %s\n", SDLNet_GetError());
        throw std::runtime_error(SDLNet_GetError());
    }

    if (SDLNet_TCP_AddSocket(_socketSet, _socket) == -1) {
        SDL_Log("SDLNet_TCP_AddSocket: %s\n", SDLNet_GetError());
        throw std::runtime_error(SDLNet_GetError());
    }

    char receivedData[16384];
    int bytesReceived = SDLNet_TCP_Recv(_socket, receivedData, sizeof(receivedData));
    if (bytesReceived <= 0) {
        std::cerr << "SDLNet_TCP_Recv() failed: " << SDLNet_GetError() << std::endl;
        throw std::runtime_error(SDLNet_GetError());
    }

    std::stringstream ss(receivedData);
    std::string to;

    if (receivedData != NULL) {
        while(std::getline(ss, to, '\n')) {
            handleMessage(to);
        }
    }
}

void Core::initializeGame(void)
{
    _connector = new Connector(_socket, _socketSet);
    _map = new Map(_connector, _renderer);
    _items = new Items(_connector, _renderer);
}

void Core::loop(void)
{
    while (_running) {
        loopGraphic();
        loopNet();
        loopGame();
    }
}

void Core::loopGraphic(void)
{
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT)
            _running = false;
    }
}

void Core::loopNet(void)
{
    int numActiveSockets = SDLNet_CheckSockets(_socketSet, 0);
    if (numActiveSockets == -1) {
        SDL_Log("SDLNet_CheckSockets: %s\n", SDLNet_GetError());
        throw std::runtime_error(SDLNet_GetError());
    }

    if (SDLNet_SocketReady(_socket)) {
        char receivedData[16384];
        int bytesReceived = SDLNet_TCP_Recv(_socket, receivedData, sizeof(receivedData));
        if (bytesReceived <= 0) {
            SDL_Log("SDLNet_TCP_Recv: %s\n", SDLNet_GetError());
            throw std::runtime_error(SDLNet_GetError());
        }
        std::stringstream ss(receivedData);
        std::string to;

        if (receivedData != NULL) {
            while(std::getline(ss, to, '\n')) {
                handleMessage(to);
            }
        }
    }
}

void Core::loopGame(void)
{
    SDL_RenderClear(_renderer);
    _map->update();
    _items->update();
    updateTrantors();
    updateEggs();
    updateTeams();
    SDL_RenderPresent(_renderer);
}

void Core::handleMessage(std::string message)
{
    // std::cout << "[MESSAGE]: " << message << std::endl;
    if (message == "WELCOME") SDLNet_TCP_Send(_socket, "GRAPHIC\n", 8);
    if (message.compare(0, 3, "msz") == 0) {
        std::vector<std::string> v;
        split(message, v, ' ');
        if (v.size() < 3) return;
        int x = safeStoi(v[1]);
        int y = safeStoi(v[2]);
        msz(x, y);
    }
    if (message.compare(0, 3, "bct") == 0) {
        std::vector<std::string> v;
        split(message, v, ' ');
        if (v.size() < 10) return;
        int x =  safeStoi(v[1]);
        int y =  safeStoi(v[2]);
        int q0 = safeStoi(v[3]);
        int q1 = safeStoi(v[4]);
        int q2 = safeStoi(v[5]);
        int q3 = safeStoi(v[6]);
        int q4 = safeStoi(v[7]);
        int q5 = safeStoi(v[8]);
        int q6 = safeStoi(v[9]);
        bct(x, y, q0, q1, q2, q3, q4, q5, q6);
    }
    if (message.compare(0, 3, "tna") == 0) {
        std::string teamName = message.substr(4, message.length() - 4);
        tna(teamName);
    }
    if (message.compare(0, 3, "pnw") == 0) {
        std::vector<std::string> v;
        split(message, v, ' ');
        if (v.size() < 7) return;
        int id = safeStoi(v[1]);
        int x =  safeStoi(v[2]);
        int y =  safeStoi(v[3]);
        int orientation = safeStoi(v[4]);
        int level = safeStoi(v[5]);
        std::string teamName = v[6];
        pnw(id, x, y, orientation, level, teamName);
    }
    if (message.compare(0, 3, "ppo") == 0) {
        std::vector<std::string> v;
        split(message, v, ' ');
        if (v.size() < 5) return;
        int id = safeStoi(v[1]);
        int x =  safeStoi(v[2]);
        int y =  safeStoi(v[3]);
        int orientation = safeStoi(v[4]);
        ppo(id, x, y, orientation);
    }
}

void Core::updateTrantors(void)
{
    for (auto trantor : _trantors)
        trantor->update();
}

void Core::updateEggs(void)
{
    for (auto egg : _eggs)
        egg->update();
}

void Core::updateTeams(void)
{
    for (auto team : _teams) {
        team->update();
    }
}

void Core::msz(int x, int y)
{
    _map->setMapSize({x,y});
    _items->setMapSize({x,y});
}

void Core::bct(int x, int y, int q0, int q1, int q2, int q3, int q4, int q5, int q6)
{
    _items->setTile(x,y,q0,q1,q2,q3,q4,q5,q6);
}

void Core::tna(std::string teamName)
{
    int id = _teams.size();
    Team *team = new Team(teamName, _renderer, id);
    _teams.push_back(team);
}

void Core::pnw(int id, int x, int y, int orientation, int level, std::string teamName)
{
    for (auto team : _teams) {
        if (team->isTeam(teamName)) {
            Trantor *trantor = new Trantor(id, _connector, _map->getTileSize(), _renderer, team);
            _trantors.push_back(trantor);
        }
    }
}

void Core::ppo(int id, int x, int y, int orientation)
{
    for (auto trantor : _trantors) {
        if (trantor->getIndex() == id) {
            std::list<int> pos = {x, y , orientation};
            trantor->setPlayerPosition(pos);
        }
    }
}

void Core::plv(int id, int level)
{

}

void Core::pin(int id, int x, int y, int q0, int q1, int q2, int q3, int q4, int q5, int q6)
{

}

void Core::pex(int id)
{

}

void Core::pbc(int id, std::string message)
{
    for (auto trantor : _trantors) {
        if (trantor->getIndex() == id) {
            trantor->broadcast();
        }
    }
}

void Core::pic(int x, int y, int level, std::list<int> players)
{
    for (auto trantor : _trantors) {
        for (auto id : players) {
            if (trantor->getIndex() == id) {
                trantor->isIncantated();
            }
        }
    }
}

void Core::pie(int x, int y, bool result)
{

}

void Core::pfk(int id)
{
    for (auto trantor : _trantors) {
        if (trantor->getIndex() == id) {
            trantor->layingEgg();
        }
    }
}

void Core::pdr(int id, int resource)
{
    for (auto trantor : _trantors) {
        if (trantor->getIndex() == id) {
            trantor->dropRessource();
        }
    }
}

void Core::pgt(int id, int resource)
{
    for (auto trantor : _trantors) {
        if (trantor->getIndex() == id) {
            trantor->collectRessource();
        }
    }
}

void Core::pdi(int id)
{
    for (auto trantor : _trantors) {
        if (trantor->getIndex() == id) {
            trantor->isDead();
        }
    }
}

void Core::enw(int egg, int player, int x, int y)
{
    std::string playerTeam;
    for (auto trantor : _trantors) {
        if (trantor->getIndex() == player) {
            playerTeam = trantor->getTeamName();
        }
    }
    for (auto team : _teams) {
        if (team->isTeam(playerTeam)) {
            Egg *_egg = new Egg(egg, _renderer, x, y, _map, team);
            _eggs.push_back(_egg);
        }
    }
}

void Core::ebo(int egg)
{
    for (auto _egg = _eggs.begin(); _egg != _eggs.end(); _egg++) {
        if ((*_egg)->getIndex() == egg) {
            _eggs.erase(_egg);
            delete *_egg;
        }
    }
}

void Core::edi(int egg)
{
    for (auto _egg = _eggs.begin(); _egg != _eggs.end(); _egg++) {
        if ((*_egg)->getIndex() == egg) {
            _eggs.erase(_egg);
            delete *_egg;
        }
    }
}

void Core::sgt(int timeUnit)
{

}

void Core::sst(int timeUnit)
{

}

void Core::seg(std::string teamName)
{
    for (auto team : _teams) {
        if (team->isTeam(teamName)) {
            team->victory();
        }
    }
}

void Core::smg(std::string message)
{

}

void Core::suc(void)
{

}

void Core::sbp(void)
{

}

size_t Core::split(const std::string &txt, std::vector<std::string> &strs, char ch)
{
    size_t pos = txt.find(ch);
    size_t initialPos = 0;
    strs.clear();

    while (pos != std::string::npos) {
        std::string strr = txt.substr(initialPos, pos - initialPos);
        if (strr.length() > 0)
            strs.push_back(txt.substr(initialPos, pos - initialPos));
        initialPos = pos + 1;

        pos = txt.find(ch, initialPos);
    }

    std::string str = txt.substr(initialPos, std::min(pos, txt.size()) - initialPos + 1);
    if (str.length() > 0)
        strs.push_back(str);

    return strs.size();
}

int Core::safeStoi(std::string str)
{
    try {
        return std::stoi(str);
    } catch(std::exception &err) {
        return 0;
    }
}