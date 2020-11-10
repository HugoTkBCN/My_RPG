/*
** EPITECH PROJECT, 2019
** malloc obstacle_t and object_t
** File description:
** parser
*/

#include "../../../include/parser.h"

obstacle_t **malloc_obstacle(obstacle_t **obstacle, char **file)
{
    int i = 0;

    obstacle = malloc(sizeof(obstacle_t *) *
                    (get_nbr_in_file(file, OBSTACLE) + 1));
    if (obstacle == NULL)
        return (NULL);
    for (i = 0; i < get_nbr_in_file(file, OBSTACLE); i++) {
        obstacle[i] = malloc(sizeof(obstacle_t));
        if (obstacle[i] == NULL)
            return (NULL);
        obstacle[i]->image = malloc(sizeof(image_t));
        if (obstacle[i]->image == NULL)
            return (NULL);
    }
    obstacle[i] = NULL;
    return (obstacle);
}

object_t **malloc_game_object(object_t **game_object, char **file)
{
    int  i = 0;

    if ((game_object = malloc(sizeof(object_t *) *
                        (get_nbr_in_file(file, GAME_OBJECT) + 1))) == NULL)
        return (NULL);
    for (i = 0; i < get_nbr_in_file(file, GAME_OBJECT); i++) {
        if ((game_object[i] = malloc(sizeof(object_t))) == NULL)
            return (NULL);
        else if ((game_object[i]->object = malloc(sizeof(image_t))) == NULL)
            return (NULL);
        game_object[i]->name = malloc(sizeof(char) * (LEN_NAME_MAX + 1));
        if (game_object[i]->name == NULL)
            return (NULL);
        else if ((game_object[i]->description = malloc(sizeof(char) *
                                        (LEN_DESCRIPTION_MAX + 1))) == NULL)
            return (NULL);
    }
    game_object[i] = NULL;
    return (game_object);
}
