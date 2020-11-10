/*
** EPITECH PROJECT, 2019
** move_char
** File description:
** move character
*/

#include "my_rpg.h"

void move_up(sfEvent event, sfSprite *sprite, int move[], scene_t *scene)
{
    if (sfKeyboard_isKeyPressed(sfKeyUp)) {
        sfSprite_setTextureRect(sprite, (sfIntRect) { move[0], 432, 80, 144 });
        sfSprite_move(sprite, (sfVector2f) { 0, -10 });
    }
}

void move_down(sfEvent event, sfSprite *sprite, int move[], scene_t *scene)
{
    if (sfKeyboard_isKeyPressed(sfKeyDown)) {
        sfSprite_setTextureRect(sprite, (sfIntRect) { move[1], 0, 80, 144 });
        sfSprite_move(sprite, (sfVector2f) { 0, 10 });
    }
}

void move_left(sfEvent event, sfSprite *sprite, int move[], scene_t *scene)
{
    if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
        sfSprite_setTextureRect(sprite, (sfIntRect) { move[3], 144, 80, 144 });
        sfSprite_move(sprite, (sfVector2f) { -10, 0 });
    }
}

void move_right(sfEvent event, sfSprite *sprite, int move[], scene_t *scene)
{
    if (sfKeyboard_isKeyPressed(sfKeyRight)) {
        sfSprite_setTextureRect(sprite, (sfIntRect) { move[2], 288, 80, 144 });
        sfSprite_move(sprite, (sfVector2f) { 10, 0 });
    }
}

void move_char(sfEvent event, game_object_t **objs, scene_t *scene)
{
    static int move[] = { 80, 0, 0, 0 };

    if (sfKeyboard_isKeyPressed(sfKeyRight) ||
        sfKeyboard_isKeyPressed(sfKeyLeft) ||
        sfKeyboard_isKeyPressed(sfKeyUp) ||
        sfKeyboard_isKeyPressed(sfKeyDown)) {
        check_ennemy(scene);
        add_walking_particule(scene);
    } else if (!objs)
        return;
    move_up(event, objs[1]->sprite, move, scene);
    move_left(event, objs[1]->sprite, move, scene);
    move_down(event, objs[1]->sprite, move, scene);
    move_right(event, objs[1]->sprite, move, scene);
    for (int i = 0; i < 4; i++) {
        if (move[i] == 240)
            move[i] = 0;
        else
            move[i] += 80;
    }
}
