/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** item fonction
*/

#include "../includes/motor.h"

int bombs_up(player *py)
{
    py->invent.bomb *= 2;
    py->it_des->active = true;
    py->it_des->l_h_active = true;
    sfClock_restart(py->it_des->des_clock);
    sfText_setString(py->it_des->main_d, " BOMBS UP !");
    sfText_setString(py->it_des->sec_d, "*2 total bombs");
    sfText_setPosition(py->it_des->main_d, (sfVector2f) {800, 195});
    sfText_setPosition(py->it_des->sec_d, (sfVector2f) {875, 270});
    sfText_setColor(py->it_des->l_hud, sfGreen);
    sfText_setPosition(py->it_des->l_hud, (sfVector2f) {175, 300});
    sfText_setString(py->it_des->l_hud, "* 2");
    return 1;
}

int keys_up(player *py)
{
    py->invent.key += 5;
    py->it_des->active = true;
    py->it_des->l_h_active = true;
    sfClock_restart(py->it_des->des_clock);
    sfText_setString(py->it_des->main_d, " KEYS UP !");
    sfText_setString(py->it_des->sec_d, "+ 5 total keys");
    sfText_setPosition(py->it_des->main_d, (sfVector2f) {800, 195});
    sfText_setPosition(py->it_des->sec_d, (sfVector2f) {875, 270});
    sfText_setColor(py->it_des->l_hud, sfGreen);
    sfText_setPosition(py->it_des->l_hud, (sfVector2f) {175, 350});
    sfText_setString(py->it_des->l_hud, "+ 5");
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
    sfText_setPosition(py->it_des->main_d, (sfVector2f) {800, 195});
    sfText_setPosition(py->it_des->sec_d, (sfVector2f) {875, 270});
    sfText_setColor(py->it_des->l_hud, sfGreen);
    sfText_setPosition(py->it_des->l_hud, (sfVector2f) {145, 950});
    sfText_setString(py->it_des->l_hud, "+1");
    return 1;
}

int money_up(player *py)
{
    py->invent.money += 35;
    py->it_des->active = true;
    py->it_des->l_h_active = true;
    sfClock_restart(py->it_des->des_clock);
    sfText_setString(py->it_des->main_d, " MONEY RAIN !");
    sfText_setString(py->it_des->sec_d, "+35 money up");
    sfText_setPosition(py->it_des->main_d, (sfVector2f) {800, 195});
    sfText_setPosition(py->it_des->sec_d, (sfVector2f) {875, 270});
    sfText_setColor(py->it_des->l_hud, sfGreen);
    sfText_setPosition(py->it_des->l_hud, (sfVector2f) {175, 250});
    sfText_setString(py->it_des->l_hud, "+25");
    return 1;
}

int fate(player *py)
{
    py->lf.total_life += 2;
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
    disp_fly_hud(py, 'f');
    return 1;
}
