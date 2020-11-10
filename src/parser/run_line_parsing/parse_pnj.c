/*
** EPITECH PROJECT, 2019
** parse line pnj
** File description:
** parser
*/

#include "../../../include/parser.h"

scene_t *parse_pnj(char *line, scene_t *scene)
{
    int nbr_pnj = scene->nbr_elements->nbr_pnj;

    scene->pnj[nbr_pnj]->name = get_str(line, NAME);
    scene->pnj[nbr_pnj]->dialogue = get_file_str(get_str(line, DIALOGUE));
    scene->pnj[nbr_pnj]->position.x = get_int(line, X);
    scene->pnj[nbr_pnj]->position.y = get_int(line, Y);
    if (scene->pnj[nbr_pnj]->position.x == -1 ||
        scene->pnj[nbr_pnj]->position.y == -1 )
        return (NULL);
    scene->pnj[nbr_pnj] = create_all_sprites(scene->pnj[nbr_pnj], line,
                                            scene->pnj[nbr_pnj]->position);
    if (scene->pnj[nbr_pnj] == NULL)
        return (NULL);
    scene->pnj[nbr_pnj]->movement =
        get_movement(scene->pnj[nbr_pnj]->movement, line);
    scene->nbr_elements->nbr_pnj++;
    return (scene);
}
