/*
** EPITECH PROJECT, 2019
** get number element in file
** File description:
** parser
*/

#include "../../../include/parser.h"

int get_nbr_in_file(char **file, char *type)
{
    int nbr = 0;
    int no = 0;

    for (int i = 0; file[i]; i++) {
        no = 0;
        for (int y = 0; type[y] && file[i][y]; y++)
            no = type[y] != file[i][y] ? 1 : no;
        if (no == 0)
            nbr++;
    }
    return (nbr);
}
