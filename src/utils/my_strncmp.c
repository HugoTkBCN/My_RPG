/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** strncmp
*/

#include "../../include/my_rpg.h"

int my_strncmp(char *s1, char *s2, int n)
{
    if (my_strlen(s1) < n || my_strlen(s2) < n)
        return (-1);
    for (int i = 0; i < n; i++) {
        if (s1[i] != s2[i])
            return (-1);
    }
    return (0);
}

int my_strcmp(char *str1, char *str2)
{
    if (my_strlen(str1) != my_strlen(str2))
        return (0);
    for (int i = 0; str1[i] && str2[i]; i++)
        if (str1[i] != str2[i])
            return (0);
    return (1);
}
