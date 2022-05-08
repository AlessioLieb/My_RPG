/*
** EPITECH PROJECT, 2021
** B-MUL-200-MLH-2-1-myrpg-robin.denni
** File description:
** specific_item4.c
*/

#include "../includes/motor.h"

int ipecac(player *py)
{
    py->st.damages += 3;
    if (py->st.freq_tears >= 5)
        py->st.freq_tears -= 3;
    else
        py->st.freq_tears = 2;
    py->it_des->active = true;
    sfClock_restart(py->it_des->des_clock);
    sfText_setString(py->it_des->main_d, "    IPECAC    ");
    sfText_setString(py->it_des->sec_d, " MEGA TEARS ");
    sfText_setPosition(py->it_des->main_d, (sfVector2f){770, 195});
    sfText_setPosition(py->it_des->sec_d, (sfVector2f){885, 270});
    return 1;
}

int cat(player *py)
{
    py->st.damages += 1;
    py->speed += 1;
    py->it_des->active = true;
    sfClock_restart(py->it_des->des_clock);
    sfText_setString(py->it_des->main_d, "CAT-O-NINE-TAILS");
    sfText_setString(py->it_des->sec_d, "Dmg + speed up");
    sfText_setPosition(py->it_des->main_d, (sfVector2f){770, 195});
    sfText_setPosition(py->it_des->sec_d, (sfVector2f){885, 270});
    return 1;
}

int brimstone(player *py)
{
    py->st.damages += 1;
    py->st.freq_tears = 9;
    py->it_des->active = true;
    sfClock_restart(py->it_des->des_clock);
    sfText_setString(py->it_des->main_d, "  BRIMSTONE ! ");
    sfText_setString(py->it_des->sec_d, "Brimstone laser");
    sfText_setPosition(py->it_des->main_d, (sfVector2f){770, 195});
    sfText_setPosition(py->it_des->sec_d, (sfVector2f){885, 270});
    return 1;
}

int mind(player *py)
{
    py->st.luck += 1;
    py->st.shot_speed += 1;
    py->it_des->active = true;
    sfClock_restart(py->it_des->des_clock);
    sfText_setString(py->it_des->main_d, "   The Mind   ");
    sfText_setString(py->it_des->sec_d, " I Know All ");
    sfText_setPosition(py->it_des->main_d, (sfVector2f){770, 195});
    sfText_setPosition(py->it_des->sec_d, (sfVector2f){885, 270});
    return 1;
}

int demon(player *py)
{
    py->st.freq_tears = 9;
    py->collision_box = sfImage_createFromFile
    ("assets/collisions/isaac_no_border.png");
    if (py->change_texture == 1)
        sfSprite_setTexture(py->sp, sfTexture_createFromFile
        ("assets/robin_fly.png", NULL), sfFalse);
    if (py->change_texture == 2)
        sfSprite_setTexture(py->sp, sfTexture_createFromFile
        ("assets/theotime_fly.png", NULL), sfFalse);
    if (py->change_texture == 4)
        sfSprite_setTexture(py->sp, sfTexture_createFromFile
        ("assets/oscar_fly.png", NULL), sfFalse);
    if (py->change_texture == 3)
        sfSprite_setTexture(py->sp, sfTexture_createFromFile
        ("assets/alessio_fly.png", NULL), sfFalse);
    disp_fly_hud(py, 'd');
    return 1;
}
