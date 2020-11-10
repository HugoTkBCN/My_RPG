/*
** EPITECH PROJECT, 2019
** inventory.c
** File description:
** if inventory
*/

#include "my_rpg.h"

int inventory(scene_t *scene, sfEvent event, int text)
{
    static int count = 0;

    if (sfKeyboard_isKeyPressed(sfKeyZ) && count == 1) {
        scene->inventory[0].count = 2;
        count = 0;
        sfSprite_setScale(scene->inventory[0].sprite, (sfVector2f) { 0, 0 });
    } else if (sfKeyboard_isKeyPressed(sfKeySpace))
        count = 1;
    else
        count = count;
    if (count == 1) {
        scene->inventory[0].count = 1;
        sfSprite_setScale(scene->inventory[0].sprite, (sfVector2f) { 1, 1 });
        if (event.type == sfEvtMouseButtonPressed)
            text = click_inventory(event.mouseButton, text);
    }
    return (text);
}
