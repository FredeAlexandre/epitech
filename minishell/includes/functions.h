/*
** EPITECH PROJECT, 2022
** functions.h
** File description:
** The functions of the library
*/


#include <stdlib.h>

#ifndef MINISHELL_FUNCTIONS
    #define MINISHELL_FUNCTIONS

int prompt(char *);
void internal_main(char *buffer, int *end);

char **get_command(const char *str);
void free_command(char **command);

int builtin(char **command);

size_t my_lengthenv(char **env);
char **my_initenv(char **new_env);
char **my_storenv(char **new_env);
char **my_environ(void);
size_t my_searchenv(const char *name);
int my_addslotenv(void);
int my_rmslotenv(void);
int my_putenv(char *string);
int my_setenv(const char *name, const char *value, int overwrite);
int my_unsetenv(const char *name);
char *my_getenv(const char *name);
int my_clearenv(void);

char *absolute_path(const char *actual, char *q);

size_t my_arrlen(char **arr);

char *find_executable(char *command);
int execute(char *bin, char **argv, int w);

int is_pipe(char *command, int i, int length);
int is_right_redir(char *command, int i, int length);
int is_left_redir(char *command, int i, int length);
int is_right_dbl_redir(char *command, int i, int length);
int is_left_dbl_redir(char *command, int i, int length);
int is_separator(char *command, int i, int length);
int check_pipe(char *command);
int next_redirection(char *command);
int exec_pipe(char *command, char **env);
void execute_function(char *command, char **env);
#endif
