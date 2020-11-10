/*
** EPITECH PROJECT, 2019
** free array
** File description:
** free
*/

#include <stdlib.h>

int my_lenline(char **array)
{
    int i = 0;

    for (i = 0; array[i]; i++);
    return (i);
}

void free_array(char **array)
{
    for (int i = my_lenline(array) - 1; i >= 0; i--)
        free(array[i]);
    free(array);
}
