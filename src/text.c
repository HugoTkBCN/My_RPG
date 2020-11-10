/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** drawin text
*/

#include "my_rpg.h"

void draw_text(sfRenderWindow *win, char *text, sfVector2f pos, int size)
{
    sfText *txt = sfText_create();
    sfFont *font = sfFont_createFromFile("fonts/title_font.ttf");

    if (!txt || !font)
        return;
    sfText_setFont(txt, font);
    sfText_setCharacterSize(txt, size);
    sfText_setString(txt, text);
    sfText_setPosition(txt, pos);
    sfRenderWindow_drawText(win, txt, 0);
    sfText_destroy(txt);
    sfFont_destroy(font);
}
