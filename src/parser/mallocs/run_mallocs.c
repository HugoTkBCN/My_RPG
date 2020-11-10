/*
** EPITECH PROJECT, 2019
** malloc all the scene
** File description:
** parser
*/

#include "../../../include/parser.h"

scene_t *malloc_all_the_scene_2(char **file, scene_t *scene)
{
    scene->music = malloc_music(scene->music);
    if (scene->music == NULL)
        return (NULL);
    scene->sound = malloc_sounds(scene->sound, file);
    if (scene->sound == NULL)
        return (NULL);
    scene->connection = malloc(sizeof(connection_t));
    if (scene->connection == NULL)
        return (NULL);
    scene->nbr_elements = malloc(sizeof(elements_t));
    if (scene->nbr_elements == NULL)
        return (NULL);
    return (scene);
}

scene_t *malloc_all_the_scene(char **file, scene_t *scene)
{
    scene = malloc(sizeof(scene_t));
    if (scene == NULL)
        return (NULL);
    scene->background = malloc(sizeof(image_t));
    if (scene->background == NULL)
        return (NULL);
    scene->obstacle = malloc_obstacle(scene->obstacle, file);
    if (scene->obstacle == NULL)
        return (NULL);
    scene->game_object = malloc_game_object(scene->game_object, file);
    if (scene->game_object == NULL)
        return (NULL);
    scene->pnj = malloc_pnj(scene->pnj, file);
    if (scene->pnj == NULL)
        return (NULL);
    scene->ennemy = malloc_ennemy(scene->ennemy, file);
    if (scene->ennemy == NULL)
        return (NULL);
    return (malloc_all_the_scene_2(file, scene));
}
