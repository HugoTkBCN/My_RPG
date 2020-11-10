/*
** EPITECH PROJECT, 2019
** utils .h
** File description:
** rpg
*/

#include "lib.h"

void my_putchar(char c);
int my_put_nbr(int nb);
void my_putstr(char const *str);
int my_strlen(char const *);
char *my_revstr(char *);
char *my_strdup(char *src);
char *my_strcpy(char *dest, char *src);
sfRenderWindow *create_window(int height, int width);
int my_strncmp(char *, char *, int);
int my_strcmp(char *, char *);
int str_to_int(char *);
char *int_to_str(int);
int char_to_int(char);
char int_to_char(int);
char *mem_alloc(char const *, char const *);
int get_len_nbr(int);
int get_nbr_line_in_file(char *filepath);
char **get_file(char *filepath);
int my_lenline(char **array);
void free_array(char **array);
