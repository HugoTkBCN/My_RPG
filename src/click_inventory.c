/*
** EPITECH PROJECT, 2019
** click_inventory.c
** File description:
** objects in inventory
*/

#include "my_rpg.h"

int click_inventory_2(int text, int x, int y)
{
    if (x >= 1020 && x <= 1020 + 101 && y >= 425 && y <= 425 + 91)
        return (3);
    else if (x >= 1165 && x <= 1165 + 101 && y >= 425 && y <= 425 + 91)
        return (4);
    else
        return (text);

}

int click_inventory(sfMouseButtonEvent event, int text)
{
    int x = event.x;
    int y = event.y;

    if (x >= 710 && x <= 710 + 101 && y >= 425 && y <= 425 + 91)
        return (1);
    else if (x >= 870 && x <= 870 + 101 && y >= 425 && y <= 425 + 91)
        return (2);
    else
        return (click_inventory_2(text, x, y));
}
