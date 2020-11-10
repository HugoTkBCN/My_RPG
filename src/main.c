/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** exemple
*/

#include "my_rpg.h"

int variable_display_is_set(char **ae)
{
    for (int i = 0; ae[i]; i++) {
        if (my_strncmp(ae[i], "DISPLAY=", 8) == 0)
            return (1);
    }
    return (0);
}

int main(int ac, char **av, char **ae)
{
    sfRenderWindow *win;

    if (!ae || !variable_display_is_set(ae))
        return (EXIT_ERROR);
    srand(time(NULL));
    win = menu();
    return (my_rpg(win));
}
