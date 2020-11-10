 /*
** EPITECH PROJECT, 2019
** inventory_description.c
** File description:
** description
*/

#include "my_rpg.h"

sfText *create_description(char *msg)
{
    sfFont *font = sfFont_createFromFile(DIALOG);
    sfText *text = sfText_create();

    sfText_setFont(text, font);
    sfText_setPosition(text, (sfVector2f) { 725, 645 });
    sfText_setCharacterSize(text, 30);
    sfText_setString(text, msg);
    sfText_setFillColor(text, sfBlack);
    return (text);
}

void inventory_description(scene_t *scene)
{
    scene->inventory[1].text = create_description(
        "Your mentor's gun. He give it to you.\nTake care of it!");
    scene->inventory[2].text = create_description(
        "Your favorite beer. Drink it to restore health.");
    scene->inventory[3].text = create_description(
        "The town's map. It smells weird...");
    scene->inventory[4].text = create_description(
        "Flowers for your mama.");
}
