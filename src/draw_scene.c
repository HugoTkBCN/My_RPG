/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** drawing a scene
*/

#include "my_rpg.h"

void draw_dialog(dialog_t dial, scene_t *scene)
{
    if (!scene || !dial.rect || !dial.font || !dial.mes || !dial.clock)
        return;
    sfRenderWindow_drawRectangleShape(scene->win, dial.rect, 0);
    sfRenderWindow_drawText(scene->win, dial.mes, 0);
}

void draw_particules(scene_t *scene)
{
    for (particule_t *tmp = scene->particules; tmp; tmp = tmp->next)
        sfRenderWindow_drawSprite(scene->win, tmp->sprite, 0);
}

void draw_parsed_elem(scene_t *scene)
{
    sfRenderWindow_drawSprite(scene->win, scene->background->sprite, 0);
    for (int i = 0; scene->obstacle[i]; i++)
        sfRenderWindow_drawSprite(scene->win,
        scene->obstacle[i]->image->sprite, 0);
    for (int i = 0; scene->game_object[i]; i++)
        sfRenderWindow_drawSprite(scene->win,
        scene->game_object[i]->object->sprite, 0);
    for (int i = 0; scene->pnj[i]; i++)
        sfRenderWindow_drawSprite(scene->win,
        scene->pnj[i]->front->sprite, 0);
    for (int i = 0; scene->ennemy[i]; i++)
        sfRenderWindow_drawSprite(scene->win,
        scene->ennemy[i]->data->front->sprite, 0);
}

void draw_inventory(scene_t *scene, int text)
{
    if (scene->inventory[0].count == 1)
        sfRenderWindow_drawSprite(scene->win, scene->inventory[0].sprite, 0);
    for (int i = 1; i < 5; i++) {
        if (i == text && scene->inventory[0].count == 1)
            sfRenderWindow_drawText(scene->win, scene->inventory[i].text, 0);
    }
}

void draw_scene(scene_t *scene, int text)
{
    sfRenderWindow_clear(scene->win, sfWhite);
    draw_parsed_elem(scene);
    sfRenderWindow_drawSprite(scene->win, scene->objs[1]->sprite, 0);
    for (int i = 0; scene->objs[i]; i++) {
        if (i == 1)
            draw_particules(scene);
        else if (i != 0)
            sfRenderWindow_drawSprite(scene->win, scene->objs[i]->sprite, 0);
    }
    draw_inventory(scene, text);
    draw_dialog(scene->dial, scene);
    sfRenderWindow_display(scene->win);
}
