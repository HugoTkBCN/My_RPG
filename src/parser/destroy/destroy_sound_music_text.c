/*
** EPITECH PROJECT, 2019
** destroy sound_t and music_t and text_t
** File description:
** parser
*/

#include "../../../include/parser.h"

void destroy_text(text_t *text)
{
    text->text != NULL ? sfText_destroy(text->text) : 0;
    text->font != NULL ? sfFont_destroy(text->font) : 0;
    text->string != NULL ? free(text->string) : 0;
}

void destroy_music(music_t *music)
{
    music->music != NULL ? sfMusic_destroy(music->music) : 0;
    music->text != NULL ? destroy_text(music->text) : 0;
    music != NULL ? free(music) : 0;
}

void destroy_sounds(sound_t **sound, int nbr_sounds)
{
    int i = 0;

    for (i = nbr_sounds - 1; i >= 0; i--) {
        sound[i]->sound != NULL ? sfSound_destroy(sound[i]->sound) : 0;
        sound[i]->buffer != NULL ? sfSoundBuffer_destroy(sound[i]->buffer) : 0;
        sound[i]->zone != NULL ? free(sound[i]->zone) : 0;
        sound[i] != NULL ? free(sound[i]) : 0;
    }
    sound != NULL ? free(sound): 0;
}
