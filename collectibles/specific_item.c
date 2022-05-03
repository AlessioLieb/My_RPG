/*
** EPITECH PROJECT, 2021
** B-MUL-200-MLH-2-1-myrpg-robin.denni
** File description:
** specific_item.c
*/

#include "../includes/motor.h"

int odd(player *py)
{
    py->st.freq_tears += 2;
    py->st.shot_speed += 1;
    py->it_des->active = true;
    sfClock_restart(py->it_des->des_clock);
    sfText_setString(py->it_des->main_d, " Odd Mushroom ");
    sfText_setString(py->it_des->sec_d, "Fire Rate Up");
    sfText_setPosition(py->it_des->main_d, (sfVector2f) {770, 195});
    sfText_setPosition(py->it_des->sec_d, (sfVector2f) {885, 270});
    return 1;
}

int squeezy(player *py)
{
    py->st.freq_tears += 1;
    py->lf.blue_hearth += 2;
    py->it_des->active = true;
    sfClock_restart(py->it_des->des_clock);
    sfText_setString(py->it_des->main_d, "  Squeezy !  ");
    sfText_setString(py->it_des->sec_d, "  Tears Up  ");
    sfText_setPosition(py->it_des->main_d, (sfVector2f) {770, 195});
    sfText_setPosition(py->it_des->sec_d, (sfVector2f) {885, 270});
    return 1;
}

int torn(player *py)
{
    py->st.freq_tears += 1;
    py->st.shot_speed += 1;
    py->it_des->active = true;
    sfClock_restart(py->it_des->des_clock);
    sfText_setString(py->it_des->main_d, "  Torn Photo  ");
    sfText_setString(py->it_des->sec_d, "Tears + shot speed up");
    sfText_setPosition(py->it_des->main_d, (sfVector2f) {770, 195});
    sfText_setPosition(py->it_des->sec_d, (sfVector2f) {885, 270});
    return 1;
}

int dolly(player *py)
{
    py->st.freq_tears += 1;
    py->lf.total_life += 2;
    py->lf.blue_hearth += 2;
    py->it_des->active = true;
    sfClock_restart(py->it_des->des_clock);
    sfText_setString(py->it_des->main_d, "  Mr. Dolly  ");
    sfText_setString(py->it_des->sec_d, "  Tears up  ");
    sfText_setPosition(py->it_des->main_d, (sfVector2f) {770, 195});
    sfText_setPosition(py->it_des->sec_d, (sfVector2f) {885, 270});
    return 1;
}

int tooth(player *py)
{
    py->st.freq_tears += 1;
    py->st.shot_speed += 1;
    py->it_des->active = true;
    sfClock_restart(py->it_des->des_clock);
    sfText_setString(py->it_des->main_d, "  Toothpicks  ");
    sfText_setString(py->it_des->sec_d, "Tears + shot speed up");
    sfText_setPosition(py->it_des->main_d, (sfVector2f) {770, 195});
    sfText_setPosition(py->it_des->sec_d, (sfVector2f) {885, 270});
    return 1;
}
