/*
** EPITECH PROJECT, 2018
** my revstr
** File description:
** task 03
*/

#include "../../include/my_rpg.h"

char *my_revstr(char *str)
{
    int i = 0;
    int y = my_strlen(str) - 1;
    char *tmp = malloc(sizeof(char) * (my_strlen(str) + 1));

    if (tmp == NULL)
        return (NULL);
    while (y >= 0) {
        tmp[i] = str[y];
        y--;
        i++;
    }
    tmp[i] = '\0';
    return (tmp);
}
