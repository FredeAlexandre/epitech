/*
** EPITECH PROJECT, 2023
** Zappy [WSL: Ubuntu]
** File description:
** init_zappy
*/

#include <stdio.h>
#include <string.h>
#include "zappy.h"

int get_amount_inventory(player_t *player, Item item)
{
    switch (item) {
    case Food:
        return player->inventory.food;
    case Linemate:
        return player->inventory.linemate;
    case Deraumere:
        return player->inventory.deraumere;
    case Sibur:
        return player->inventory.sibur;
    case Mendiane:
        return player->inventory.mendiane;
    case Phiras:
        return player->inventory.phiras;
    case Thystame:
        return player->inventory.thystame;
    default:
        return 0;
    }
}
