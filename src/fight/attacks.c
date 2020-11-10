/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** attack.c
*/

#include "my_rpg.h"
#include "fight.h"

void att(fight_t *f, attack_t *att, fighter_t *pl, fighter_t *opp)
{
    sfVector2f scale;

    if (f->p_spr != pl->idle->sprite)
        return;
    if (rand() % 100 < att->accuracy) {
        opp->life -= att->damage;
        f->o_spr = opp->death->sprite;
    }
    f->p_spr = pl->att->sprite;
    sfSprite_setPosition(f->p_spr, (sfVector2f){P_X, P_Y});
    sfSprite_setPosition(f->o_spr, (sfVector2f){O_X, O_Y});
    scale = sfSprite_getScale(f->o_spr);
    if (scale.x != -1)
        sfSprite_setScale(f->o_spr, (sfVector2f){-1, 1});
}

void opp_att(fight_t *f, attack_t *att, fighter_t *pl, fighter_t *opp)
{
    sfVector2f scale;

    if (rand() % 100 < att->accuracy) {
        pl->life -= att->damage;
        f->p_spr = pl->death->sprite;
    }
    f->o_spr = opp->att->sprite;
    sfSprite_setPosition(f->p_spr, (sfVector2f){P_X, P_Y});
    sfSprite_setPosition(f->o_spr, (sfVector2f){O_X, O_Y});
    scale = sfSprite_getScale(f->o_spr);
    if (scale.x != -1)
        sfSprite_setScale(f->o_spr, (sfVector2f){-1, 1});
}
