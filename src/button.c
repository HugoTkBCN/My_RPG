/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** button func
*/

#include "my_rpg.h"

void display_button_array(sfRenderWindow *win, button_t **btns)
{
    for (int i = 0; btns[i]; i++)
        display_button(win, *btns[i]);
}

void display_button(sfRenderWindow *win, button_t button)
{
    sfText *txt = sfText_create();
    sfFont *font = sfFont_createFromFile("fonts/dialog_font.ttf");
    sfVector2f pos = sfRectangleShape_getPosition(button.rect);
    sfVector2f size = sfRectangleShape_getSize(button.rect);
    int midx = pos.x + size.x / 2 - my_strlen(button.text) * 8;
    int midy = pos.y + size.y / 2 - 30;

    if (!txt || !font) {
        my_putstr("Error: cannot create text\n");
        return;
    }
    sfRenderWindow_drawRectangleShape(win, button.rect, NULL);
    sfText_setFont(txt, font);
    sfText_setCharacterSize(txt, button.size);
    sfText_setString(txt, button.text ? button.text : "(null)");
    sfText_setColor(txt, sfWhite);
    sfText_setPosition(txt, (sfVector2f){midx, midy});
    sfRenderWindow_drawText(win, txt, 0);
    sfText_destroy(txt);
    sfFont_destroy(font);
}

int button_is_clicked(button_t *button, sfVector2i click_position)
{
    sfVector2f rect_pos = sfRectangleShape_getPosition(button->rect);
    sfVector2f rect_sz = sfRectangleShape_getSize(button->rect);
    int max_x = rect_pos.x + rect_sz.x;
    int max_y = rect_pos.y + rect_sz.y;

    if (click_position.x >= rect_pos.x && click_position.x <= max_x &&
        click_position.y >= rect_pos.y && click_position.y <= max_y) {
        return (1);
    } else
        return (0);
}

int check_btn_click(scene_t *scene, button_t **buttons)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(scene->win);
    sfVector2f posf = {pos.x, pos.y};

    for (int i = 0; buttons[i]; i++) {
        if (button_is_clicked(buttons[i], pos)) {
            return (buttons[i]->callback(scene));
        }
    }
}

void init_button(button_t *btn, char *txt, sfVector2f pos, sfVector2f size)
{
    sfColor color = {0, 17, 214, 200};

    btn->rect = sfRectangleShape_create();
    if (!btn || !btn->rect)
        return;
    sfRectangleShape_setPosition(btn->rect, pos);
    sfRectangleShape_setSize(btn->rect, size);
    sfRectangleShape_setFillColor(btn->rect, color);
    color.r += 100;
    sfRectangleShape_setOutlineColor(btn->rect, color);
    sfRectangleShape_setOutlineThickness(btn->rect, 6);
    btn->size = 55;
    btn->text = my_strdup(txt);
}
