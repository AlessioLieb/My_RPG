/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** collision tears/enemies
*/

#include "../includes/motor.h"

void check_boss(reduce *red, int i, char c)
{
    if (c == 'E') {
        red->enem_t->boss_adv[i].pv -= red->py->st.damages;
        if (red->enem_t->boss_adv[i].pv <= 0 && (i != 0
        || red->enem_t->boss_adv[i].bospt.delay == 0)) {
            red->enem_t->boss_adv[i].pos = (sfVector2f){-1, -1};
            red->enem_t->boss_adv[i].pv = 1;
            red->enem_t->boss_life.active = -1;
            place_item(red->rm);
        } else if (red->enem_t->boss_adv[i].pv <= 0) {
            red->enem_t->boss_adv[i].pv = 100;
            red->enem_t->boss_adv[i].bospt.delay = 0;
            sfSprite_setTextureRect(red->enem_t->boss_adv[i].sp,
            (sfIntRect){0, 158, 271, 156});
            place_boss_level(red->enem_t, false);
        }
    }
}

void check_other(reduce *red, int i, char c)
{
    if (c == 'F') {
        red->enem_t->flying_adv[i].pv -= red->py->st.damages;
        if (red->enem_t->flying_adv[i].pv <= 0) {
            red->enem_t->flying_adv[i].pos = (sfVector2f){-1, -1};
            red->enem_t->flying_adv[i].pv = 3;
        }
    }
    if (c == 'L') {
        red->enem_t->little_adv[i].pv -= red->py->st.damages;
        if (red->enem_t->little_adv[i].pv <= 0) {
            red->enem_t->little_adv[i].pos = (sfVector2f){-1, -1};
            red->enem_t->little_adv[i].pv = 4;
        }
    }
    check_boss(red, i, c);
}

bool touched_enemy(reduce *red, int i, char c)
{
    if (c == 'I') {
        red->enem_t->big_adv[i].pv -= red->py->st.damages;
        if (red->enem_t->big_adv[i].pv <= 0) {
            red->enem_t->big_adv[i].pos = (sfVector2f){-1, -1};
            red->enem_t->big_adv[i].pv = 6;
        }
    }
    if (c == 'N') {
        red->enem_t->no_moving_adv[i].pv -= red->py->st.damages;
        if (red->enem_t->no_moving_adv[i].pv <= 0) {
            red->enem_t->no_moving_adv[i].pos = (sfVector2f){-1, -1};
            red->enem_t->no_moving_adv[i].pv = 2;
        }
    }
    check_other(red, i, c);
    return false;
}
