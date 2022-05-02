/*
** EPITECH PROJECT, 2021
** menu
** File description:
** description
*/

#include "../../includes/motor.h"

void disp_fly_hud(player *py, char c)
{
    if (c == 'f') {
        py->it_des->active = true;
        sfClock_restart(py->it_des->des_clock);
        sfText_setString(py->it_des->main_d, "  FATE ! ");
        sfText_setString(py->it_des->sec_d, "Gives you the ability to fly !");
        sfText_setPosition(py->it_des->main_d, (sfVector2f) {830, 195});
        sfText_setPosition(py->it_des->sec_d, (sfVector2f) {730, 270});
    }
    if (c == 'd') {
        py->it_des->active = true;
        sfClock_restart(py->it_des->des_clock);
        sfText_setString(py->it_des->main_d, "DEMON WINGS");
        sfText_setString(py->it_des->sec_d, "Gives you the ability to fly !");
        sfText_setPosition(py->it_des->main_d, (sfVector2f) {830, 195});
        sfText_setPosition(py->it_des->sec_d, (sfVector2f) {730, 270});
    }
}

void draw_all_texts(reduce *red, sfRenderWindow *wd)
{
    sfText_setColor(red->py->it_des->l_hud, sfGreen);
    sfText_setString(red->py->it_des->l_hud, "+1");
    sfText_setPosition(red->py->it_des->l_hud, (sfVector2f) {150, 650});
    sfRenderWindow_drawText(wd, red->py->it_des->l_hud, NULL);
    sfText_setPosition(red->py->it_des->l_hud, (sfVector2f) {150, 725});
    sfRenderWindow_drawText(wd, red->py->it_des->l_hud, NULL);
    sfText_setPosition(red->py->it_des->l_hud, (sfVector2f) {150, 800});
    sfRenderWindow_drawText(wd, red->py->it_des->l_hud, NULL);
    sfText_setPosition(red->py->it_des->l_hud, (sfVector2f) {150, 875});
    sfRenderWindow_drawText(wd, red->py->it_des->l_hud, NULL);
    sfText_setPosition(red->py->it_des->l_hud, (sfVector2f) {150, 950});
    sfRenderWindow_drawText(wd, red->py->it_des->l_hud, NULL);
}

void disp_description(reduce *red, sfRenderWindow *wd)
{
    sfRenderWindow_drawSprite(wd, red->py->it_des->des, NULL);
    sfRenderWindow_drawText(wd, red->py->it_des->main_d, NULL);
    sfRenderWindow_drawText(wd, red->py->it_des->sec_d, NULL);
    if (red->py->it_des->l_h_active == true)
        sfRenderWindow_drawText(wd, red->py->it_des->l_hud, NULL);
    if (red->py->it_des->all_st_active)
        draw_all_texts(red, wd);
}

void init_description_bis(item_desc *it_des)
{
    sfText_setFont(it_des->main_d, it_des->font);
    sfText_setFont(it_des->sec_d, it_des->font);
    sfText_setFont(it_des->l_hud, it_des->font);
    sfText_setScale(it_des->main_d, (sfVector2f) {2, 2});
    sfText_setScale(it_des->sec_d, (sfVector2f) {1, 1});
    sfText_setScale(it_des->l_hud, (sfVector2f) {0.75, 0.75});

    sfTexture *t = sfTexture_createFromFile("assets/desc_bar.png", NULL);
    sfSprite_setTexture(it_des->des, t, sfTrue);
    sfSprite_setTextureRect(it_des->des, (sfIntRect) {2, 16, 396, 32});
    sfSprite_setPosition(it_des->des, (sfVector2f) {380, 200});
    sfSprite_setScale(it_des->des, (sfVector2f) {3, 3});
}

item_desc *init_description(void)
{
    item_desc *it_des = malloc(sizeof(item_desc));

    it_des->active = false;
    it_des->l_h_active = false;
    it_des->all_st_active = false;
    it_des->main_d = sfText_create();
    it_des->sec_d = sfText_create();
    it_des->l_hud = sfText_create();
    it_des->des = sfSprite_create();
    it_des->font = sfFont_createFromFile("ressources/upheavtt.ttf");
    it_des->des_clock = sfClock_create();
    init_description_bis(it_des);

    return it_des;
}
