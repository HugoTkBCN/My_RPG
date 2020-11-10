/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** create_window
*/

#include "../include/my_rpg.h"

sfRenderWindow *create_window(int height, int width)
{
    sfVideoMode mode = {width, height, 32};
    sfRenderWindow *window = sfRenderWindow_create(mode, NAME_GAME, sfClose, 0);

    if (!window)
        return (NULL);
    sfRenderWindow_setFramerateLimit(window, FPS);
    return (window);
}
