/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** anim enemies
*/

#include "../includes/motor.h"

static void check_max(sfIntRect actual, int max, adv_t *adv, int i, int decal)
{
    if (actual.left >= max)
        sfSprite_setTextureRect(adv[i].sp,
        (sfIntRect) {0, actual.top, actual.width, actual.height});
    else
        sfSprite_setTextureRect(adv[i].sp,
        (sfIntRect) {actual.left + decal, actual.top,
        actual.width, actual.height});
}

static void anim_all(adv_t *all, int max, int decal)
{
    for (int i = 0; i < 10; ++i)
        if (all[i].pos.x != - 1 && all[i].pos.y != - 1)
            check_max(sfSprite_getTextureRect(all[i].sp), max, all, i, decal);
}

void anim_enemies(enemies_t *enem_t)
{
    enem_t->ti.timer_total += sfClock_getElapsedTime
    (enem_t->total_clock).microseconds - enem_t->ti.timer;
    while (enem_t->ti.timer_total > 100000) {
        anim_all(enem_t->flying_adv, 60, 30);
        anim_all(enem_t->big_adv, 440, 64);
        anim_all(enem_t->little_adv, 93, 31);
        anim_all(enem_t->no_moving_adv, 61, 31);
        anim_boss_loop(enem_t);
        enem_t->ti.timer_total -= 100000;
    }
    enem_t->ti.timer =
    sfClock_getElapsedTime(enem_t->total_clock).microseconds;
}

void reduce_init_big(int i, adv_t *adv)
{
    adv[i].speed = 2;
    adv[i].pos = (sfVector2f){-1, -1};
    adv[i].is_flying = false;
    adv[i].is_shooting = false;
    adv[i].pv = 6;
}

void reduce_init_fly(int i, adv_t *adv)
{
    adv[i].speed = 4;
    adv[i].pos = (sfVector2f){-1, -1};
    adv[i].is_flying = true;
    adv[i].is_shooting = false;
    adv[i].pv = 3;
}
