/*
** EPITECH PROJECT, 2019
** parse line music
** File description:
** parser
*/

#include "../../../include/parser.h"

scene_t *parse_music(char *line, scene_t *scene)
{
    scene->music->text->font = sfFont_createFromFile(PATH_TO_FONT_VOLUME);
    scene->music->text->string = my_strdup(int_to_str(VOLUME_DEFAULT));
    scene->music->text->color = sfColor_fromRGB(255, 255, 255);
    scene->music->text->position.x = POS_X_VOLUME;
    scene->music->text->position.y = POS_Y_VOLUME;
    scene->music->music = sfMusic_createFromFile(get_str(line, PATH));
    scene->music->volume = VOLUME_DEFAULT;
    scene->music->text->text = sfText_create();
    sfText_setString(scene->music->text->text, scene->music->text->string);
    sfText_setFont(scene->music->text->text, scene->music->text->font);
    sfText_setCharacterSize(scene->music->text->text, SIZE_CHAR_VOLUME);
    sfText_setColor(scene->music->text->text, scene->music->text->color);
    sfText_setPosition(scene->music->text->text, scene->music->text->position);
    return (scene);
}
