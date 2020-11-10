/*
** EPITECH PROJECT, 2019
** malloc sound_t music_t
** File description:
** parser
*/

#include "../../../include/parser.h"

music_t *malloc_music(music_t *music)
{
    music = malloc(sizeof(music_t));
    if (music == NULL)
        return (NULL);
    music->text = malloc(sizeof(text_t));
    if (music->text == NULL)
        return (NULL);
    music->text->string = malloc(sizeof(char) * 4);
    if (music->text->string == NULL)
        return (NULL);
    return (music);
}

sound_t **malloc_sounds(sound_t **sound, char **file)
{
    int i = 0;

    sound = malloc(sizeof(sound_t *) * (get_nbr_in_file(file, SOUND) + 1));
    if (sound == NULL)
        return (NULL);
    for (i = 0; i < get_nbr_in_file(file, SOUND); i++) {
        sound[i] = malloc(sizeof(sound_t));
        if (sound[i] == NULL)
            return (NULL);
        sound[i]->zone = malloc(sizeof(movement_t));
        if (sound[i]->zone == NULL)
            return (NULL);
    }
    sound[i] = NULL;
    return (sound);
}
