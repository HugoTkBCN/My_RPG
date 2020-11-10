/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** main file
*/

#include "my_rpg.h"
#include "fight.h"
#include "parser.h"

int poll_event(scene_t *scene, sfClock *clock, int text)
{
    sfEvent event;
    sfTime time = sfClock_getElapsedTime(clock);

    while (sfRenderWindow_pollEvent(scene->win, &event) && WIN_OPEN) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(scene->win);
            return (1);
        } else if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
            pause_screen(scene);
    }
    if (sfTime_asSeconds(time) > 0.03) {
        move_char(event, scene->objs, scene);
        sfClock_restart(clock);
    }
    text = inventory(scene, event, text);
    return (text);
}

int check_change_scene(scene_t *scene, int actual_scene)
{
    sfVector2f pos_perso = sfSprite_getPosition(scene->objs[1]->sprite);

    if (pos_perso.y <= 100)
        return (scene->connection->top);
    else if (pos_perso.y >= 980)
        return (scene->connection->bottom);
    pos_perso = pos_perso;
    if (pos_perso.x <= 100)
        return (scene->connection->left);
    else if (pos_perso.x >= 1820)
        return (scene->connection->right);
    return (actual_scene);
}

void check_ennemy(scene_t *s)
{
    sfVector2f pos = sfSprite_getPosition(s->objs[1]->sprite);
    fighter_t *player;
    fighter_t *opp;
    static int nb_fights = 0;

    if (rand() % 1000 < 20) {
        player = prep_fighter(100, 100);
        opp = prep_fighter(100, 100);
        if (!opp || !player || !s->win)
            return;
        s->particules = NULL;
        if (fight(s->win, player, opp) > 0)
            nb_fights++;
        player->life = 100;
    }
    if (nb_fights != 10)
        return;
    create_dialog(s, (sfVector2f){500, 500}, (sfVector2f){340, 100},
                 "CONGRATULATION YOU DID IT!!!! Now you're the Boss!!");
}

int my_rpg(sfRenderWindow *win)
{
    scene_t **scenes = run_parsing(win);
    sfClock *clock = sfClock_create();
    int actual_scene = 0;
    int text = 0;

    if (scenes == NULL)
        return (84);
    create_dialog(scenes[0], (sfVector2f){20, 800}, (sfVector2f){340, 100},
                 "Kill 10 opponents! You can find them in the grass");
    inventory_description(scenes[actual_scene]);
    while (sfRenderWindow_isOpen(scenes[actual_scene]->win)) {
        check_particules(scenes[actual_scene]);
        update_dialog(scenes[actual_scene]);
        draw_scene(scenes[actual_scene], text);
        text = poll_event(scenes[actual_scene], clock, text);
        actual_scene = check_change_scene(scenes[actual_scene], actual_scene);
    }
    destroy_scene(scenes[0]);
    destroy_scenes_parser(scenes);
    return (0);
}
