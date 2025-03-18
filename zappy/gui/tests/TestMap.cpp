#include "../src/Map.hpp"
#include "../src/Trantor.hpp"
#include "../src/Items.hpp"
#include "../src/Egg.hpp"
#include "../src/Team.hpp"
#include <SDL2/SDL_ttf.h>

int main()
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "Failed to initialize SDL: " << SDL_GetError() << std::endl;
        return 1;
    }
    if (TTF_Init() != 0) {
        std::cerr << "Failed to initialize SDL: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("Zappy", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1920, 1080, SDL_WINDOW_SHOWN);
    if (!window) {
        std::cerr << "Failed to create SDL window: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::cerr << "Failed to create SDL renderer: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    Connector connector;
    connector.testing();
    std::list<int> _mapSize = {10, 10};
    std::list<int> _playerPosition = {0, 0, 2};
    std::list<int> _tileContent = {5, 4, 0, 0, 1, 1, 0, 0 , 1};
    connector.setMapSize(_mapSize);
    connector.setPlayerPosition(_playerPosition);
    connector.setTileContent(_tileContent);
    Map *map = new Map(&connector, renderer);
    Items *items = new Items(&connector, renderer);
    std::list<int> _playerPosition4 = {2, 2, 1};
    printf("test\n");
    Team *team1 = new Team("RushImmo", renderer, 0);
    Team *team2 = new Team("GoFer3", renderer, 1);
    printf("test\n");
    Trantor *trantor = new Trantor(1, &connector, map->getTileSize(), renderer, team1);
    connector.setPlayerPosition(_playerPosition4);
    Trantor *trantor1 = new Trantor(2, &connector, map->getTileSize(), renderer, team2);
    SDL_Texture *texture;
    SDL_Texture *texture1;
    SDL_Rect texr;
    SDL_Rect texr1;
    SDL_Color TextColor;
    SDL_Surface *surface;
    SDL_Surface *surface1;
    TTF_Font *Font;
        Font = TTF_OpenFont("../src/sprites/PoliceGame.TTF", 25);
        TextColor.r = 255;
        TextColor.g = 255;
        TextColor.b = 255;
        if (Font == NULL) printf("error font\n");
        std::string teamName = "RushImmo";
        if ((surface = TTF_RenderText_Solid(Font, teamName.c_str(), TextColor)) == NULL) return -84;
        if ((texture = SDL_CreateTextureFromSurface(renderer, surface)) == NULL) return -84;
        int texteX = 1920 - surface->w - 25;
        int texteY = 10;
        texr.x = texteX;
        texr.y = texteY;
        texr.w = surface->w;
        texr.h = surface->h;
        std::string teamName1 = "GoFer3";
        if ((surface1 = TTF_RenderText_Solid(Font, teamName1.c_str(), TextColor)) == NULL) return -84;
        if ((texture1 = SDL_CreateTextureFromSurface(renderer, surface1)) == NULL) return -84;
        int texteX1 = 1920 - surface1->w - 25;
        int texteY1 = 10 * 2 + texr.h;
        texr1.x = texteX1;
        texr1.y = texteY1;
        texr1.w = surface1->w;
        texr1.h = surface1->h;
    int i = 0;
    while (i != 500) {
        SDL_RenderClear(renderer);
        map->update();
        items->update();
        connector.setPlayerPosition(_playerPosition);
        trantor->update();
        connector.setPlayerPosition(_playerPosition4);
        trantor1->update();
        team1->update();
        team2->update();
        SDL_RenderPresent(renderer);
        i++;
    }
    std::list<int> _playerPosition1 = {1, 0, 2};
    connector.setPlayerPosition(_playerPosition1);
    std::list<int> _playerPosition5 = {2, 1, 1};
    i = 0;
    while (i != 500) {
        SDL_RenderClear(renderer);
        map->update();
        items->update();
        connector.setPlayerPosition(_playerPosition1);
        trantor->update();
        connector.setPlayerPosition(_playerPosition5);
        trantor1->update();
        team1->update();
        team2->update();
        SDL_RenderPresent(renderer);
        i++;
    }
    std::list<int> _playerPosition2 = {1, 1, 3};
    connector.setPlayerPosition(_playerPosition2);
    std::list<int> _playerPosition6 = {3, 1, 2};
    i = 0;
    while (i != 500) {
        SDL_RenderClear(renderer);
        map->update();
        items->update();
        connector.setPlayerPosition(_playerPosition2);
        trantor->update();
        connector.setPlayerPosition(_playerPosition6);
        trantor1->update();
        team1->update();
        team2->update();
        SDL_RenderPresent(renderer);
        i++;
    }
    /*i = 0;
    trantor1->isIncantated();
    trantor->isIncantated();
    while (i != 500) {
        SDL_RenderClear(renderer);
        map->update();
        items->update();
        connector.setPlayerPosition(_playerPosition2);
        trantor->update();
        connector.setPlayerPosition(_playerPosition6);
        trantor1->update();
        SDL_RenderPresent(renderer);
        i++;
    }
    i = 0;
    trantor1->endIncantated();
    trantor->endIncantated();
    while (i != 500) {
        SDL_RenderClear(renderer);
        map->update();
        items->update();
        connector.setPlayerPosition(_playerPosition2);
        trantor->update();
        connector.setPlayerPosition(_playerPosition6);
        trantor1->update();
        SDL_RenderPresent(renderer);
        i++;
    }
    i = 0;
    trantor1->layingEgg();
    while (i != 500) {
        SDL_RenderClear(renderer);
        map->update();
        items->update();
        connector.setPlayerPosition(_playerPosition2);
        trantor->update();
        connector.setPlayerPosition(_playerPosition6);
        trantor1->update();
        SDL_RenderPresent(renderer);
        i++;
    }*/
    i = 0;
    Egg *egg1 = new Egg(1, renderer, 2, 2, map, team1);
    trantor1->broadcast();
    while (i != 500) {
        SDL_RenderClear(renderer);
        map->update();
        items->update();
        connector.setPlayerPosition(_playerPosition2);
        trantor->update();
        connector.setPlayerPosition(_playerPosition6);
        trantor1->update();
        egg1->update();
        team1->update();
        team2->update();
        SDL_RenderPresent(renderer);
        i++;
    }
    Egg *egg = new Egg(1, renderer, 5, 5, map, team2);
    i = 0;
    trantor1->isDead();
    trantor->isDead();
    while (i != 500) {
        SDL_RenderClear(renderer);
        map->update();
        items->update();
        connector.setPlayerPosition(_playerPosition2);
        trantor->update();
        connector.setPlayerPosition(_playerPosition6);
        trantor1->update();
        egg1->update();
        egg->update();
        team1->update();
        team2->update();
        SDL_RenderPresent(renderer);
        i++;
    }
        SDL_FreeSurface(surface);
        SDL_DestroyTexture(texture);
        TTF_CloseFont(Font);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}