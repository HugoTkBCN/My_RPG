/*
** EPITECH PROJECT, 2019
** get file in string
** File description:
** parser
*/

#include "../../../include/parser.h"

char *get_file_str(char *file_path)
{
    int fd = open(file_path, O_RDONLY);
    char *str = "";
    char *tmp = malloc(sizeof(char) * 2);
    int size = 1;

    if (fd == -1 || tmp == NULL)
        return (NULL);
    while (size != 0) {
        size = read(fd, tmp, 1);
        tmp[1] = '\0';
        str = mem_alloc(str, tmp);
    }
    free(tmp);
    close(fd);
    return (str);
}
