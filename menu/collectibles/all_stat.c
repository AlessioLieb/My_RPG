/*
** EPITECH PROJECT, 2021
** menu
** File description:
** all_stat.c
*/

#include "../includes/motor.h"

int all_stat(player *py)
{
    py->st.damages++;
    py->speed++;
    py->st.freq_tears++;
    py->st.shot_speed++;
    py->lf.total_life += 2;
    return 1;
}
