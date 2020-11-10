/*
** EPITECH PROJECT, 2019
** create sprite and image
** File description:
** parser
*/

#include "../../../include/parser.h"

image_t *create_image(image_t *image, char *line)
{
    char *file_path = get_str(line, PATH);

    if (file_path == NULL)
        return (NULL);
    image->texture = sfTexture_createFromFile(file_path, NULL);
    if (image->texture == NULL)
        return (NULL);
    image->sprite = sfSprite_create();
    image->position.x = get_int(line, X);
    image->position.y = get_int(line, Y);
    if (image->position.x == -1 || image->position.y == -1 )
        return (NULL);
    sfSprite_setTexture(image->sprite, image->texture, sfTrue);
    sfSprite_setPosition(image->sprite, image->position);
    free(file_path);
    return (image);
}

sprite_t *create_sprite(sprite_t *sprite, char *file_path, sfVector2f position)
{
    if (file_path == NULL)
        return (NULL);
    sprite->texture = sfTexture_createFromFile(file_path, NULL);
    if (sprite->texture == NULL)
        return (NULL);
    sprite->sprite = sfSprite_create();
    sfSprite_setTexture(sprite->sprite, sprite->texture, sfTrue);
    sfSprite_setPosition(sprite->sprite, position);
    sprite->rect->top = 0;
    sprite->rect->left = 0;
    sprite->rect->width = 0;
    sprite->rect->height = 0;
    free(file_path);
    return (sprite);
}

sprite_battle_t *create_sprites_battle(sprite_battle_t *sprite_battle,
                                char *line, sfVector2f position)
{
    sprite_battle->attack = create_sprite(sprite_battle->attack,
                                get_str(line, PATH_ATTACK), position);
    sprite_battle->dead = create_sprite(sprite_battle->dead,
                                get_str(line, PATH_DEAD), position);
    sprite_battle->normal = create_sprite(sprite_battle->normal,
                                get_str(line, PATH_NORMAL), position);
    if (sprite_battle->attack == NULL || sprite_battle->dead == NULL ||
        sprite_battle->normal == NULL)
        return (NULL);
    return (sprite_battle);
}

pnj_t *create_all_sprites(pnj_t *pnj, char *line, sfVector2f position)
{
    pnj->front = create_sprite(pnj->front, get_str(line, PATH_FRONT), position);
    pnj->back = create_sprite(pnj->back, get_str(line, PATH_BACK), position);
    pnj->left = create_sprite(pnj->left, get_str(line, PATH_LEFT), position);
    pnj->right = create_sprite(pnj->right, get_str(line, PATH_RIGHT), position);
    if (pnj->front == NULL || pnj->back == NULL ||
        pnj->left == NULL || pnj->right == NULL)
        return (NULL);
    return (pnj);
}
