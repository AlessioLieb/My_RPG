/*
** EPITECH PROJECT, 2021
** menu
** File description:
** all_stat.c
*/

#include "../includes/motor.h"

int my_str_compare(char const *str_one, char const *str_two)
{
    if (str_len(str_one) != str_len(str_two))
        return 0;
    for (int i = 0; str_one[i] != '\0'; ++i)
        if (str_one[i] != str_two[i])
            return 0;
    return 1;
}

inventory create_inventory(void)
{
    inventory invent;
    invent.money = 3;
    invent.bomb = 6;
    invent.key = 1;
    return invent;
}

int all_stats_up(player *py)
{
    py->lf.total_life += 2;
    py->lf.red_hearth += 2;
    py->it_des->active = true;
    sfClock_restart(py->it_des->des_clock);
    sfText_setString(py->it_des->main_d, "ALL STATS UP !");
    sfText_setString(py->it_des->sec_d, "+1 all stats");
    sfText_setPosition(py->it_des->main_d, (sfVector2f){770, 195});
    sfText_setPosition(py->it_des->sec_d, (sfVector2f){885, 270});
    py->it_des->all_st_active = true;
    ++py->st.damages;
    ++py->st.freq_tears;
    ++py->st.luck;
    ++py->st.shot_speed;
    ++py->speed;
    return 1;
}
