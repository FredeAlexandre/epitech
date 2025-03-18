/*
** EPITECH PROJECT, 2022
** execute
** File description:
** main funcftion
*/

#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include "includes/global.h"

int execute(char *bin, char **argv, int w)
{
    pid_t child = fork();

    if (child == -1) return -1;
    if (child == 0) {
        if (execve(bin, argv, my_environ()) == -1) {
            write(2, "mysh: command not found: ", 25);
            write(2, bin, my_strlen(bin));
            write(2, "\n", 1);
            return 0;
        } else {
            return 1;
        }
    } else {
        wait(NULL);
        return 2;
    }
}
