/*
** EPITECH PROJECT, 2019
** parse line background
** File description:
** parser
*/

#include "../../../include/parser.h"

scene_t *parse_background(char *line, scene_t *scene)
{
    scene->nbr_elements->nbr_background++;
    scene->background = create_image(scene->background, line);
    if (scene->nbr_elements->nbr_background > 1 || scene->background == NULL)
        return (NULL);
    return (scene);
}
