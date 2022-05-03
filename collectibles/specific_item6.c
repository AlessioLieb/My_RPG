/*
** EPITECH PROJECT, 2021
** B-MUL-200-MLH-2-1-myrpg-robin.denni
** File description:
** specific_item6.c
*/

#include "../includes/motor.h"

int god_head(player *py)
{
    py->lf.total_life += 2;
    py->lf.red_hearth += 2;
    py->it_des->active = true;
    ++py->st.damages;
    ++py->st.freq_tears;
    ++py->st.luck;
    ++py->st.shot_speed;
    ++py->speed;
    py->st.damages *= 1.25;
    sfClock_restart(py->it_des->des_clock);
    sfText_setString(py->it_des->main_d, "  GOD HEAD !  ");
    sfText_setString(py->it_des->sec_d, "+1 all stats");
    sfText_setPosition(py->it_des->main_d, (sfVector2f) {770, 195});
    sfText_setPosition(py->it_des->sec_d, (sfVector2f) {885, 270});
    py->it_des->all_st_active = true;
    return 1;
}

int mushroom(player *py)
{
    py->lf.total_life += 2;
    py->lf.red_hearth += 2;
    py->it_des->active = true;
    ++py->st.damages;
    ++py->st.freq_tears;
    ++py->st.luck;
    ++py->st.shot_speed;
    ++py->speed;
    py->st.damages *= 1.25;
    sfClock_restart(py->it_des->des_clock);
    sfText_setString(py->it_des->main_d, "  MUSHROOM !  ");
    sfText_setString(py->it_des->sec_d, "+1 all stats");
    sfText_setPosition(py->it_des->main_d, (sfVector2f) {770, 195});
    sfText_setPosition(py->it_des->sec_d, (sfVector2f) {885, 270});
    py->it_des->all_st_active = true;
    return 1;
}

int cricket(player *py)
{
    ++py->st.damages;
    py->st.damages *= 1.5;
    py->it_des->active = true;
    sfClock_restart(py->it_des->des_clock);
    sfText_setString(py->it_des->main_d, "CRICKET'S HEAD");
    sfText_setString(py->it_des->sec_d, "   DMG UP   ");
    sfText_setPosition(py->it_des->main_d, (sfVector2f) {770, 195});
    sfText_setPosition(py->it_des->sec_d, (sfVector2f) {885, 270});
    return 1;
}

int polyphemus(player *py)
{
    py->st.damages += 3;
    if (py->st.freq_tears >= 5)
        py->st.freq_tears -= 3;
    else
        py->st.freq_tears = 2;
    py->it_des->active = true;
    sfClock_restart(py->it_des->des_clock);
    sfText_setString(py->it_des->main_d, "  POLYPHEMUS  ");
    sfText_setString(py->it_des->sec_d, " MEGA TEARS ");
    sfText_setPosition(py->it_des->main_d, (sfVector2f) {770, 195});
    sfText_setPosition(py->it_des->sec_d, (sfVector2f) {885, 270});
    return 1;
}
