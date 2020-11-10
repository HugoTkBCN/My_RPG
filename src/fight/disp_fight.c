/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** display
*/

#include "my_rpg.h"
#include "fight.h"

void disp_fight(sfRenderWindow *win, fighter_t *gamer, fighter_t *opp,
                fight_t *fight)
{
    sfRenderWindow_clear(win, sfBlack);
    sfRenderWindow_drawSprite(win, fight->bg->sprite, NULL);
    sfRenderWindow_drawSprite(win, fight->p_spr, NULL);
    sfRenderWindow_drawSprite(win, fight->o_spr, NULL);
    sfRenderWindow_drawRectangleShape(win, fight->o_life, NULL);
    sfRenderWindow_drawRectangleShape(win, fight->p_life, NULL);
    for (int i = 0; gamer->attack[i]; i++) {
        sfRenderWindow_drawRectangleShape(win, gamer->attack[i]->rect, NULL);
        sfRenderWindow_drawText(win, gamer->attack[i]->text, NULL);
    }
    sfRenderWindow_display(win);
}

void draw_lost_screen(sfRenderWindow *win, fight_t *f)
{
    sfVector2f scale;

    scale.x = (float)WIN_WIDTH / (float)LOST_WID;
    scale.y = (float)WIN_HEIGHT / (float)LOST_HEI;
    is_fight_closed(win);
    sfSprite_setScale(f->lost->sprite, scale);
    sfRenderWindow_clear(win, sfBlack);
    sfRenderWindow_drawSprite(win, f->lost->sprite, NULL);
    sfRenderWindow_display(win);
}
