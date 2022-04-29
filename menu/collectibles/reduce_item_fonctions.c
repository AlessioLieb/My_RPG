/*
** EPITECH PROJECT, 2021
** menu
** File description:
** reduce_item_fonctions.c
*/

#include "../includes/motor.h"

int item_damage(player *py)
{
    py->st.damages++;
    return 1;
}

int item_speed(player *py)
{
    py->speed++;
    return 1;
}

int item_freq(player *py)
{
    if (py->st.freq_tears <= 9)
        py->st.freq_tears++;
    return 1;
}

int item_speed_tears(player *py)
{
    if (py->st.shot_speed <= 10)
    py->st.shot_speed++;
    return 1;
}

int item_life_augmentation(player *py)
{
    py->lf.total_life += 2;
    py->lf.red_hearth += 2;
    return 1;
}
