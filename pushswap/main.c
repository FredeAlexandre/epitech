/*
** EPITECH PROJECT, 2022
** my_strlen
** File description:
** Return the length of a string
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "include/global.h"

int main(int argc, char **argv)
{
    stack_a(create_stack());
    stack_b(create_stack());
    fill_stack_a(argc, argv);
    if (stack_a(NULL)->length == 0) return 0;
    if (v_enabled(-1)) {
        print_status("starter");
        first_action(0);
    }
    set_sorted();
    sort();
    if (v_enabled(-1)) {
        print_divider();
        print_status("finish");
    } else {
        write(1, "\n", 1);
    }
    free_stack(stack_a(NULL));
    free_stack(stack_b(NULL));
    return 0;
}
