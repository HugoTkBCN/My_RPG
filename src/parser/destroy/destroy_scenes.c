/*
** EPITECH PROJECT, 2019
** destroy scenes
** File description:
** parser
*/

#include "../../../include/parser.h"

void destroy_scene_parser(scene_t *scene)
{
    scene->background != NULL ? destroy_image(scene->background) : 0;
    destroy_obstacles(scene->obstacle, scene->nbr_elements->nbr_obstacles);
    destroy_game_objects(scene->game_object,
                        scene->nbr_elements->nbr_game_objects);
    destroy_pnjs(scene->pnj, scene->nbr_elements->nbr_pnj);
    destroy_ennemies(scene->ennemy, scene->nbr_elements->nbr_ennemies);
    destroy_music(scene->music);
    destroy_sounds(scene->sound, scene->nbr_elements->nbr_sounds);
    free(scene->connection);
    free(scene);
}

void destroy_scenes_parser(scene_t **scenes)
{
    for (int i = 0; scenes[i]; i++)
        destroy_scene_parser(scenes[i]);
}
