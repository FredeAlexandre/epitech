/*
** EPITECH PROJECT, 2023
** Zappy [WSL: Ubuntu]
** File description:
** get_zappy
*/

#include <stdlib.h>
#include "zappy.h"

zappy_t *get_zappy(zappy_t* new_zappy)
{
    static zappy_t *saved_zappy = NULL;

    if (new_zappy != NULL) saved_zappy = new_zappy;

    return saved_zappy;
}
