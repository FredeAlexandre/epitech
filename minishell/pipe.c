/*
** EPITECH PROJECT, 2022
** main
** File description:
** c
*/
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "includes/global.h"

int child_second_fork(int *pipe_pid, int *pipe_pid2, int nbr_pipe)
{
    dup2(pipe_pid[0], STDIN_FILENO);
    if (nbr_pipe > 0) {
        dup2(pipe_pid2[1], STDOUT_FILENO);
        close(pipe_pid2[0]);
    }
}

int second_pipe(int *pipe_pid, char *command, char **env, int nbr_pipe)
{
    pid_t child;
    int pipe_pid2[2];
    char *command1 = my_strtok(NULL, "|");

    nbr_pipe--;
    pipe(pipe_pid2);
    child = fork();
    if (child == -1) return 84;
    if (child == 0) {
        child_second_fork(pipe_pid, pipe_pid2, nbr_pipe);
        execute_function(command1, env);
        exit(0);
    } else {
        close(pipe_pid[0]);
        close(pipe_pid2[1]);
        if (nbr_pipe > 0)
            second_pipe(pipe_pid2, command, env, nbr_pipe);
    }
    return 0;
}

int first_pipe(int *pipe_pid, char *command, char **env, int nbr_pipe)
{
    pid_t child;
    char *command1 = my_strtok(command, "|");

    child = fork();
    if (child == -1) return 84;
    if (child == 0) {
        dup2(pipe_pid[1], STDOUT_FILENO);
        close(pipe_pid[0]);
        execute_function(command1, env);
        exit(0);
    } else {
        close(pipe_pid[1]);
        second_pipe(pipe_pid, command, env, nbr_pipe);
    }
    return 0;
}

int exec_pipe(char *command, char **env)
{
    int pipe_pid[2];
    int nbr_pipe = my_strtoklen(command, "|") -1;

    pipe(pipe_pid);
    first_pipe(pipe_pid, command, env, nbr_pipe);
    for (int i = 0; i < nbr_pipe + 1; i++) {
        wait(NULL);
    }
    return 0;
}
