/*
** EPITECH PROJECT, 2019
** parser line ennemy
** File description:
** parser
*/

#include "../../../include/parser.h"

scene_t *parse_ennemy_2(char *line, scene_t *scene, int nbr_ennemy)
{
    scene->ennemy[nbr_ennemy]->lvl = get_int(line, LVL);
    scene->ennemy[nbr_ennemy]->att = get_int(line, ATT_S);
    scene->ennemy[nbr_ennemy]->life = LIFE_ENNEMY;
    scene->ennemy[nbr_ennemy]->type =
        get_type_ennemy(scene->ennemy[nbr_ennemy]->type,
        get_str(line, S_TYPE));
    scene->ennemy[nbr_ennemy]->sprite_battle =
        create_sprites_battle(scene->ennemy[nbr_ennemy]->sprite_battle,
        line, scene->ennemy[nbr_ennemy]->data->position);
    if (scene->ennemy[nbr_ennemy]->sprite_battle == NULL)
        return (NULL);
    scene->nbr_elements->nbr_ennemies++;
    return (scene);
}

scene_t *parse_ennemy(char *line, scene_t *scene)
{
    int nbr_ennemy = scene->nbr_elements->nbr_ennemies;

    scene->ennemy[nbr_ennemy]->data->name = get_str(line, NAME);
    scene->ennemy[nbr_ennemy]->data->dialogue =
        get_file_str(get_str(line, DIALOGUE));
    scene->ennemy[nbr_ennemy]->data->position.x = get_int(line, X);
    scene->ennemy[nbr_ennemy]->data->position.y = get_int(line, Y);
    if (scene->ennemy[nbr_ennemy]->data->position.x == -1 ||
        scene->ennemy[nbr_ennemy]->data->position.y == -1 )
        return (NULL);
    scene->ennemy[nbr_ennemy]->data =
        create_all_sprites(scene->ennemy[nbr_ennemy]->data, line,
        scene->ennemy[nbr_ennemy]->data->position);
    if (scene->ennemy[nbr_ennemy]->data == NULL)
        return (NULL);
    scene->ennemy[nbr_ennemy]->data->movement =
        get_movement(scene->ennemy[nbr_ennemy]->data->movement, line);
    return (parse_ennemy_2(line, scene, nbr_ennemy));
}
