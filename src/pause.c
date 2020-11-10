/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** pause screen
*/

#include "my_rpg.h"

int resume_pause(scene_t *scene)
{
    return (1);
}

int exit_pause(scene_t *scene)
{
    sfRenderWindow_close(scene->win);
    return (1);
}

int check_quit(scene_t *scene)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(scene->win, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(scene->win);
            return (1);
        }
    }
    return (0);
}

button_t **create_pause_button(void)
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
    init_button(btns[0], "Resume", pos, (sfVector2f){500, 100});
    pos.y += 150;
    init_button(btns[1], "Exit", pos, (sfVector2f){500, 100});
    btns[0]->callback = resume_pause;
    btns[1]->callback = exit_pause;
    return (btns);
}

int pause_screen(scene_t *scene)
{
    game_object_t *bg = create_object(PAUSE_BG, (sfIntRect){0, 0, 1920, 1080});
    button_t **btns = create_pause_button();
    int resume = 0;

    if (!btns || !bg)
        return (EXIT_ERROR);
    scene->particules = NULL;
    while (sfRenderWindow_isOpen(scene->win) && !resume) {
        sfRenderWindow_clear(scene->win, sfBlack);
        sfRenderWindow_drawSprite(scene->win, bg->sprite, 0);
        display_button_array(scene->win, btns);
        draw_text(scene->win, "Pause", (sfVector2f){730, 120}, 100);
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue)
            resume = check_btn_click(scene, btns);
        check_quit(scene);
        sfRenderWindow_display(scene->win);
    }
    destroy_button_array(btns);
    destroy_game_object(bg);
    return (0);
}
