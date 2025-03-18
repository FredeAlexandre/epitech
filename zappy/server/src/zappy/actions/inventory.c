/*
** EPITECH PROJECT, 2023
** Zappy [WSL: Ubuntu]
** File description:
** init_zappy
*/

#include <stdio.h>
#include <string.h>
#include "zappy.h"

void inventory_action(player_t *player)
{
    if (!player->client) return;

    char result[OUT_BUFFER_SIZE];
    bzero(result, OUT_BUFFER_SIZE);

    strcat(result, "[");

    for (int i = 0; i < ITEMS_AMOUNT; i++) {
        Item item = i;
        strcat(result, get_item_name(item));
        strcat(result, " ");
        char amount[10];
        sprintf(amount, "%d", get_amount_inventory(player, item));
        strcat(result, amount);
        strcat(result, ",");
    }
    result[strlen(result) - 1] = ']';
    player->action = NULL;
    send_message(player->client, result);
}
