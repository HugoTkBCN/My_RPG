/*
** EPITECH PROJECT, 2019
** destroy image_t and sprite_t
** File description:
** parser
*/

#include "../../../include/parser.h"

void destroy_image(image_t *image)
{
    sfSprite_destroy(image->sprite);
    sfTexture_destroy(image->texture);
    free(image);
}

void destroy_sprite(sprite_t *sprite)
{
    sfSprite_destroy(sprite->sprite);
    sfTexture_destroy(sprite->texture);
    free(sprite->rect);
    free(sprite);
}
