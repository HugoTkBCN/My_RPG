/*
** EPITECH PROJECT, 2019
** destroy game_obj and obstacle
** File description:
** parser
*/

#include "../../../include/parser.h"

void destroy_obstacles(obstacle_t **obstacle, int nbr_obstacles)
{
    int i = 0;

    for (i = nbr_obstacles - 1; i >= 0; i--) {
        obstacle[i]->image != NULL ? destroy_image(obstacle[i]->image) : 0;
        obstacle[i] != NULL ? free(obstacle[i]) : 0;
    }
    obstacle != NULL ? free(obstacle) : 0;
}

void destroy_game_objects(object_t **game_object, int nbr_game_object)
{
    int i = 0;

    for (i = nbr_game_object - 1; i >= 0; i--) {
        game_object[i]->object != NULL ?
            destroy_image(game_object[i]->object) : 0;
        game_object[i]->name != NULL ? free(game_object[i]->name) : 0;
        game_object[i]->description != NULL ?
            free(game_object[i]->description) : 0;
        game_object[i] != NULL ? free(game_object[i]) : 0;
    }
    game_object != NULL ? free(game_object) : 0;
}
