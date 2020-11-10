/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** menu scene
*/

#include "my_rpg.h"

button_t **create_menu_buttons(void)
{
    button_t **btns = malloc(sizeof(button_t * ) * 3);
    sfVector2f pos = {700, 400};

    if (!btns)
        return (0);
    btns[0] = malloc(sizeof(button_t));
    btns[1] = malloc(sizeof(button_t));
    btns[2] = 0;
    if (!btns[0] || !btns[1])
        return (0);
    init_button(btns[0], "Start", pos, (sfVector2f){500, 100});
    pos.y += 150;
    init_button(btns[1], "Exit", pos, (sfVector2f){500, 100});
    btns[0]->callback = resume_pause;
    btns[1]->callback = exit_pause;
    return (btns);
}

scene_t *create_menu_scene(void)
{
    scene_t *scene = malloc(sizeof(scene_t));
    sfIntRect rect = {0, 0, WIN_WIDTH, WIN_HEIGHT};

    if (!scene)
        return (0);
    scene->win = create_window(WIN_HEIGHT, WIN_WIDTH);
    scene->objs = malloc(sizeof(game_object_t *) * 2);
    scene->objs[0] = create_object(MENU_IMG, rect);
    scene->objs[1] = 0;
    if (!scene->objs)
        return (0);
    return (scene);

}

void draw_menu_scene(scene_t *scene, button_t **btns)
{
    sfRenderWindow_drawSprite(scene->win, scene->objs[0]->sprite, 0);
    display_button_array(scene->win, btns);
    draw_text(scene->win, NAME_GAME, (sfVector2f){650, 120}, 120);
    sfRenderWindow_display(scene->win);
}

sfRenderWindow *menu(void)
{
    scene_t *scene = create_menu_scene();
    int close = 0;
    button_t **buttons = create_menu_buttons();

    if (!scene || !buttons)
        return (0);
    while (sfRenderWindow_isOpen(scene->win) && !close) {
        check_quit(scene);
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue)
            close = check_btn_click(scene, buttons);
        draw_menu_scene(scene, buttons);
    }
    destroy_game_object(scene->objs[0]);
    destroy_button_array(buttons);
    return (scene->win);
}
