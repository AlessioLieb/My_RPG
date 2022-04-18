/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** anim enemies
*/

#include "../includes/motor.h"

void check_max(sfIntRect actual, int max, adv_t *adv, int i, int decal)
{
    if (actual.left >= max)
        sfSprite_setTextureRect(adv[i].sp,
        (sfIntRect) {0, actual.top, actual.width, actual.height});
    else
        sfSprite_setTextureRect(adv[i].sp,
        (sfIntRect) {actual.left + decal, actual.top, actual.width, actual.height});
}

void move_adv(adv_t *actual, int i, sfVector2f player_pos)
{
    if (fabsf(actual[i].pos.x - player_pos.x) > fabsf(actual[i].pos.y - player_pos.y))
        actual[i].pos.x += actual[i].pos.x - player_pos.x > 0 ? - actual[i].speed : actual[i].speed;
    else
        actual[i].pos.y += actual[i].pos.y - player_pos.y > 0 ?  - actual[i].speed : actual[i].speed;
}

void anim_all(adv_t *all, int max, int decal)
{
    for (int i = 0; i < 10; ++i)
        if (all[i].pos.x != - 1 && all[i].pos.y != - 1)
            check_max(sfSprite_getTextureRect(all[i].sp), max, all, i, decal);
}

void mouv_all(adv_t *all, sfVector2f player_pos)
{
    for (int i = 0; i < 10; ++i)
        if (all[i].pos.x != - 1 && all[i].pos.y != - 1)
            move_adv(all, i, player_pos);
}

void anim_enemies(enemies_t *enem_t, player *py)
{
    sfVector2f p_pos = sfSprite_getPosition(py->sp);
    enem_t->ti.timer_total += sfClock_getElapsedTime
    (enem_t->total_clock).microseconds - enem_t->ti.timer;
    while (enem_t->ti.timer_total > 100000) {
        anim_all(enem_t->flying_adv, 60, 30);
        anim_all(enem_t->big_adv, 440, 64);
        anim_all(enem_t->little_adv, 93, 31);
        anim_all(enem_t->no_mouving_adv, 61, 31);
        enem_t->ti.timer_total -= 100000;
    }
    enem_t->ti.timer = sfClock_getElapsedTime(enem_t->total_clock).microseconds;
    enem_t->move_ti.timer_total += sfClock_getElapsedTime
   (enem_t->total_clock).microseconds - enem_t->move_ti.timer;
    while (enem_t->move_ti.timer_total > 50000) {
        mouv_all(enem_t->flying_adv, p_pos);
        mouv_all(enem_t->big_adv, p_pos);
        mouv_all(enem_t->little_adv, p_pos);
        mouv_all(enem_t->no_mouving_adv, p_pos);
        enem_t->move_ti.timer_total -= 50000;
    }
    enem_t->move_ti.timer = sfClock_getElapsedTime(enem_t->total_clock).microseconds;
}