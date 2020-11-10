/*
** EPITECH PROJECT, 2019
** myrpg
** File description:
** game_obj
*/

#include "my_rpg.h"

void destroy_object(game_object_t *obj)
{
    sfSprite_destroy(obj->sprite);
    sfTexture_destroy(obj->texture);
}

game_object_t *create_object(char *filepath, sfIntRect rect)
{
    game_object_t *obj = malloc(sizeof(game_object_t));

    if (!obj)
        return (0);
    obj->sprite = sfSprite_create();
    obj->texture = sfTexture_createFromFile(filepath, 0);
    if (!obj->sprite || !obj->texture)
        return (0);
    sfSprite_setTextureRect(obj->sprite, rect);
    sfSprite_setTexture(obj->sprite, obj->texture, 0);
    return (obj);
}
