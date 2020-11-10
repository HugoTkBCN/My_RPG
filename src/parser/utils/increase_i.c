/*
** EPITECH PROJECT, 2019
** increase i to other element to parse
** File description:
** parser
*/

#include "../../../include/parser.h"

int increase_i(int i, char *line)
{
    for (i = i; line[i] != '|' && line[i] && line[i] != ';'; i++);
    return (i + 1);
}
