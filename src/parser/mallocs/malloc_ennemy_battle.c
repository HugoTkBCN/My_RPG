/*
** EPITECH PROJECT, 2019
** malloc ennemy_t and sprite_battle.c
** File description:
** parser
*/

#include "../../../include/parser.h"

sprite_battle_t *malloc_sprites_battle(sprite_battle_t *sprite_battle)
{
    sprite_battle = malloc(sizeof(sprite_battle_t));
    if (sprite_battle == NULL)
        return (NULL);
    else if ((sprite_battle->attack = malloc(sizeof(sprite_t))) == NULL)
        return (NULL);
    sprite_battle->attack->rect = malloc(sizeof(sfIntRect));
    if (sprite_battle->attack->rect == NULL)
        return (NULL);
    else if ((sprite_battle->dead = malloc(sizeof(sprite_t))) == NULL)
        return (NULL);
    sprite_battle->dead->rect = malloc(sizeof(sfIntRect));
    if (sprite_battle->dead->rect == NULL)
        return (NULL);
    else if ((sprite_battle->normal = malloc(sizeof(sprite_t))) == NULL)
        return (NULL);
    sprite_battle->normal->rect = malloc(sizeof(sfIntRect));
    if (sprite_battle->normal->rect == NULL)
        return (NULL);
    return (sprite_battle);
}

ennemy_t **malloc_ennemy(ennemy_t **ennemy, char **file)
{
    int i = 0;

    ennemy = malloc(sizeof(ennemy_t *) * (get_nbr_in_file(file, ENNEMY) + 1));
    if (ennemy == NULL)
        return (NULL);
    for (i = 0; i < get_nbr_in_file(file, ENNEMY); i++) {
        ennemy[i] = malloc(sizeof(ennemy_t));
        if (ennemy[i] == NULL)
            return (NULL);
        else if ((ennemy[i]->data = malloc_one_pnj(ennemy[i]->data)) == NULL)
            return (NULL);
        ennemy[i]->sprite_battle =
            malloc_sprites_battle(ennemy[i]->sprite_battle);
        if (ennemy[i]->sprite_battle == NULL)
            return (NULL);
    }
    ennemy[i] = NULL;
    return (ennemy);
}
