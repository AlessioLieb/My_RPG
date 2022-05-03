/*
** EPITECH PROJECT, 2021
** B-MUL-200-MLH-2-1-myrpg-robin.denni
** File description:
** specific_item5.c
*/

#include "../includes/motor.h"

int abaddon(player *py)
{
    py->st.damages += 1;
    py->st.freq_tears = 9;
    py->it_des->active = true;
    sfClock_restart(py->it_des->des_clock);
    sfText_setString(py->it_des->main_d, "   ABADDON   ");
    sfText_setString(py->it_des->sec_d, "Dmg up+Laser");
    sfText_setPosition(py->it_des->main_d, (sfVector2f) {770, 195});
    sfText_setPosition(py->it_des->sec_d, (sfVector2f) {885, 270});
    return 1;
}

int masc(player *py)
{
    py->st.damages += 1.5;
    py->st.freq_tears >= 3 ? py->st.freq_tears -= 1 : 0;
    py->st.shot_speed >= 3 ? py->st.shot_speed -= 1 : 0;
    py->it_des->active = true;
    sfClock_restart(py->it_des->des_clock);
    sfText_setString(py->it_des->main_d, " EVE'S MASCARA");
    sfText_setString(py->it_des->sec_d, "Dmg up, tears + shot speed down");
    sfText_setPosition(py->it_des->main_d, (sfVector2f) {770, 195});
    sfText_setPosition(py->it_des->sec_d, (sfVector2f) {385, 270});
    return 1;
}

int death(player *py)
{
    py->st.damages += 1;
    py->st.freq_tears += 1;
    py->it_des->active = true;
    sfClock_restart(py->it_des->des_clock);
    sfText_setString(py->it_des->main_d, " DEATH'S TOUCH");
    sfText_setString(py->it_des->sec_d, "Dmg + tears up");
    sfText_setPosition(py->it_des->main_d, (sfVector2f) {770, 195});
    sfText_setPosition(py->it_des->sec_d, (sfVector2f) {885, 270});
    return 1;
}

int stigmata(player *py)
{
    py->st.damages += 1;
    py->lf.total_life += 2;
    py->it_des->active = true;
    sfClock_restart(py->it_des->des_clock);
    sfText_setString(py->it_des->main_d, "  STIGMATA !  ");
    sfText_setString(py->it_des->sec_d, "Dmg + health up");
    sfText_setPosition(py->it_des->main_d, (sfVector2f) {770, 195});
    sfText_setPosition(py->it_des->sec_d, (sfVector2f) {885, 270});
    return 1;
}

int arrow(player *py)
{
    py->st.damages += 1;
    py->st.shot_speed += 1;
    py->it_des->active = true;
    sfClock_restart(py->it_des->des_clock);
    sfText_setString(py->it_des->main_d, "    ARROW !   ");
    sfText_setString(py->it_des->sec_d, "Dmg + shot speed up");
    sfText_setPosition(py->it_des->main_d, (sfVector2f) {770, 195});
    sfText_setPosition(py->it_des->sec_d, (sfVector2f) {885, 270});
    return 1;
}
