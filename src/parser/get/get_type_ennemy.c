/*
** EPITECH PROJECT, 2019
** get type ennemy
** File description:
** parser
*/

#include "../../../include/parser.h"

type_ennemy_t get_type_ennemy(type_ennemy_t type, char *str_type)
{
    if (str_type == NULL) {
        type = SBIRE;
        return (type);
    }
    str_type = str_to_low(str_type);
    if (my_strcmp(str_type, T_BOSS) == 1)
        type = BOSS;
    else if (my_strcmp(str_type, T_MINI_BOSS) == 1)
        type = MINI_BOSS;
    else
        type = SBIRE;
    return (type);
}
