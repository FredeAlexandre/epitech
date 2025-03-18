/*
** EPITECH PROJECT, 2022
** my_strlen
** File description:
** Return the length of a string
*/

#include <stdlib.h>
#include "include/global.h"

int strtoint(const char *str)
{
    int v = 0;
    int mul = 1;
    int len = my_strlen(str);

    for (size_t i = len; i > 0; i--) {
        v += (str[i - 1] - '0') * mul;
        mul *= 10;
    }
    return v;
}

void fill_stack_a_internal(const char *str, stack *s)
{
    int is_negative = str[0] == '-';
    int v = is_negative ? -strtoint(&str[1]) : strtoint(str);
    add_item(v, s);
}

void fill_stack_a(int argc, char **argv)
{
    for (int i = 1; i < argc; i++) {
        if (argv[i][0] == '-' && argv[i][1] == 'v') v_enabled(1);
        else {
            fill_stack_a_internal(argv[i], stack_a(NULL));
        }
    }
}
