/*
** EPITECH PROJECT, 2022
** log.c
** File description:
** Simple log for the boilerplate
*/

#include <stdio.h>
#include <string.h>
#include <strings.h>

#include "zappy.h"

struct item_name_map_s {
    Item item;
    char *name;
};

static struct item_name_map_s item_name_map[] = {
    {Food, "food"},
    {Linemate, "linemate"},
    {Deraumere, "deraumere"},
    {Sibur, "sibur"},
    {Mendiane, "mendiane"},
    {Phiras, "phiras"},
    {Thystame, "thystame"}
};

char *get_item_name(Item item)
{
    for (size_t i = 0; i < sizeof(item_name_map); i++) {
        if (item_name_map[i].item == item) return item_name_map[i].name;
    }
    return NULL;
}

Item get_item_by_name(char *name)
{
    for (size_t i = 0; i < sizeof(item_name_map); i++) {
        if (strcasecmp(item_name_map[i].name, name) == 0) return item_name_map[i].item;
    }
    return -1;
}
