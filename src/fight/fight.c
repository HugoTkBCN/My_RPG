/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** fight
*/
#include "my_rpg.h"
#include "fight.h"

int is_fight_closed(sfRenderWindow *win)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(win, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(win);
            return (0);
        }
    }
    return (0);
}

void update_life(fight_t *fight, fighter_t *gamer, fighter_t *opp)
{
    sfVector2f size;
    sfTime time = sfClock_getElapsedTime(opp->clock);

    if (sfTime_asSeconds(time) > 1) {
        opp_att(fight, opp->attack[1], gamer, opp);
        sfClock_restart(opp->clock);
    }
    sfRectangleShape_setFillColor(fight->o_life, sfRed);
    sfRectangleShape_setFillColor(fight->p_life, sfRed);
    size.y = 20;
    size.x = (LEN_LIFE * opp->life) / opp->max_life;
    sfRectangleShape_setSize(fight->o_life, size);
    size.x = (LEN_LIFE * gamer->life) / gamer->max_life;
    sfRectangleShape_setSize(fight->p_life, size);
}

void update_sprite(fight_t *f, fighter_t *pl, fighter_t *opp)
{
    sfIntRect rect = sfSprite_getTextureRect(f->p_spr);

    if (sfTime_asSeconds(sfClock_getElapsedTime(f->clock)) < 0.05)
        return;
    sfClock_restart(f->clock);
    if (rect.left >= MAX_WID - FCHAR_WID) {
        rect.left = 0;
        sfSprite_setTextureRect(f->p_spr, rect);
        f->p_spr = pl->idle->sprite;
    } else
        rect.left += rect.width;
    sfSprite_setTextureRect(f->p_spr, rect);
    rect = sfSprite_getTextureRect(f->o_spr);
    if (rect.left >= MAX_WID - FCHAR_WID) {
        rect.left = 0;
        sfSprite_setTextureRect(f->o_spr, rect);
        f->o_spr = opp->idle->sprite;
    } else
        rect.left += rect.width;
    sfSprite_setTextureRect(f->o_spr, rect);
}

void check_fight_click(sfRenderWindow *win, fight_t *fight, fighter_t *pl,
                       fighter_t *opp)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(win);

    for (int i = 0; pl->attack[i]; i++) {
        if (pl->attack[i]->pos.x <= pos.x && pl->attack[i]->pos.y <= pos.y &&
            pl->attack[i]->pos.x + pl->attack[i]->size.x >= pos.x &&
            pl->attack[i]->pos.y + pl->attack[i]->size.y >= pos.y) {
            pl->attack[i]->callback(fight, pl->attack[i], pl, opp);
        }
    }
}

int fight(sfRenderWindow *win, fighter_t *player, fighter_t *opp)
{
    fight_t *fight = prepare_fight(player, opp);

    if (!fight || !win || !player || !opp)
        return (84);
    fight->mus = sfMusic_createFromFile(F_THEME);
    sfMusic_setLoop(fight->mus, sfTrue);
    sfMusic_play(fight->mus);
    while (opp->life > 0 && player->life > 0 && sfRenderWindow_isOpen(win)) {
        is_fight_closed(win);
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue)
            check_fight_click(win, fight, player, opp);
        update_life(fight, player, opp);
        update_sprite(fight, player, opp);
        disp_fight(win, player, opp, fight);
    }
    while (player->life <= 0 && sfRenderWindow_isOpen(win))
        draw_lost_screen(win, fight);
    sfMusic_destroy(fight->mus);
    return (player->life);
}
