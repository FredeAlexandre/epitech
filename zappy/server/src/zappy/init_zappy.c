/*
** EPITECH PROJECT, 2023
** Zappy [WSL: Ubuntu]
** File description:
** init_zappy
*/

#include <stdio.h>
#include <string.h>
#include "server.h"
#include "zappy.h"

int init_map(int width, int height)
{
    zappy_t *zappy = get_zappy(NULL);
    zappy->map = malloc(sizeof(map_t));
    if (!zappy->map) return -1;
    zappy->map->width = width;
    zappy->map->height = height;
    zappy->map->tiles = malloc(sizeof(tile_t *) * width * height);
    zappy->map->first_spawned = 0;
    for (int i = 0; i <  width * height; i++) {
        zappy->map->tiles[i] = malloc(sizeof(tile_t));
        if (!zappy->map->tiles[i]) return -1;
        zappy->map->tiles[i]->items = NULL;
        zappy->map->tiles[i]->items_amount = 0;
        zappy->map->tiles[i]->x = i % width;
        zappy->map->tiles[i]->y = i / width;
    }
    printf("[ZAPPY] Map created with a width: %i and height: %i \n", width, height);
    return 0;
}

int default_teams(int start_players)
{
    zappy_t *zappy = get_zappy(NULL);
    team_t *last_team = NULL;
    for (int i = 0; i < 4; i++) {
        team_t *team = malloc(sizeof(team_t));
        if (!team) return -1;
        if (zappy->teams == NULL) zappy->teams = team;
        if (i == 0) team->name = DEFAULT_TEAM_1;
        if (i == 1) team->name = DEFAULT_TEAM_2;
        if (i == 2) team->name = DEFAULT_TEAM_3;
        if (i == 3) team->name = DEFAULT_TEAM_4;
        team->players = NULL;
        team->next = NULL;
        if (last_team)
            last_team->next = team;
        last_team = team;
        printf("[ZAPPY] Team {%s} created !\n", team->name);
        for (int i = 0; i < start_players; i++) {
            add_player(team, rand() % zappy->map->width, rand() % zappy->map->height, 0);
        }
    }
    return 0;
}

int init_teams(const char **argv, int first_name_id, int last_name_id, int start_players)
{
    zappy_t *zappy = get_zappy(NULL);
    if (first_name_id == last_name_id && first_name_id == -1) return default_teams(start_players);
    team_t *last_team = NULL;
    for (int i = first_name_id; i <= last_name_id; i++) {
        team_t *team = malloc(sizeof(team_t));
        if (!team) return -1;
        if (zappy->teams == NULL) zappy->teams = team;
        team->name = argv[i];
        team->players = NULL;
        team->next = NULL;
        if (last_team)
            last_team->next = team;
        last_team = team;
        printf("[ZAPPY] Team {%s} created !\n", argv[i]);
        for (int i = 0; i < start_players; i++) {
            add_player(team, rand() % zappy->map->width, rand() % zappy->map->height, 0);
        }
    }
    return 0;
}

int init_zappy(const char **argv, const args_t *args)
{
    if (init_server(args->port) == -1) return -1;
    zappy_t *zappy = malloc(sizeof(zappy_t));
    if (!zappy) return -1;
    zappy->teams = NULL;
    get_zappy(zappy);
    get_graphic("GRAPHIC");

    init_map(args->width, args->height);
    init_teams(argv, args->first_name_id, args->last_name_id, args->clients_nb_max);
    printf("[ZAPPY] Max clients: %d\n", args->clients_nb_max);
    printf("[ZAPPY] Server frequency: %d\n", args->freq);
    zappy->freq = args->freq;
    return 0;
}
