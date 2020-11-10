/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** header
*/

#ifndef FIGHT
#define FIGHT

#include "my_rpg.h"

#define LEN_LIFE 500
#define F_BACK "img/fight/fight_bg.png"
#define DEAD "img/fight/fight_death.png"
#define ATT "img/fight/fight_attack.png"
#define STAND "img/fight/fight_idle.png"
#define F_THEME "music/fight_theme.ogg"
#define O_DEATH "img/fight/op_death.png"
#define O_IDLE "img/fight/op_idle.png"
#define O_ATT "img/fight/op_attack.png"
#define LOST "img/losing.png"
#define FCHAR_HEI 320
#define FCHAR_WID 240
#define MAX_WID 1440
#define LOST_WID 500
#define LOST_HEI 500
#define P_X 200
#define P_Y 650
#define O_X 1600
#define O_Y 650

typedef struct player_s fighter_t;
typedef struct fight_s fight_t;
typedef struct attack_s attack_t;

typedef struct attack_s {
    int damage;
    int accuracy;
    char *name;
    sfText *text;
    sfVector2f pos;
    sfVector2f size;
    sfRectangleShape *rect;
    void (*callback)(fight_t *, attack_t *, fighter_t *, fighter_t *);
} attack_t;

typedef struct player_s {
    int life;
    int max_life;
    attack_t **attack;
    sfClock *clock;
    game_object_t *att;
    game_object_t *death;
    game_object_t *idle;
} fighter_t;

typedef struct fight_s {
    sfSprite *p_spr;
    sfSprite *o_spr;
    sfClock *clock;
    int finished;
    sfSound **sound;
    sfSoundBuffer **s_buf;
    sfMusic *mus;
    game_object_t *bg;
    game_object_t *lost;
    sfRectangleShape *o_life;
    sfRectangleShape *p_life;
} fight_t;

fighter_t *prep_fighter(int, int);
int fight(sfRenderWindow *win, fighter_t *player, fighter_t *opp);
void prep_sprite_player(fighter_t *p, char *att, char *death, char *idle);
fight_t *prepare_fight(fighter_t *player, fighter_t *opp);
void disp_fight(sfRenderWindow *, fighter_t *, fighter_t *, fight_t *);
attack_t **create_attack(void);
void att(fight_t *f, attack_t *att, fighter_t *pl, fighter_t *opp);
void opp_att(fight_t *f, attack_t *att, fighter_t *pl, fighter_t *opp);
int is_fight_closed(sfRenderWindow *);
void draw_lost_screen(sfRenderWindow *win, fight_t *f);

#endif
