/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** creating scenes
*/

#include "my_rpg.h"

void destroy_scene(scene_t *scene)
{
    for (int i = 0; scene->objs[i]; i++)
        destroy_object(scene->objs[i]);
    destroy_inventory(scene->inventory);
    if (sfRenderWindow_isOpen(scene->win))
        sfRenderWindow_close(scene->win);
}

scene_t *create_main_scene(scene_t *scene, sfRenderWindow *win)
{
    sfIntRect rect = {0, 0, WIN_WIDTH, WIN_HEIGHT};
    sfIntRect char_rect = {0, 0, CHAR_WID, CHAR_HEI};

    if (!scene)
        return (0);
    scene->win = win;
    scene->objs = malloc(sizeof(game_object_t) * 3);
    if (!scene->objs)
        return (0);
    scene->inventory = malloc(sizeof(inventory_object_t) * 6);
    if (!scene->inventory)
        return (0);
    scene->objs[0] = create_object(SCENE1, rect);
    scene->objs[1] = create_object(CHAR, char_rect);
    scene->objs[2] = 0;
    create_object_inv(scene->inventory, INVENTORY);
    sfSprite_setPosition(scene->objs[1]->sprite, (sfVector2f){700, 200});
    scene->dial.rect = NULL;
    scene->particules = NULL;
    return (scene);
}
