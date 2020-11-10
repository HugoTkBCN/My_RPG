/*
** EPITECH PROJECT, 2019
** get movement coord
** File description:
** parser
*/

#include "../../../include/parser.h"

void save_coord(int type, movement_t *movement, char *tmp)
{
    if (type == 1)
        movement->start.x = str_to_int(tmp);
    else if (type == 2)
        movement->start.y = str_to_int(tmp);
    type = type;
    if (type == 3)
        movement->end.x = str_to_int(tmp);
    else if (type == 4)
        movement->end.y = str_to_int(tmp);
}

int get_coord(int i, char *coord, movement_t *movement, int type)
{
    int y = 0;
    char *tmp = malloc(sizeof(char) * my_strlen(coord));

    if (tmp == NULL)
        return (-1);
    for (i = i; coord[i] != ',' && coord[i] != ' ' && coord[i]; i++)
        tmp[y++] = coord[i];
    tmp[y] = '\0';
    if (is_num(tmp) == 0) {
        free(tmp);
        return (-1);
    }
    save_coord(type, movement, tmp);
    free(tmp);
    return (i);

}

movement_t *get_movement(movement_t *movement, char *line)
{
    char *coord = get_str(line, MOVE);
    int i = 0;

    if (coord == NULL)
        return (NULL);
    else if ((i = get_coord(i, coord, movement, 1)) == -1)
        return (NULL);
    for (i = i; (coord[i] == ' ' || coord[i] == ',') && coord[i]; i++);
    if ((i = get_coord(i, coord, movement, 2)) == -1)
        return (NULL);
    for (i = i; (coord[i] == ' ' || coord[i] == '-') && coord[i]; i++);
    if ((i = get_coord(i, coord, movement, 3)) == -1)
        return (NULL);
    for (i = i; (coord[i] == ' ' || coord[i] == ',') && coord[i]; i++);
    if ((i = get_coord(i, coord, movement, 4)) == -1)
        return (NULL);
    return (movement);
}
