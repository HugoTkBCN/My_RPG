/*
** EPITECH PROJECT, 2019
** malloc pnj_t
** File description:
** parser
*/

#include "../../../include/parser.h"

pnj_t *malloc_one_pnj_2(pnj_t *pnj)
{
    if ((pnj->right = malloc(sizeof(sprite_t))) == NULL)
        return (NULL);
    else if ((pnj->right->rect = malloc(sizeof(sfIntRect))) == NULL)
        return (NULL);
    pnj->name = malloc(sizeof(char) * (LEN_NAME_MAX + 1));
    if (pnj->name == NULL)
        return (NULL);
    pnj->dialogue = malloc(sizeof(char) * (LEN_DIALOGUE_MAX) + 1);
    if (pnj->dialogue == NULL)
        return (NULL);
    else if ((pnj->movement = malloc(sizeof(movement_t))) == NULL)
        return (NULL);
    return (pnj);
}

pnj_t *malloc_one_pnj(pnj_t *pnj)
{
    if ((pnj = malloc(sizeof(pnj_t))) == NULL)
        return (NULL);
    else if ((pnj->front = malloc(sizeof(sprite_t))) == NULL)
        return (NULL);
    pnj->front->rect = malloc(sizeof(sfIntRect));
    if (pnj->front->rect == NULL)
        return (NULL);
    else if ((pnj->back = malloc(sizeof(sprite_t))) == NULL)
        return (NULL);
    pnj->back->rect = malloc(sizeof(sfIntRect));
    if (pnj->back->rect == NULL)
        return (NULL);
    else if ((pnj->left = malloc(sizeof(sprite_t))) == NULL)
        return (NULL);
    pnj->left->rect = malloc(sizeof(sfIntRect));
    if (pnj->left->rect == NULL)
        return (NULL);
    return (malloc_one_pnj_2(pnj));
}

pnj_t **malloc_pnj(pnj_t **pnj, char **file)
{
    int i = 0;

    pnj = malloc(sizeof(pnj_t *) * (get_nbr_in_file(file, PNJ) + 1));
    if (pnj == NULL)
        return (NULL);
    for (i = 0; i < get_nbr_in_file(file, PNJ); i++) {
        pnj[i] = malloc_one_pnj(pnj[i]);
        if (pnj[i] == NULL)
            return (NULL);
    }
    pnj[i] = NULL;
    return (pnj);
}
