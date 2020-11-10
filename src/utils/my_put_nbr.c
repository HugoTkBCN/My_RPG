/*
** EPITECH PROJECT, 2018
** my put nbr
** File description:
** task07
*/

#include "../../include/my_rpg.h"

int my_put_nbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    nb / 10 ? my_put_nbr(nb / 10) : 0;
    my_putchar(nb % 10 + '0');
    return (0);
}
