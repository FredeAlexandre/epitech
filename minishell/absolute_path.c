/*
** EPITECH PROJECT, 2022
** main
** File description:
** main funcftion
*/

#include <unistd.h>
#include <stdio.h>
#include "includes/global.h"

int absolute_pathfillw(const char* content, char **buffer)
{
    int len = 0;
    char *c = my_strdup(content);
    for (char *i = my_strtok(c, "/"); i != NULL; i = my_strtok(NULL, "/")) {
        buffer[len] = my_strdup(i);
        len++;
    }
    buffer[len] = NULL;
    free(c);
    return len;
}

int absolute_pathfill(const char *actual, char first, char **buffer)
{
    switch (first) {
        case '/':
            return 0;
        case '~':
            char * home = my_getenv("HOME");
            if (home == NULL) return -1;
            return absolute_pathfillw(home, buffer);
        case '-':
            char * old = my_getenv("OLDPWD");
            if (old == NULL) return -1;
            return absolute_pathfillw(old, buffer);
        default:
            return absolute_pathfillw(actual, buffer);
    }
}

char *absolute_result(char **buffer)
{
    size_t i = 0;
    size_t length = 0;
    for (; buffer[i] != NULL; i++) {
        length += my_strlen(buffer[i]) + 1;
    }
    length = i == 0 ? 1 : length;
    char *result = malloc(sizeof(char) * (length + 1));
    result[0] = '\0';
    return result;
}

void absolute_fillq(char *q, int len, char **buffer)
{
    int oui = 0;
    for (char *i = my_strtok(q, "/"); i != NULL; i = my_strtok(NULL, "/")) {
        if (oui == 0 && q[0] == '~') {
            oui = 1;
            continue;
        }
        if (my_strcmp(i, ".") == 0) continue;
        if (my_strcmp(i, "..") == 0) {
            len = len > 0 ? len - 1 : 0;
            free(buffer[len]);
            buffer[len] = NULL;
        } else {
            len++;
            buffer[len -  1] = my_strdup(i);
            buffer[len] = NULL;
        }
    }
}

char *absolute_path(const char *actual, char *q)
{
    char *buffer[256] = {NULL};
    int len = absolute_pathfill(actual, q[0], buffer);
    if (len == -1) return NULL;
    if (my_strcmp(q, "-") != 0) absolute_fillq(q, len, buffer);
    char *result = absolute_result(buffer);
    size_t i = 0;
    for (; buffer[i] != NULL; i++) {
        my_strcat(result, "/");
        my_strcat(result, buffer[i]);
    }
    if (i == 0) my_strcat(result, "/");
    return result;
}
