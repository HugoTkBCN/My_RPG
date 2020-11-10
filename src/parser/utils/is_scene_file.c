/*
** EPITECH PROJECT, 2019
** is scene file
** File description:
** parser
*/

#include "../../../include/parser.h"

int is_scene_file(char *name)
{
    int i = 0;
    int y = 0;

    for (i = 0; name[i] != '.' && name[i]; i++);
    for (i = i; i < my_strlen(name) && DOT_SCENE[y]; i++) {
        if (name[i] != DOT_SCENE[y++])
            return (0);
    }
    if (i != my_strlen(name))
        return (0);
    return (1);
}
