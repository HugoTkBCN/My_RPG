/*
** EPITECH PROJECT, 2019
** is num
** File description:
** parser
*/

#include "../../../include/parser.h"

int is_num(char *str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] < '0' || str[i] > '9')
            return (0);
    return (1);
}
