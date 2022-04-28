/*
** EPITECH PROJECT, 2021
** menu
** File description:
** all_stat.c
*/

#include "../includes/motor.h"

int all_stats_up(player *py)
{
    py->lf.total_life += 2;
    py->lf.red_hearth += 2;
    ++py->st.damages;
    ++py->st.freq_tears;
    ++py->st.luck;
    ++py->st.shot_speed;
    ++py->speed;
    return 1;
}
