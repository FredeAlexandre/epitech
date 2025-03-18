/*
** EPITECH PROJECT, 2022
** nbr_word
** File description:
** c
*/

int get_nbr_word(char **command)
{
    int nbr_word == 0;

    for (int i = 0; command[i] != NULL; i++) {
        nbr_word++;
    }
    return nbr_word;
}
