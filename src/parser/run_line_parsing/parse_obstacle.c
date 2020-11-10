/*
** EPITECH PROJECT, 2019
** parse line obstacle
** File description:
** parser
*/

#include "../../../include/parser.h"

scene_t *parse_obstacle(char *line, scene_t *scene)
{
    int nbr_obstacles = scene->nbr_elements->nbr_obstacles;

    scene->obstacle[nbr_obstacles]->image =
        create_image(scene->obstacle[nbr_obstacles]->image, line);
    if (scene->obstacle[nbr_obstacles]->image == NULL)
        return (NULL);
    scene->nbr_elements->nbr_obstacles++;
    return (scene);
}
