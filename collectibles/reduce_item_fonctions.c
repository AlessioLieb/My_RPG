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
    py->it_des->active = true;
    py->it_des->l_h_active = true;
    sfClock_restart(py->it_des->des_clock);
    sfText_setString(py->it_des->main_d, "DAMAGE UP !");
    sfText_setString(py->it_des->sec_d, "+1 damage");
    sfText_setPosition(py->it_des->main_d, (sfVector2f){800, 195});
    sfText_setPosition(py->it_des->sec_d, (sfVector2f){890, 270});
    sfText_setColor(py->it_des->l_hud, sfGreen);
    sfText_setPosition(py->it_des->l_hud, (sfVector2f){145, 875});
    sfText_setString(py->it_des->l_hud, "+1");
    return 1;
}

int item_speed(player *py)
{
    py->speed++;
    py->it_des->active = true;
    py->it_des->l_h_active = true;
    sfClock_restart(py->it_des->des_clock);
    sfText_setString(py->it_des->main_d, " SPEED UP !");
    sfText_setString(py->it_des->sec_d, "+1 speed");
    sfText_setPosition(py->it_des->main_d, (sfVector2f){800, 195});
    sfText_setPosition(py->it_des->sec_d, (sfVector2f){890, 270});
    sfText_setColor(py->it_des->l_hud, sfGreen);
    sfText_setPosition(py->it_des->l_hud, (sfVector2f){145, 650});
    sfText_setString(py->it_des->l_hud, "+1");
    return 1;
}

int item_freq(player *py)
{
    if (py->st.freq_tears <= 9)
        py->st.freq_tears++;
    py->it_des->active = true;
    py->it_des->l_h_active = true;
    sfClock_restart(py->it_des->des_clock);
    sfText_setString(py->it_des->main_d, " TEARS UP !");
    sfText_setString(py->it_des->sec_d, "+1 tears");
    sfText_setPosition(py->it_des->main_d, (sfVector2f){800, 195});
    sfText_setPosition(py->it_des->sec_d, (sfVector2f){890, 270});
    sfText_setColor(py->it_des->l_hud, sfGreen);
    sfText_setPosition(py->it_des->l_hud, (sfVector2f){145, 725});
    sfText_setString(py->it_des->l_hud, "+1");
    return 1;
}

int item_speed_tears(player *py)
{
    if (py->st.shot_speed <= 10)
    py->st.shot_speed++;
    py->it_des->active = true;
    py->it_des->l_h_active = true;
    sfClock_restart(py->it_des->des_clock);
    sfText_setString(py->it_des->main_d, "SHOT SPEED UP !");
    sfText_setString(py->it_des->sec_d, "+1 shot speed");
    sfText_setPosition(py->it_des->main_d, (sfVector2f){745, 195});
    sfText_setPosition(py->it_des->sec_d, (sfVector2f){865, 270});
    sfText_setColor(py->it_des->l_hud, sfGreen);
    sfText_setPosition(py->it_des->l_hud, (sfVector2f){145, 800});
    sfText_setString(py->it_des->l_hud, "+1");
    return 1;
}

int item_life_augmentation(player *py)
{
    py->lf.total_life += 2;
    py->lf.red_hearth += 2;
    py->it_des->active = true;
    sfClock_restart(py->it_des->des_clock);
    sfText_setString(py->it_des->main_d, "HEALTH UP !");
    sfText_setString(py->it_des->sec_d, "+1 health");
    sfText_setPosition(py->it_des->main_d, (sfVector2f){810, 195});
    sfText_setPosition(py->it_des->sec_d, (sfVector2f){900, 270});
    return 1;
}
