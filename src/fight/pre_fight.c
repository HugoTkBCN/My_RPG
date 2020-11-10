/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** pre_fight
*/

#include "my_rpg.h"
#include "fight.h"

fighter_t *prep_fighter(int life, int max)
{
    fighter_t *f = malloc(sizeof(fighter_t));

    if (!f)
        return (NULL);
    f->life = life;
    f->max_life = max;
    f->clock = sfClock_create();
    return (f);
}

void prep_sprite_player(fighter_t *p, char *att, char *death, char *idle)
{
    p->att = create_object(att, (sfIntRect){0, 0, FCHAR_WID, FCHAR_HEI});
    p->death = create_object(death, (sfIntRect){0, 0, FCHAR_WID, FCHAR_HEI});
    p->idle = create_object(idle, (sfIntRect){0, 0, FCHAR_WID, FCHAR_HEI});
}

void prep_life(fight_t *fig)
{
    sfVector2f pos = {30, 30};

    fig->o_life = sfRectangleShape_create();
    fig->p_life = sfRectangleShape_create();
    if (!fig->o_life || !fig->p_life)
        return;
    sfRectangleShape_setPosition(fig->p_life, pos);
    pos.x = WIN_WIDTH - 30;
    sfRectangleShape_setPosition(fig->o_life, pos);
    sfRectangleShape_setScale(fig->o_life, (sfVector2f){-1, 1});
}

void prep_displayed_sprite(fight_t *fig, fighter_t *player, fighter_t *opp)
{
    fig->lost = create_object(LOST, (sfIntRect){0, 0, LOST_WID, LOST_HEI});
    fig->p_spr = player->idle->sprite;
    sfSprite_setPosition(fig->p_spr, (sfVector2f){P_X, P_Y});
    fig->o_spr = opp->idle->sprite;
    sfSprite_setPosition(fig->o_spr, (sfVector2f){O_X, O_Y});
    sfSprite_setScale(fig->o_spr, (sfVector2f){-1, 1});
}

fight_t *prepare_fight(fighter_t *player, fighter_t *opp)
{
    fight_t *fig = malloc(sizeof(fight_t));

    if (!fig)
        return (NULL);
    player->attack = create_attack();
    opp->attack = create_attack();
    fig->s_buf = malloc(sizeof(sfSoundBuffer *));
    fig->sound = malloc(sizeof(sfSound *));
    fig->bg = create_object(F_BACK, (sfIntRect){0, 0, WIN_WIDTH, WIN_HEIGHT});
    fig->clock = sfClock_create();
    prep_sprite_player(player, ATT, DEAD, STAND);
    prep_sprite_player(opp, O_ATT, O_DEATH, O_IDLE);
    prep_life(fig);
    if (!fig->s_buf || !fig->sound || !fig->o_life || !fig->p_life || !fig->bg)
        return (NULL);
    fig->finished = 1;
    prep_displayed_sprite(fig, player, opp);
    fig->s_buf[0] = NULL;
    fig->sound[0] = NULL;
    return (fig);
}
