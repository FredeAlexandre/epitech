/*
** EPITECH PROJECT, 2022
** prompt
** File description:
** Get the actual command
*/

#include <unistd.h>
#include <stdio.h>
#include "includes/global.h"

void show_prompt(void)
{
    if (isatty(0)) write(1, "[Minishell]&>", 13);
}

void check_exit(char *str, int *returned)
{
    if (str == NULL) return;
    char *start = str;
    while (!(start[0] == '\0' || (start[0] != ' ' && start[0] != '\t'))) {
        start = &start[1];
    }
    int result = my_strcmp(start, "exit");
    if (result == 0) {
        *returned = 0;
    }
}

int prompt(char *buffer)
{
    show_prompt();
    size_t size = 256;
    if (getline(&buffer, &size, stdin) == -1) return 0;
    int returned = 1;
    if (my_strlen(buffer) > 1) {
        buffer[my_strlen(buffer) - 1] = '\0';
        char *result = my_strdup(buffer);
        check_exit(my_strtok(result, " \t"), &returned);
        free(result);
    };
    return returned;
}
