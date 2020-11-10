/*
** EPITECH PROJECT, 2019
** run parsiing
** File description:
** rpg
*/

#include "../../include/parser.h"

elements_t *init_nbr_elements(elements_t *elements)
{
    elements->nbr_background = 0;
    elements->nbr_obstacles = 0;
    elements->nbr_game_objects = 0;
    elements->nbr_pnj = 0;
    elements->nbr_ennemies = 0;
    elements->nbr_sounds = 0;
    return (elements);
}

scene_t *parse_line(char *line, scene_t *scene)
{
    int type = get_type_line(line);
    scene_t *(*fonction_parsing[8])(char *, scene_t *) = {&parse_background,
                                                        &parse_obstacle,
                                                        &parse_game_object,
                                                        &parse_pnj,
                                                        &parse_ennemy,
                                                        &parse_music,
                                                        &parse_sound,
                                                        &parse_connection};

    if (type == 84)
        return (NULL);
    scene = fonction_parsing[type](line, scene);
    return (scene);
}

scene_t *parse_file(char *file_name)
{
    char *file_path = mem_alloc(PATH_SCENES, file_name);
    scene_t *scene = NULL;
    char **file = NULL;

    if (file_path == NULL)
        return (NULL);
    else if ((file = get_file(file_path)) == NULL)
        return (NULL);
    scene = malloc_all_the_scene(file, scene);
    if (scene == NULL)
        return (NULL);
    scene->nbr_elements = init_nbr_elements(scene->nbr_elements);
    for (int i = 0; file[i]; i++) {
        scene = parse_line(file[i], scene);
        if (scene == NULL)
            return (NULL);
    }
    free(file_path);
    free_array(file);
    return (scene);
}

scene_t **run_parsing(sfRenderWindow *win)
{
    char **file_name = get_name_files_in_dir(PATH_SCENES);
    scene_t **scenes = NULL;
    int  i = 0;

    if (file_name == NULL)
        return (NULL);
    else if ((file_name = get_only_scene_files(file_name)) == NULL)
        return (NULL);
    scenes = malloc(sizeof(scene_t *) * (my_lenline(file_name) + 1));
    if (scenes == NULL)
        return (NULL);
    for (i = 0; file_name[i]; i++) {
        if ((scenes[i] = parse_file(file_name[i])) == NULL)
            return (NULL);
        else if ((scenes[i] = create_main_scene(scenes[i], win)) == NULL)
            return (NULL);
    }
    scenes[i] = NULL;
    free_array(file_name);
    return (scenes);
}
