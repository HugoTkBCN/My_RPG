/*
** EPITECH PROJECT, 2019
** get int
** File description:
** parser
*/

#include "../../../include/parser.h"

char *ret_int(char *line, int i)
{
    char *nbr = malloc(sizeof(char) * (my_strlen(line) + 1));
    int y = 0;

    i += line[i] == ' ' ? 1 : 0;
    if (nbr == NULL)
        return (NULL);
    for (i = i; line[i] != ' ' && line[i] && line[i] != ';'; i++) {
        nbr[y++] = line[i];
    }
    nbr[y] = '\0';
    return (nbr);
}

int check_int(char *nbr, char *elem)
{
    int ret = 0;

    if (nbr == NULL)
        return (0);
    else if (is_num(nbr) == 0)
        return (-1);
    ret = str_to_int(nbr);
    free(nbr);
    free(elem);
    return (ret);
}

int get_int(char *line, char *type)
{
    int i = 0;
    int c = 0;
    char *elem = malloc(sizeof(char) * (my_strlen(line) + 1));
    char *nbr = NULL;

    if (elem == NULL)
        return (-1);
    for (i = 0; line[i] != ':' && line[i]; i++);
    i = line[i + 1] == ' ' ? i + 2 : i + 1;
    for (i = i; i < my_strlen(line) && nbr == NULL; i++) {
        elem[c] = line[i] == '=' ? '\0' : line[i];
        nbr = line[i] == '=' && my_strcmp(elem, type) == 1 ?
            ret_int(line, i + 1) : NULL;
        c = line[i] == '=' ? 0 : c + 1;
        i = line[i] == '=' ? increase_i(i, line) : i;
        if (i < my_strlen(line) && c - 1 >= 0)
            c = (line[i] != '=' && elem[c - 1] == ' ') ? c - 1 : c;
    }
    return (check_int(nbr, elem));
}
