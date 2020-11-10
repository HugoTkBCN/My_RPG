/*
** EPITECH PROJECT, 2019
** parse line sound
** File description:
** parser
*/

#include "../../../include/parser.h"

scene_t *parse_sound(char *line, scene_t *scene)
{
    int nbr_sounds = scene->nbr_elements->nbr_sounds;

    scene->sound[nbr_sounds]->buffer =
    sfSoundBuffer_createFromFile(get_str(line, PATH));
    if (scene->sound[nbr_sounds]->buffer == NULL)
        return (NULL);
    scene->sound[nbr_sounds]->sound = sfSound_create();
    sfSound_setBuffer(scene->sound[nbr_sounds]->sound,
                        scene->sound[nbr_sounds]->buffer);
    scene->sound[nbr_sounds]->frequence = get_int(line, FREQUENCE);
    scene->sound[nbr_sounds]->zone =
    get_movement(scene->sound[nbr_sounds]->zone, line);
    scene->nbr_elements->nbr_sounds++;
    return (scene);
}
