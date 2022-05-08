/*
** EPITECH PROJECT, 2021
** B-MUL-200-MLH-2-1-myrpg-robin.denni
** File description:
** specific_item2.c
*/

#include "../includes/motor.h"

int meat(player *py)
{
    py->st.damages += 1;
    py->lf.total_life += 2;
    py->it_des->active = true;
    sfClock_restart(py->it_des->des_clock);
    sfText_setString(py->it_des->main_d, "    MEAT !    ");
    sfText_setString(py->it_des->sec_d, "HP + dmg up");
    sfText_setPosition(py->it_des->main_d, (sfVector2f){770, 195});
    sfText_setPosition(py->it_des->sec_d, (sfVector2f){885, 270});
    return 1;
}

int pyj(player *py)
{
    py->speed += 1;
    py->lf.blue_hearth += 2;
    py->it_des->active = true;
    sfClock_restart(py->it_des->des_clock);
    sfText_setString(py->it_des->main_d, "   Pyjamas !   ");
    sfText_setString(py->it_des->sec_d, "You Feel Cozy");
    sfText_setPosition(py->it_des->main_d, (sfVector2f){770, 195});
    sfText_setPosition(py->it_des->sec_d, (sfVector2f){885, 270});
    return 1;
}

int binky(player *py)
{
    py->speed += 1;
    py->lf.blue_hearth += 2;
    py->it_des->active = true;
    sfClock_restart(py->it_des->des_clock);
    sfText_setString(py->it_des->main_d, "   Binky !   ");
    sfText_setString(py->it_des->sec_d, "Memories ...");
    sfText_setPosition(py->it_des->main_d, (sfVector2f){770, 195});
    sfText_setPosition(py->it_des->sec_d, (sfVector2f){885, 270});
    return 1;
}

int speed_ball(player *py)
{
    py->speed += 1;
    py->st.shot_speed += 1;
    py->it_des->active = true;
    sfClock_restart(py->it_des->des_clock);
    sfText_setString(py->it_des->main_d, " Speed Ball ! ");
    sfText_setString(py->it_des->sec_d, "Shot + speed up");
    sfText_setPosition(py->it_des->main_d, (sfVector2f){770, 195});
    sfText_setPosition(py->it_des->sec_d, (sfVector2f){885, 270});
    return 1;
}

int screw(player *py)
{
    py->speed += 1;
    py->st.shot_speed += 1;
    py->it_des->active = true;
    sfClock_restart(py->it_des->des_clock);
    sfText_setString(py->it_des->main_d, "   Screw !   ");
    sfText_setString(py->it_des->sec_d, "Shot + speed up");
    sfText_setPosition(py->it_des->main_d, (sfVector2f){770, 195});
    sfText_setPosition(py->it_des->sec_d, (sfVector2f){885, 270});
    return 1;
}
