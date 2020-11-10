/*
** EPITECH PROJECT, 2019
** get name file scenes
** File description:
** parser
*/

#include "../../../include/parser.h"

int check_who_is_first(char *str_1, char *str_2)
{
    char a;
    char b;
    int eg = 0;

    for (int i = 0; str_1[i] && str_2[i]; i++) {
        a = str_1[i];
        b = str_2[i];
        a = a <= 'Z' && a >= 'A' ? a + 32 : a;
        b = b <= 'Z' && b >= 'A' ? b + 32 : b;
        if (a > b) {
            return (1);
        } else if (a == b)
            eg++;
        else
            return (0);
    }
    if (eg == my_strlen(str_1) || eg == my_strlen(str_2))
        if (my_strlen(str_1) > my_strlen(str_2))
            return (1);
    return (0);
}

char **loop_alpha_order(char **array, char a, char b, char *tmp)
{
    for (int i = 0; array[i + 1]; i++) {
        a = array[i][0];
        b = array[i + 1][0];
        a = a <= 'Z' && a >= 'A' ? a + 32 : a;
        b = b <= 'Z' && b >= 'A' ? b + 32 : b;
        if (a > b) {
            tmp = my_strdup(array[i]);
            array[i] = my_strdup(array[i + 1]);
            array[i + 1] = my_strdup(tmp);
        } else if (a == b && check_who_is_first(array[i], array[i + 1]) == 1) {
            tmp = my_strdup(array[i]);
            array[i] = my_strdup(array[i + 1]);
            array[i + 1] = my_strdup(tmp);
        }
    }
    return (array);
}

char **order_letter(char **array)
{
    char *tmp = NULL;
    char a;
    char b;

    for (int y = 0; array[y]; y++)
        array = loop_alpha_order(array, a, b, tmp);
    free(tmp);
    return (array);
}

int get_nbr_file_in_dir(char *filepath)
{
    DIR *folder = NULL;
    struct dirent *directory = NULL;
    int i = 0;

    folder = opendir(filepath);
    if (folder) {
        for (i = 0; (directory = readdir(folder)) != NULL; i++) {
            i = directory->d_name[0] == '.' ? i - 1 : i;
        }
        closedir(folder);
        return (i);
    } else
        return (-1);
}

char **get_name_files_in_dir(char *filepath)
{
    DIR *folder = NULL;
    struct dirent *directory = NULL;
    char **files_name = malloc(sizeof(char *) *
                                (get_nbr_file_in_dir(filepath) + 1));
    int i = 0;

    folder = opendir(filepath);
    if (folder && files_name != NULL) {
        for (i = 0; (directory = readdir(folder)) != NULL; i++) {
            files_name[i] = my_strdup(directory->d_name);
            i = files_name[i][0] == '.' ? i - 1 : i;
        }
        files_name[i] = NULL;
        files_name = order_letter(files_name);
        closedir(folder);
        return (files_name);
    } else
        return (NULL);
}
