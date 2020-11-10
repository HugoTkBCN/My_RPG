/*
** EPITECH PROJECT, 2019
** getfile_in array
** File description:
** put file in array
*/

#include "../../include/my_rpg.h"

int get_nbr_line_in_file(char *filepath)
{
    FILE *fd = fopen(filepath, "r");
    size_t size = 0;
    char *line = NULL;
    int nbr_line = 0;

    if (fd == NULL)
        return (-1);
    for (int i = 0; getline(&line, &size, fd) != -1; i++) {
        nbr_line++;
    }
    fclose(fd);
    return (nbr_line);
}

char **get_file(char *filepath)
{
    char **array = malloc(sizeof(char *) *
                    (get_nbr_line_in_file(filepath) + 1));
    FILE *fd = fopen(filepath, "r");
    size_t size = 0;
    char *line = NULL;
    int i = 0;

    if (fd == NULL || array == NULL)
        return (NULL);
    for (i = 0; getline(&line, &size, fd) != -1; i++)
        array[i] = my_strdup(line);
    if (i == 0)
        return (NULL);
    array[i] = NULL;
    free(line);
    fclose(fd);
    return (array);
}
