/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** item fonction
*/

#include "../includes/motor.h"

int bombs_up(player *py)
{
    py->invent.bomb += 5;
    return 1;
}

int keys_up(player *py)
{
    py->invent.key += 5;
    return 1;
}

int luck_up(player *py)
{
    if (py->st.luck <= 15)
        py->st.luck++;
    py->it_des->active = true;
    py->it_des->l_h_active = true;
    sfClock_restart(py->it_des->des_clock);
    sfText_setString(py->it_des->main_d, " LUCK UP !");
    sfText_setString(py->it_des->sec_d, "+1 luck up");
    sfText_setColor(py->it_des->l_hud, sfGreen);
    sfText_setPosition(py->it_des->l_hud, (sfVector2f) {145, 950});
    sfText_setString(py->it_des->l_hud, "+1");
    return 1;
}

int money_up(player *py)
{
    py->invent.money += 15;
    return 1;
}

int fly_player(player *py)
{
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
    return 1;
}
