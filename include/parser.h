/*
** EPITECH PROJECT, 2019
** structure fonction and define
** File description:
** parser
*/

#ifndef PARSER_H_
#define PARSER_H_

#include "my_rpg.h"

#define DOT_SCENE ".dz28"
#define LEN_NAME_MAX 20
#define LEN_DESCRIPTION_MAX 200
#define LEN_DIALOGUE_MAX 200
#define LIFE_ENNEMY 100
#define VOLUME_DEFAULT 100
#define POS_X_VOLUME 40
#define POS_Y_VOLUME 40
#define SIZE_CHAR_VOLUME 30
#define PATH_TO_FONT_VOLUME "fonts/dialog_font.ttf"
#define T_BOSS "boss"
#define T_MINI_BOSS "mini boss"
#define PATH "PATH"
#define PATH_FRONT "PATH_FRONT"
#define PATH_BACK "PATH_BACK"
#define PATH_LEFT "PATH_LEFT"
#define PATH_RIGHT "PATH_RIGHT"
#define PATH_ATTACK "PATH_ATTACK"
#define PATH_DEAD "PATH_DEAD"
#define PATH_NORMAL "PATH_NORMAL"
#define S_TYPE "TYPE"
#define NAME "NAME"
#define FREQUENCE "FREQUENCE"
#define MOVE "MOVE"
#define X "X"
#define Y "Y"
#define TOP "TOP"
#define BOTTOM "BOTTOM"
#define RIGHT "RIGHT"
#define LEFT "LEFT"
#define LVL "LVL"
#define ATT_S "ATT"
#define DESCRIPTION "DESCRIPTION"
#define OBSTACLE "OBSTACLE"
#define GAME_OBJECT "GAME_OBJECT"
#define PNJ "PNJ"
#define ENNEMY "ENNEMY"
#define MUSIC "MUSIC"
#define SOUND "SOUND"
#define CONNECTION "CONNECTION"
#define DIALOGUE "DIALOGUE"
#define PATH_SCENES "scene/"
#define TYPE (char *[9]){"BACKGROUND", "OBSTACLE", "GAME_OBJECT", "PNJ" \
            , "ENNEMY", "MUSIC", "SOUND", "CONNECTION", NULL}

scene_t **run_parsing(sfRenderWindow *);
scene_t *parse_background(char *, scene_t *);
scene_t *parse_obstacle(char *, scene_t *);
scene_t *parse_game_object(char *, scene_t *);
scene_t *parse_pnj(char *, scene_t *);
scene_t *parse_ennemy_2(char *, scene_t *, int);
scene_t *parse_ennemy(char *, scene_t *);
scene_t *parse_music(char *, scene_t *);
scene_t *parse_sound(char *, scene_t *);
scene_t *parse_connection(char *, scene_t *);
int check_who_is_first(char *, char *);
char **loop_alpha_order(char **, char, char, char *);
char **order_letter(char **);
int get_nbr_file_in_dir(char *);
char **get_name_files_in_dir(char *);
void destroy_image(image_t *image);
void destroy_sprite(sprite_t *sprite);
void destroy_pnj(pnj_t *pnj);
void destroy_pnjs(pnj_t **pnj, int nbr_pnj);
void destroy_ennemies(ennemy_t **ennemy, int nbr_ennemies);
void destroy_text(text_t *text);
void destroy_music(music_t *music);
void destroy_sounds(sound_t **sound, int nbr_sounds);
void destroy_obstacles(obstacle_t **obstacle, int nbr_obstacles);
void destroy_game_objects(object_t **game_object, int nbr_game_object);
void destroy_scene_parser(scene_t *scene);
void destroy_scenes_parser(scene_t **scenes);
int increase_i(int i, char *line);
int is_num(char *str);
char *str_to_low(char *str);
int is_scene_file(char *name);
char *get_file_str(char *file_path);
int get_nbr_in_file(char **file, char *type);
char *ret_int(char *line, int i);
int check_int(char *nbr, char *elem);
int get_int(char *line, char *type);
char *ret_str(char *line, int i);
char *get_str(char *line, char *type);
int get_len_type(char *line);
int get_type_line(char *line);
type_ennemy_t get_type_ennemy(type_ennemy_t type, char *str_type);
char **get_only_scene_files(char **file_name);
void save_coord(int, movement_t *, char *);
int get_coord(int, char *, movement_t *, int);
movement_t *get_movement(movement_t *movement, char *line);
image_t *create_image(image_t *image, char *line);
sprite_t *create_sprite(sprite_t *, char *, sfVector2f);
sprite_battle_t *create_sprites_battle(sprite_battle_t *, char *, sfVector2f);
pnj_t *create_all_sprites(pnj_t *pnj, char *line, sfVector2f position);
scene_t *malloc_all_the_scene(char **, scene_t *);
scene_t *malloc_all_the_scene_2(char **, scene_t *);
obstacle_t **malloc_obstacle(obstacle_t **obstacle, char **file);
object_t **malloc_game_object(object_t **game_object, char **file);
pnj_t *malloc_one_pnj_2(pnj_t *pnj);
pnj_t *malloc_one_pnj(pnj_t *pnj);
pnj_t **malloc_pnj(pnj_t **pnj, char **file);
sprite_battle_t *malloc_sprites_battle(sprite_battle_t *sprite_battle);
ennemy_t **malloc_ennemy(ennemy_t **ennemy, char **file);
music_t *malloc_music(music_t *music);
sound_t **malloc_sounds(sound_t **sound, char **file);

#endif /* !PARSER_H_ */
