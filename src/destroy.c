/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** destroy
*/

#include "my_rpg.h"

void destroy_button(button_t *btn)
{
    sfRectangleShape_destroy(btn->rect);
    free(btn);
}

void destroy_button_array(button_t **btn)
{
    for (int i = 0; btn[i]; i++)
        destroy_button(btn[i]);
}

void destroy_game_object(game_object_t *obj)
{
    sfSprite_destroy(obj->sprite);
    sfTexture_destroy(obj->texture);
    free(obj);
}

void destroy_particule(scene_t *scene, particule_t *p)
{
    if (p->previous && !p->next)
        p->previous->next = NULL;
    else if (p->previous && p->next)
        p->previous->next = p->next;
    p = p;
    if (!p->previous && !p->next)
        scene->particules = NULL;
    else if (!p->previous && p->next)
        scene->particules = p->next;
}
