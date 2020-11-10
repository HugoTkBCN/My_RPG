/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** create_attack
*/

#include "my_rpg.h"
#include "fight.h"

void put_att_button(attack_t *att, sfVector2f pos, sfVector2f size)
{
    sfFont *font = sfFont_createFromFile(DIALOG);

    att->rect = sfRectangleShape_create();
    sfRectangleShape_setSize(att->rect, size);
    sfRectangleShape_setPosition(att->rect, pos);
    sfRectangleShape_setFillColor(att->rect, sfRed);
    sfRectangleShape_setOutlineColor(att->rect, sfBlack);
    att->text = sfText_create();
    sfText_setString(att->text, att->name);
    sfText_setCharacterSize(att->text, 30);
    sfText_setFont(att->text, font);
    sfText_setPosition(att->text, (sfVector2f){pos.x + 10, pos.y + 5});
    att->pos = pos;
    att->size = size;
}

void create_callback(attack_t **attack)
{
    attack[0]->callback = &att;
    attack[1]->callback = &att;
    attack[2]->callback = &att;
}

attack_t **create_attack(void)
{
    attack_t **attack = malloc(sizeof(attack_t *) * 4);

    for (int i = 0; i < 3; i++)
        attack[i] = malloc(sizeof(attack_t));
    attack[3] = NULL;
    attack[0]->damage = 40;
    attack[0]->accuracy = 20;
    attack[0]->name = "head";
    put_att_button(attack[0], (sfVector2f){200, 900}, (sfVector2f){200, 50});
    attack[1]->damage = 20;
    attack[1]->accuracy = 40;
    attack[1]->name = "leg";
    put_att_button(attack[1], (sfVector2f){450, 900}, (sfVector2f){200, 50});
    attack[2]->damage = 10;
    attack[2]->accuracy = 80;
    attack[2]->name = "body";
    put_att_button(attack[2], (sfVector2f){200, 960}, (sfVector2f){200, 50});
    create_callback(attack);
    return (attack);
}
