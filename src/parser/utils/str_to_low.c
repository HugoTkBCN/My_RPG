/*
** EPITECH PROJECT, 2019
** str to low cass
** File description:
** parser
*/

#include "../../../include/parser.h"

char *str_to_low(char *str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] = str[i] - 32;
    return (str);
}
