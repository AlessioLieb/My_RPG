/*
** EPITECH PROJECT, 2021
** B-MUL-200-MLH-2-1-myrpg-robin.denni
** File description:
** check_txt_player.c
*/

#include "../includes/music.h"

int choose_texture_player(reduce *red, options *sprt)
{
    if (red->py->change_texture)
        return 1;
    (sprt->choose == 0) ? sfSprite_setTexture(red->py->sp,
    sfTexture_createFromFile("assets/robin.png", NULL), sfFalse) : 0;
    (sprt->choose == 1) ? sfSprite_setTexture(red->py->sp,
    sfTexture_createFromFile("assets/theotime.png", NULL), sfFalse) : 0;
    (sprt->choose == 2) ? sfSprite_setTexture(red->py->sp,
    sfTexture_createFromFile("assets/alessio.png", NULL), sfFalse) : 0;
    (sprt->choose == 3) ? sfSprite_setTexture(red->py->sp,
    sfTexture_createFromFile("assets/oscar.png", NULL), sfFalse) : 0;
    red->py->change_texture = sprt->choose + 1;
    stats_player(red);
    return 0;
}
