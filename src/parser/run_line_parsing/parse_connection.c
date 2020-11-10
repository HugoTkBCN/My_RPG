/*
** EPITECH PROJECT, 2019
** parse line connection
** File description:
** parser
*/

#include "../../../include/parser.h"

scene_t *parse_connection(char *line, scene_t *scene)
{
    scene->connection->top = get_int(line, TOP);
    scene->connection->bottom = get_int(line, BOTTOM);
    scene->connection->left = get_int(line, LEFT);
    scene->connection->right = get_int(line, RIGHT);
    return (scene);
}
