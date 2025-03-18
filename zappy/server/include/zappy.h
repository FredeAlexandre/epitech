/*
** EPITECH PROJECT, 2022
** server.h
** File description:
** All functions used by the server
*/

#include <time.h>

#ifndef _ZAPPY_
#define _ZAPPY_

#include "server.h"

#define TIME_UNIT 1000000000L
#define LIFE_UNIT 126 * TIME_UNIT

typedef struct zappy_s zappy_t;
typedef struct map_s map_t;
typedef struct tile_s tile_t;
typedef struct team_s team_t;
typedef struct player_s player_t;
typedef struct inventory_s inventory_t;
typedef enum Item_e Item;

enum Item_e { Food, Linemate, Deraumere, Sibur, Mendiane, Phiras, Thystame };
#define ITEMS_AMOUNT 7

struct zappy_s {
    map_t *map;
    team_t *teams;
    long freq;
};

struct map_s {
    int height;
    int width;
    int first_spawned;
    struct timespec last_ressources_spawn;
    tile_t **tiles;
};

struct tile_s {
    Item *items;
    int items_amount;
    int x;
    int y;
    int players_amount;
};

struct team_s {
    const char *name;
    player_t *players;
    team_t *next;
};

enum Action_e { Idle, Forward, Right, Left, Look, Inventory, Broadcast, Fork, Eject, Take, Set, Incantation };
enum Direction_e { North, East, South, West };

struct inventory_s {
    int food;
    int linemate;
    int deraumere;
    int sibur;
    int mendiane;
    int phiras;
    int thystame;
};

typedef void (*action_t)(player_t *player);

struct player_s {
    int id;
    player_t *next;
    void* client;

    int is_egg;

    action_t action;
    char *options;
    struct timespec action_timeout;

    int level;

    inventory_t inventory;

    enum Direction_e direction;
    
    int x;
    int y;

    struct timespec dead_timeout;
};

void forward_action(player_t *player);
void left_action(player_t *player);
void look_action(player_t *player);
void right_action(player_t *player);
void inventory_action(player_t *player);
void broadcast_action(player_t *player);
void connect_nbr_action(player_t *player);
void fork_action(player_t *player);
void eject_action(player_t *player);
void take_action(player_t *player);
void set_action(player_t *player);
// void incantation_action(player_t *player);

int init_zappy(const char **argv, const args_t *args);
void destroy_zappy(void);

void update_zappy(void);
void update_ressources(void);
void update_players(void);

zappy_t *get_zappy(zappy_t* new_zappy);

team_t *get_team(const char *name);
team_t *get_team_of(const player_t *player);

player_t *add_player(team_t *team, int x, int y, int is_egg);

tile_t *get_tile(int x, int y);
void add_item(tile_t *tile, Item item);
int remove_item(tile_t *tile, Item item);
int get_item_amount(tile_t *tile, Item item);
int get_total_item_amount(Item item);

char *get_item_name(Item item);
Item get_item_by_name(char *name);

int get_amount_inventory(player_t *player, Item item);
void set_amount_inventory(player_t *player, Item item, int amount);

void msz_route(connection_t *connection);
void quit_route(connection_t *connection);
void bct_route(connection_t *connection, char *options);
void bct_compute(connection_t *connection, int x, int y);
void mct_route(connection_t *connection);
void tna_route(connection_t *connection);
void ppo_route(connection_t *connection, char *options);
void plv_route(connection_t *connection, char *options);
void pin_route(connection_t *connection, char *options);
void sgt_route(connection_t *connection);
void kill_player(player_t *player);

#define DEFAULT_TEAM_1 "Team1"
#define DEFAULT_TEAM_2 "Team2"
#define DEFAULT_TEAM_3 "Team3"
#define DEFAULT_TEAM_4 "Team4"

#endif
