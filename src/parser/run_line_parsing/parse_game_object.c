/*
** EPITECH PROJECT, 2019
** parse line game object
** File description:
** parser
*/

#include "../../../include/parser.h"

scene_t *parse_game_object(char *line, scene_t *scene)
{
    int nbr_game_objects = scene->nbr_elements->nbr_game_objects;

    scene->game_object[nbr_game_objects]->name = get_str(line, NAME);
    scene->game_object[nbr_game_objects]->description =
        get_str(line, DESCRIPTION);
    scene->game_object[nbr_game_objects]->object =
        create_image(scene->game_object[nbr_game_objects]->object, line);
    if (scene->game_object[nbr_game_objects]->object == NULL)
        return (NULL);
    scene->nbr_elements->nbr_game_objects++;
    return (scene);
}
