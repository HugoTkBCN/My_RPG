/*
** EPITECH PROJECT, 2019
** include
** File description:
** exemple
*/

#ifndef MY_H_
#define MY_H_

#define FPS 30
#define EXIT_ERROR 84
#define CHAR "img/character/character.png"
#define SCENE1 "img/grass_bg.png"
#define DIALOG "fonts/dialog_font.ttf"
#define TITLE "fonts/title_font.ttf"
#define WIN_WIDTH 1920
#define WIN_HEIGHT 1080
#define CHAR_WID 80
#define CHAR_HEI 144
#define HOUSE2 "img/house_2.png"
#define HOUSE_HEI 360
#define HOUSE_WID 480
#define PAUSE_BG "img/pause_bg.png"
#define FPS 30
#define TREE1 "img/tree_1.png"
#define TREE2 "img/tree_2.png"
#define MENU_IMG "img/menu_bg.png"
#define NAME_GAME "my_rpg"
#define INVENTORY "img/inventory.png"

#include "utils.h"
#include "lib.h"

#define WIN_OPEN "sfRenderWindow_isOpen(scene->win)"

typedef struct inventory_object_s {
    sfSprite *sprite;
    sfTexture *texture;
    int count;
    sfText *text;
} inventory_object_t;

typedef enum type_ennemy_s {
    SBIRE,
    MINI_BOSS,
    BOSS
} type_ennemy_t;

typedef struct image_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f position;
} image_t;

typedef struct obstacle_s {
    image_t *image;
} obstacle_t;

typedef struct object_s {
    image_t *object;
    char *name;
    char *description;
} object_t;

typedef struct sprite_t {
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect *rect;
} sprite_t;

typedef struct movement_s {
    sfVector2f start;
    sfVector2f end;
} movement_t;

typedef struct pnj_s {
    sprite_t *front;
    sprite_t *back;
    sprite_t *left;
    sprite_t *right;
    char *name;
    char *dialogue;
    sfVector2f position;
    movement_t *movement;
} pnj_t;

typedef struct sprite_battle_s {
    sprite_t *attack;
    sprite_t *dead;
    sprite_t *normal;
} sprite_battle_t;

typedef struct ennemy_s {
    pnj_t *data;
    type_ennemy_t type;
    int lvl;
    int att;
    int life;
    sprite_battle_t *sprite_battle;
} ennemy_t;

typedef struct sound_s {
    sfSoundBuffer *buffer;
    sfSound *sound;
    movement_t *zone;
    int frequence;
} sound_t;

typedef struct text_s {
    sfText *text;
    sfFont *font;
    sfColor color;
    sfVector2f position;
    char *string;
} text_t;

typedef struct music_s {
    sfMusic *music;
    int volume;
    text_t *text;
} music_t;

typedef struct connection_s {
    int top;
    int bottom;
    int left;
    int right;
} connection_t;

typedef struct elements_s {
    int nbr_background;
    int nbr_obstacles;
    int nbr_game_objects;
    int nbr_pnj;
    int nbr_ennemies;
    int nbr_sounds;
} elements_t;

typedef struct game_object_s {
    sfSprite *sprite;
    sfTexture *texture;
} game_object_t;

typedef struct dialog_s {
    sfRectangleShape *rect;
    sfVector2f size;
    sfVector2f pos;
    sfClock *clock;
    float speed;
    sfFont *font;
    sfText *mes;
    char *text;
    int letter;
} dialog_t;

struct framebuffer {
    unsigned int width;
    unsigned int height;
    sfUint8 *pixels;
};
typedef struct framebuffer framebuffer_t;

typedef struct particule_s {
    sfSprite *sprite;
    sfClock *clock;
    float duration;
    struct particule_s *next;
    struct particule_s *previous;
} particule_t;

typedef struct scene_s {
    image_t *background;
    obstacle_t **obstacle;
    object_t **game_object;
    pnj_t **pnj;
    ennemy_t **ennemy;
    music_t *music;
    sound_t **sound;
    connection_t *connection;
    elements_t *nbr_elements;
    sfRenderWindow *win;
    particule_t *particules;
    dialog_t dial;
    game_object_t **objs;
    inventory_object_t *inventory;
} scene_t;

typedef struct button_s {
    sfRectangleShape *rect;
    char *text;
    int size;
    int (*callback)(scene_t *);
} button_t;

void destroy_inventory(inventory_object_t *);
int click_inventory(sfMouseButtonEvent , int);
int inventory(scene_t *, sfEvent , int);
void inventory_description(scene_t *);
int create_object_inv(inventory_object_t *, char *);
game_object_t *create_object(char *, sfIntRect);
void destroy_object(game_object_t *obj);
void draw_scene(scene_t *, int);
int my_rpg(sfRenderWindow *);
scene_t *create_main_scene(scene_t *, sfRenderWindow *);
void destroy_scene(scene_t *scene);
void move_char(sfEvent event, game_object_t **objs, scene_t *);
int create_dialog(scene_t *scene, sfVector2f pos, sfVector2f size, char *mes);
int update_dialog(scene_t *scene);
framebuffer_t *framebuffer_create(unsigned int width, unsigned int height);
void my_put_pixel(framebuffer_t *framebuffer, int x, int y, sfColor color);
particule_t *put_particule(sfVector2f, sfColor, int *, particule_t *);
void add_walking_particule(scene_t *scene);
void check_particules(scene_t *scene);
int pause_screen(scene_t *);
void display_button(sfRenderWindow *win, button_t button);
int button_is_clicked(button_t *, sfVector2i click_position);
void init_button(button_t *btn, char *txt, sfVector2f pos, sfVector2f size);
void destroy_game_obj(game_object_t *);
void destroy_button_array(button_t **);
void destroy_particule(scene_t *scene, particule_t *p);
void display_button_array(sfRenderWindow *, button_t **);
int check_btn_click(scene_t *, button_t **);
void destroy_game_object(game_object_t *);
void draw_text(sfRenderWindow *, char *text, sfVector2f pos, int size);
sfRenderWindow *menu(void);
int resume_pause(scene_t *);
int exit_pause(scene_t *);
int check_quit(scene_t *);
void check_ennemy(scene_t *s);

#endif /* !MY_H_ */
