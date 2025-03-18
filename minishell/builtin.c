/*
** EPITECH PROJECT, 2022
** main
** File description:
** main funcftion
*/

#include <unistd.h>
#include <stdio.h>
#include "includes/global.h"

int btin_setenv(char **command)
{
    if (my_arrlen(command) < 3) {
        write(2, "setenv invalid number of arguments\n", 35);
    } else {
        my_setenv(command[1], command[2], 1);
    }
    return 1;
}

int btin_unsetenv(char **command)
{
    if (my_arrlen(command) < 2) {
        write(2, "unsetenv invalid number of arguments\n", 37);
    } else {
        my_unsetenv(command[1]);
    }
    return 1;
}

int btin_env(void)
{
    char **env = my_environ();
    for (size_t i = 0; env[i] != NULL; i++) {
        write(1, env[i], my_strlen(env[i]));
        write(1, "\n", 1);
    }
    return 1;
}

int btin_cd(char **command)
{
    char *actual = my_getenv("PWD");
    char *pwd;
    if (my_arrlen(command) == 1 || command[1] == NULL) {
        char home[] = "~";
        pwd = absolute_path(actual, home);
    } else {
        pwd = absolute_path(actual, command[1]);
    }
    if (pwd == NULL) {
        write(2, "Home env is not set\n", 20);
        return 1;
    }
    if (chdir(pwd) == -1) write(2, "Directory not found\n", 20);
    else {
        my_setenv("OLDPWD", actual, 1);
        my_setenv("PWD", pwd, 1);
    }
    free(pwd);
    return 1;
}

int builtin(char **command)
{
    if (my_strcmp(command[0], "setenv") == 0) return btin_setenv(command);
    if (my_strcmp(command[0], "unsetenv") == 0) return btin_unsetenv(command);
    if (my_strcmp(command[0], "env") == 0) return btin_env();
    if (my_strcmp(command[0], "cd") == 0) return btin_cd(command);
    return 0;
}
