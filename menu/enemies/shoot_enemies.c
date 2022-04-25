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
        red->enem_t->boss_adv[i].pv--;
        if (red->enem_t->boss_adv[i].pv <= 0) {
            red->enem_t->boss_adv[i].pos = (sfVector2f){-1, -1};
            red->enem_t->boss_adv[i].pv = 1;
        }
    }
}

void check_other(reduce *red, int i, char c)
{
    if (c == 'F') {
        red->enem_t->flying_adv[i].pv--;
        if (red->enem_t->flying_adv[i].pv <= 0) {
            red->enem_t->flying_adv[i].pos = (sfVector2f){-1, -1};
            red->enem_t->flying_adv[i].pv = 20;
        }
    }
    if (c == 'L') {
        red->enem_t->little_adv[i].pv--;
        if (red->enem_t->little_adv[i].pv <= 0) {
            red->enem_t->little_adv[i].pos = (sfVector2f){-1, -1};
            red->enem_t->little_adv[i].pv = 20;
        }
    }
    check_boss(red, i, c);
}

bool touched_enemy(reduce *red, int i, char c)
{
    if (c == 'I') {
        red->enem_t->big_adv[i].pv--;
        if (red->enem_t->big_adv[i].pv <= 0) {
            red->enem_t->big_adv[i].pos = (sfVector2f){-1, -1};
            red->enem_t->big_adv[i].pv = 20;
        }
    }
    if (c == 'N') {
        red->enem_t->no_moving_adv[i].pv--;
        if (red->enem_t->no_moving_adv[i].pv <= 0) {
            red->enem_t->no_moving_adv[i].pos = (sfVector2f){-1, -1};
            red->enem_t->no_moving_adv[i].pv = 20;
        }
    }
    check_other(red, i, c);
    return false;
}
