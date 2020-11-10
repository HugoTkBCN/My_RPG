/*
** EPITECH PROJECT, 2019
** get type line to parse
** File description:
** parser
*/

#include "../../../include/parser.h"

int get_len_type(char *line)
{
    int i = 0;

    for (i = 0; line[i] != ':' && line[i]; i++);
    return (i);
}

int get_type_line(char *line)
{
    char *type = malloc(sizeof(char) * (get_len_type(line) + 1));
    int i = 0;

    if (type == NULL)
        return (84);
    for (i = 0; line[i] != ':' && line[i]; i++)
        type[i] = line[i];
    type[(i = (type[i - 1] == ' ' ? i - 1 : i))] = '\0';
    if (my_strlen(line) == i) {
        free(type);
        return (84);
    }
    for (int y = 0; TYPE[y]; y++)
        if (my_strcmp(TYPE[y], type) == 1) {
            free(type);
            return (y);
        }
    free(type);
    return (84);
}
