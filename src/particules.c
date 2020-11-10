/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** fonctions to put a particules effect
*/

#include "my_rpg.h"

void init_particules(framebuffer_t *fb, int width, int height, particule_t *p)
{
    for (int i = 4; i < width * height * 4; i++)
        fb->pixels[i] = 0;
    p->clock = sfClock_create();
    p->duration = 1;
}

void add_previous(particule_t *particule)
{
    if (particule->next)
        particule->next->previous = particule;
    particule->previous = NULL;
}

particule_t *put_particule(sfVector2f pos, sfColor color, int *dim,
                        particule_t *old)
{
    framebuffer_t *fb = framebuffer_create(dim[0], dim[1]);
    sfTexture *texture = sfTexture_create(dim[0], dim[1]);
    particule_t *particule = malloc(sizeof(particule_t));
    int coord[] = {0, 0};

    if (!fb || !texture || !particule)
        return (NULL);
    init_particules(fb, dim[0], dim[1], particule);
    for (int i = 0; i < dim[0] * dim[1] / 20; i++) {
        coord[0] = rand() % dim[0];
        coord[1] = rand() % dim[1];
        my_put_pixel(fb, coord[0], coord[1], color);
    }
    sfTexture_updateFromPixels(texture, fb->pixels, dim[0], dim[1], 0, 0);
    particule->sprite = sfSprite_create();
    sfSprite_setTexture(particule->sprite, texture, sfTrue);
    sfSprite_setPosition(particule->sprite, pos);
    particule->next = old;
    add_previous(particule);
    return (particule);
}

void add_walking_particule(scene_t *scene)
{
    sfVector2f pos = sfSprite_getPosition(scene->objs[1]->sprite);
    int dim[] = {30, 30};

    pos.x += CHAR_WID / 2 - dim[0] / 2;
    pos.y += CHAR_HEI - dim[1] / 2;
    scene->particules = put_particule(pos, sfWhite, dim, scene->particules);
    scene->particules->duration = 0.5;
}

void check_particules(scene_t *scene)
{
    sfTime time;

    if (!scene->particules)
        return;
    for (particule_t *tmp = scene->particules; tmp; tmp = tmp->next) {
        time = sfClock_getElapsedTime(tmp->clock);
        if (sfTime_asSeconds(time) >= tmp->duration) {
            sfSprite_destroy(tmp->sprite);
            destroy_particule(scene, tmp);
        }
    }
}
