/*
** EPITECH PROJECT, 2021
** B-MUL-200-MLH-2-1-myrpg-robin.denni
** File description:
** specific_item3.c
*/

#include "../includes/motor.h"

int bandage(player *py)
{
    py->lf.total_life += 2;
    py->lf.blue_hearth += 4;
    py->it_des->active = true;
    sfClock_restart(py->it_des->des_clock);
    sfText_setString(py->it_des->main_d, "SUPER BANDAGE");
    sfText_setString(py->it_des->sec_d, "  +2 Hearts ");
    sfText_setPosition(py->it_des->main_d, (sfVector2f){770, 195});
    sfText_setPosition(py->it_des->sec_d, (sfVector2f){885, 270});
    return 1;
}

int body(player *py)
{
    py->lf.total_life += 4;
    py->it_des->active = true;
    sfClock_restart(py->it_des->des_clock);
    sfText_setString(py->it_des->main_d, "   The Body   ");
    sfText_setString(py->it_des->sec_d, " I Feel All ");
    sfText_setPosition(py->it_des->main_d, (sfVector2f){770, 195});
    sfText_setPosition(py->it_des->sec_d, (sfVector2f){885, 270});
    return 1;
}

int soul(player *py)
{
    py->speed += 1;
    py->lf.blue_hearth += 2;
    py->it_des->active = true;
    sfClock_restart(py->it_des->des_clock);
    sfText_setString(py->it_des->main_d, "   The Soul   ");
    sfText_setString(py->it_des->sec_d, "  I Am All  ");
    sfText_setPosition(py->it_des->main_d, (sfVector2f){770, 195});
    sfText_setPosition(py->it_des->sec_d, (sfVector2f){885, 270});
    return 1;
}

int fat(player *py)
{
    py->speed -= 1;
    py->lf.total_life += 4;
    py->it_des->active = true;
    sfClock_restart(py->it_des->des_clock);
    sfText_setString(py->it_des->main_d, "Bucket Of Lard");
    sfText_setString(py->it_des->sec_d, "HP Up");
    sfText_setPosition(py->it_des->main_d, (sfVector2f){770, 195});
    sfText_setPosition(py->it_des->sec_d, (sfVector2f){885, 270});
    return 1;
}

int scab(player *py)
{
    py->st.luck += 1;
    py->lf.total_life += 2;
    py->it_des->active = true;
    sfClock_restart(py->it_des->des_clock);
    sfText_setString(py->it_des->main_d, "  Magic Scab  ");
    sfText_setString(py->it_des->sec_d, "HP + luck up");
    sfText_setPosition(py->it_des->main_d, (sfVector2f){770, 195});
    sfText_setPosition(py->it_des->sec_d, (sfVector2f){885, 270});
    return 1;
}
