/*
** EPITECH PROJECT, 2022
** prg
** File description:
** enemies room
*/

#include "../includes/motor.h"

int search_len_en(adv_t *adv)
{
    for (int i = 0; i < 10; ++i)
        if (adv[i].pos.x == - 1)
            return i;
    return 0;
}

void place_enemies(char *str, enemies_t *enem_t)
{
    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] == 'L')
            enem_t->little_adv[search_len_en(enem_t->little_adv)]
            .pos = (sfVector2f){i % 22 * 78 + 140, (i / 22 * 90) + 82};
        if (str[i] == 'F')
            enem_t->flying_adv[search_len_en(enem_t->flying_adv)]
            .pos = (sfVector2f){i % 22 * 78 + 140, (i / 22 * 90) + 82};
        if (str[i] == 'I')
            enem_t->big_adv[search_len_en(enem_t->big_adv)]
            .pos = (sfVector2f){i % 22 * 78 + 140, (i / 22 * 90) + 82};
        if (str[i] == 'N')
            enem_t->no_moving_adv[search_len_en(enem_t->no_moving_adv)]
            .pos = (sfVector2f){i % 22 * 78 + 140, (i / 22 * 90) + 82};
    }
}

void draw_adv(adv_t *adv, sfRenderWindow *wndw)
{
    for (int i = 0; i < 10; ++i)
        if (adv[i].pos.x != - 1 && adv[i].pos.y != - 1) {
            sfSprite_setPosition(adv[i].sp, adv[i].pos);
            sfRenderWindow_drawSprite(wndw, adv[i].sp, NULL);
        }
}

void draw_enemies(reduce *red, sfRenderWindow *wndw)
{
    anim_enemies(red->enem_t);
    move_enemies(red);
    draw_adv(red->enem_t->no_moving_adv, wndw);
    draw_adv(red->enem_t->flying_adv, wndw);
    draw_adv(red->enem_t->little_adv, wndw);
    draw_adv(red->enem_t->big_adv, wndw);
    draw_boss(red->enem_t->boss_adv, wndw);
    if (red->enem_t->boss_life.active != -1)
        display_boss_life(red->enem_t, red->enem_t->boss_life.active, wndw);
}
