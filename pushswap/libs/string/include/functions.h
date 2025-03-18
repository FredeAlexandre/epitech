/*
** EPITECH PROJECT, 2022
** functions.h
** File description:
** The functions of the library
*/


#include <stdlib.h>

#ifndef MY_STRING_FUNCTIONS
    #define MY_STRING_FUNCTIONS

void *my_memccpy(void *dest, const void *src, int ch, size_t max);
void *my_memchr(const void *mem_block, int ch, size_t size);
int my_memcmp(const void *ptr1, const void *ptr2, size_t size);
void *my_memcpy(void *dest, const void *src, size_t max);
void *my_memmove(void *dest, const void *src, size_t max);
void *my_memset(void *ptr, int v, size_t count);

char *my_strcat(char *dest, const char *src);
char *my_strchr(char const *str, int ch);
int my_strcmp(char const *str1, char const *str2);
char *my_strcpy(char *dest, char const *src);
size_t my_strcspn(char const *str, char const *r);
char *my_strdup(const char *source);
size_t my_strlen(char const *str);
char *my_strncat(char *dest, const char *src, size_t n);
int my_strncmp(char const *str1, char const *str2, size_t n);
char *my_strncpy(char *dest, char const *src, size_t n);
char *my_strndup(const char *source, size_t n);
char *my_strpbrk(const char *str, const char *s);
char *my_strrchr(char const *str, int ch);
size_t my_strspn(char const *str, char const *a);
char *my_strstr(const char *full, const char *query);
char *my_strtok(char *set_str, const char *sep);

#endif
