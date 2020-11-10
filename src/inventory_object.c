/*
** EPITECH PROJECT, 2019
** inventory_object.c
** File description:
** inventory
*/

#include "my_rpg.h"

void destroy_inventory(inventory_object_t *inventory)
{
    sfSprite_destroy(inventory[0].sprite);
    sfTexture_destroy(inventory[0].texture);
    sfText_destroy(inventory[1].text);
    sfText_destroy(inventory[2].text);
    sfText_destroy(inventory[3].text);
    sfText_destroy(inventory[4].text);
}

int create_object_inv(inventory_object_t *inventory, char *filepath)
{
    inventory->sprite = sfSprite_create();
    inventory->texture = sfTexture_createFromFile(filepath, 0);
    if (!inventory->sprite || !inventory->texture)
        return (0);
    sfSprite_setTexture(inventory->sprite, inventory->texture, 0);
    sfSprite_setPosition(inventory->sprite, (sfVector2f) { 650, 200 });
    return (0);
}
