/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** fonctions to animate the dialog
*/

#include "my_rpg.h"

int create_dialog(scene_t *scene, sfVector2f pos, sfVector2f size, char *mes)
{
    scene->dial.speed = 0.1;
    scene->dial.pos = pos;
    scene->dial.size = size;
    scene->dial.clock = sfClock_create();
    scene->dial.rect = sfRectangleShape_create();
    scene->dial.mes = sfText_create();
    scene->dial.font = sfFont_createFromFile(DIALOG);
    sfRectangleShape_setPosition(scene->dial.rect, pos);
    sfRectangleShape_setSize(scene->dial.rect, size);
    sfRectangleShape_setFillColor(scene->dial.rect, sfBlack);
    sfRectangleShape_setOutlineColor(scene->dial.rect, sfRed);
    sfRectangleShape_setOutlineThickness(scene->dial.rect, 4);
    scene->dial.text = mes;
    scene->dial.letter = 0;
}

char *put_linebreak(char *str, sfVector2f size, int len)
{
    int line = size.x / 8;
    int j = 0;
    char *new = malloc(sizeof(char) * (2 * len));

    for (int i = 0; i < 2 * len; i++)
        new[i] = '\0';
    for (int i = 0; str[i] != '\0'; i++, j++)
        if (i % line == 0 && i != 0) {
            new[j] = '\n';
        } else {
            new[j] = str[i];
        }
    return (new);
}

char *prep_str(char *str, int nb, dialog_t dial)
{
    char *new = malloc(sizeof(char) * nb + 1);

    if (new == NULL)
        return (NULL);
    else if (my_strlen(str) < nb)
        nb = my_strlen(str);
    for (int i = 0; i <= nb; i++)
        new[i] = '\0';
    for (int i = 0; i < nb && str[i] != '\0'; i++)
        new[i] = str[i];
    new = put_linebreak(new, dial.size, nb);
    return (new);
}

int update_dialog(scene_t *scene)
{
    char *str;
    sfTime time;
    sfVector2f pos = {scene->dial.pos.x + 10, scene->dial.pos.y + 10};

    if (!scene->dial.rect || !scene->dial.font || !scene->dial.mes
        || !scene->dial.clock)
        return (-1);
    time = sfClock_getElapsedTime(scene->dial.clock);
    if (sfTime_asSeconds(time) < scene->dial.speed)
        return (-1);
    sfText_setFont(scene->dial.mes, scene->dial.font);
    sfText_setCharacterSize(scene->dial.mes, 20);
    scene->dial.letter++;
    str = prep_str(scene->dial.text, scene->dial.letter, scene->dial);
    sfText_setString(scene->dial.mes, str);
    sfText_setColor(scene->dial.mes, sfWhite);
    sfText_setPosition(scene->dial.mes, pos);
    sfClock_restart(scene->dial.clock);
    free(str);
}
