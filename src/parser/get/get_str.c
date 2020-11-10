/*
** EPITECH PROJECT, 2019
** get string parser
** File description:
** parser
*/

#include "../../../include/parser.h"

char *ret_str(char *line, int i)
{
    char *str = malloc(sizeof(char) * (my_strlen(line) + 1));
    int y = 0;

    i += line[i] == ' ' ? 1 : 0;
    if (line[i] != '\"' || str == NULL)
        return (NULL);
    for (i = i + 1; line[i] != '\"' && line[i] && line[i] != ';'; i++) {
        str[y++] = line[i];
    }
    if (line[i] != '\"')
        return (NULL);
    str[y] = '\0';
    return (str);
}

char *get_str(char *line, char *type)
{
    int i = 0;
    int y = 0;
    char *elem = malloc(sizeof(char) * (my_strlen(line) + 1));
    char *str = NULL;

    if (elem == NULL)
        return (NULL);
    for (i = 0; line[i] != ':' && line[i]; i++);
    i = line[i + 1] == ' ' ? i + 2 : i + 1;
    for (i = i; i < my_strlen(line) && str == NULL; i++) {
        elem[y] = line[i] == '=' ? '\0' : line[i];
        str = line[i] == '=' && my_strcmp(elem, type) == 1 ?
            ret_str(line, i + 1) : NULL;
        y = line[i] == '=' ? 0 : y + 1;
        i = line[i] == '=' ? increase_i(i, line) : i;
        if (i < my_strlen(line) && y - 1 >= 0)
            y = line[i] != '=' && elem[y - 1] == ' ' ? y - 1 : y;
    }
    free(elem);
    return (str);
}
