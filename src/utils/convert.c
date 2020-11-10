/*
** EPITECH PROJECT, 2018
** convert
** File description:
** convertisseur
*/

#include "../../include/my_rpg.h"

int str_to_int(char *nbr)
{
    int i = 0;
    int res = 0;

    while (nbr[i]) {
        res = res * 10;
        res = res + (nbr[i++] - 48);
    }
    return (res);
}

int get_len_nbr(int nbr)
{
    int len = 0;

    for (int i = 0; nbr > 0; i++) {
        nbr = nbr / 10;
        len++;
    }
    return (len);
}

char *int_to_str(int nbr)
{
    int i = 0;
    int tmp = 0;
    char *str = malloc(sizeof(int) * (get_len_nbr(nbr) + 1));

    if (str == NULL)
        return (NULL);
    while (nbr != 0) {
        tmp = nbr % 10;
        str[i++] = tmp + 48;
        nbr = nbr / 10;
    }
    str[i] = '\0';
    str = my_revstr(str);
    return (str);
}

int char_to_int(char nbr)
{
    int res = 0;

    res = nbr - 48;
    return (res);
}

char int_to_char(int nbr)
{
    char c;

    c = nbr + 48;
    return (c);
}
