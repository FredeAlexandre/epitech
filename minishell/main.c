/*
** EPITECH PROJECT, 2022
** main
** File description:
** main funcftion
*/

#include <unistd.h>
#include <stdio.h>
#include "includes/global.h"

void internal_main(char *buffer, int *end)
{
    char **command = get_command(buffer);
    if (!builtin(command) && command != NULL) {
        char *bin = find_executable(command[0]);
        *end = execute(bin == NULL ? command[0] : bin, command, 1) != 2;
        if (bin != NULL) free(bin);
    }
    if (command != NULL) free_command(command);
}

int main(int argc, char * const argv[], char * env[])
{
    char buffer[256] = "\0";
    int end = 0;

    my_initenv(env);
    while (!(!prompt(buffer) || end)) {
        if (next_redirection(buffer) == 1) {
            exec_pipe(buffer, env);
            continue;
        }
        internal_main(buffer, &end);
    }
    my_clearenv();
    return 0;
}
