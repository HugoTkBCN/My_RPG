/*
** EPITECH PROJECT, 2019
** get only scene file to parse
** File description:
** parser
*/

#include "../../../include/parser.h"

char **get_only_scene_files(char **file_name)
{
    char **new_file_name = malloc(sizeof(char *) *
                        (my_lenline(file_name) + 1));
    int y = 0;

    if (new_file_name == NULL)
        return (NULL);
    for (int i = 0; file_name[i]; i++)
        if (is_scene_file(file_name[i]) == 1)
            new_file_name[y++] = my_strdup(file_name[i]);
    new_file_name[y] = NULL;
    free_array(file_name);
    return (new_file_name);
}
