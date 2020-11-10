/*
** EPITECH PROJECT, 2019
** destroy ennemy_t and pnj_t
** File description:
** parser
*/

#include "../../../include/parser.h"

void destroy_pnj(pnj_t *pnj)
{
    pnj->front != NULL ? destroy_sprite(pnj->front) : 0;
    pnj->back != NULL ? destroy_sprite(pnj->back) : 0;
    pnj->left != NULL ? destroy_sprite(pnj->left) : 0;
    pnj->right != NULL ? destroy_sprite(pnj->right) : 0;
    pnj->name != NULL ? free(pnj->name) : 0;
    pnj->dialogue != NULL ? free(pnj->dialogue) : 0;
    pnj->movement != NULL ? free(pnj->movement) : 0;
    pnj != NULL ? free(pnj) : 0;
}

void destroy_pnjs(pnj_t **pnj, int nbr_pnj)
{
    int i = 0;

    for (i = nbr_pnj - 1; i >= 0; i--) {
        pnj[i] != NULL ? destroy_pnj(pnj[i]) : 0;
    }
    pnj != NULL ? free(pnj): 0;
}

void destroy_ennemies(ennemy_t **ennemy, int nbr_ennemies)
{
    int i = 0;

    for (i = nbr_ennemies - 1; i >= 0; i--) {
        ennemy[i]->data != NULL ? destroy_pnj(ennemy[i]->data) : 0;
        ennemy[i]->sprite_battle->attack != NULL ?
        destroy_sprite(ennemy[i]->sprite_battle->attack) : 0;
        ennemy[i]->sprite_battle->dead != NULL ?
        destroy_sprite(ennemy[i]->sprite_battle->dead) : 0;
        ennemy[i]->sprite_battle->normal != NULL ?
        destroy_sprite(ennemy[i]->sprite_battle->normal) : 0;
        ennemy[i]->sprite_battle != NULL ? free(ennemy[i]->sprite_battle) : 0;
        ennemy[i] != NULL ? free(ennemy[i]) : 0;
    }
    ennemy != NULL ? free(ennemy) : 0;
}
