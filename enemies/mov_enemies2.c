/*
** EPITECH PROJECT, 2021
** B-MUL-200-MLH-2-1-myrpg-robin.denni
** File description:
** mov_enemies2.c
*/

#include "../includes/motor.h"

void move_enemies(reduce *red)
{
    sfVector2f p_pos = sfSprite_getPosition(red->py->sp);
    red->enem_t->move_ti.timer_total +=
    sfClock_getElapsedTime(red->enem_t->total_clock)
    .microseconds - red->enem_t->move_ti.timer;
    while (red->enem_t->move_ti.timer_total > 50000) {
        mov_all(red->enem_t->flying_adv, p_pos, 0, red);
        mov_all(red->enem_t->big_adv, p_pos, 1, red);
        mov_all(red->enem_t->little_adv, p_pos, 2, red);
        mov_all(red->enem_t->no_moving_adv, p_pos, 3, red);
        mov_all_boss(red->enem_t->boss_adv, p_pos, red);
        red->enem_t->move_ti.timer_total -= 50000;
    }
    red->enem_t->move_ti.timer =
    sfClock_getElapsedTime(red->enem_t->total_clock).microseconds;
}

void reduce_init_nomov(int i, adv_t *no_mov, sfVector2f scale, sfIntRect place)
{
    sfSprite_setTextureRect(no_mov[i].sp, place);
    sfSprite_setScale(no_mov[i].sp, scale);
    no_mov[i].speed = 0;
    no_mov[i].pos = (sfVector2f){-1, -1};
    no_mov[i].is_flying = false;
    no_mov[i].is_shooting = true;
    no_mov[i].pv = 2;
}
