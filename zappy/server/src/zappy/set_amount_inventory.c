/*
** EPITECH PROJECT, 2023
** Zappy [WSL: Ubuntu]
** File description:
** init_zappy
*/

#include <stdio.h>
#include <string.h>
#include "zappy.h"

void set_amount_inventory(player_t *player, Item item, int amount)
{
    switch (item) {
    case Food:
        player->inventory.food = amount;
        break;
    case Linemate:
        player->inventory.linemate = amount;
        break;
    case Deraumere:
        player->inventory.deraumere = amount;
        break;
    case Sibur:
        player->inventory.sibur = amount;
        break;
    case Mendiane:
        player->inventory.mendiane = amount;
        break;
    case Phiras:
        player->inventory.phiras = amount;
        break;
    case Thystame:
        player->inventory.thystame = amount;
        break;
    default:
        break;
    }
}
