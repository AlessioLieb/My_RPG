/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** hud
*/

#include "../includes/motor.h"

stats create_stats(void)
{
    stats st;
    st.damages = 3;
    st.freq_tears = 5;
    st.luck = 7;
    st.shot_speed = 5;
    st.speed = 6;
    return st;
}

void disp_speed(reduce *red, sfRenderWindow *wd)
{
    sfText *spe = sfText_create();
    sfFont *font = sfFont_createFromFile("ressources/upheavtt.ttf");
    sfSprite *sp = sfSprite_create();
    sfTexture *s = sfTexture_createFromFile("../Sprites/hudstats.png", NULL);
    sfSprite_setTexture(sp, s, sfTrue);
    sfSprite_setTextureRect(sp, (sfIntRect) {1, 4, 12, 10});
    sfSprite_setScale(sp, (sfVector2f) {3, 3});
    sfSprite_setPosition(sp, (sfVector2f) {74, 650});
    char *speed = str_concat(" ", my_int_str(red->py->st.speed));
    sfText_setFont(spe, font);
    sfText_setString(spe, speed);
    sfText_setPosition(spe, (sfVector2f) {115, 650});
    sfText_setScale(spe, (sfVector2f) {0.75, 0.75});
    sfRenderWindow_drawText(wd, spe, NULL);
    sfRenderWindow_drawSprite(wd, sp, NULL);
    sfText_destroy(spe);
    sfFont_destroy(font);
    sfSprite_destroy(sp);
    sfTexture_destroy(s);
    free(speed);
}

void disp_freq_tears(reduce *red, sfRenderWindow *wd)
{
    sfText *fre = sfText_create();
    sfFont *font = sfFont_createFromFile("ressources/upheavtt.ttf");
    sfSprite *fr = sfSprite_create();
    sfTexture *f = sfTexture_createFromFile("../Sprites/hudstats.png", NULL);
    sfSprite_setTexture(fr, f, sfTrue);
    sfSprite_setTextureRect(fr, (sfIntRect) {32, 2, 13, 12});
    sfSprite_setScale(fr, (sfVector2f) {3, 3});
    sfSprite_setPosition(fr, (sfVector2f) {74, 725});
    char *dam = str_concat(" ", my_int_str(red->py->st.freq_tears));
    sfText_setFont(fre, font);
    sfText_setString(fre, dam);
    sfText_setPosition(fre, (sfVector2f) {115, 725});
    sfText_setScale(fre, (sfVector2f) {0.75, 0.75});
    sfRenderWindow_drawText(wd, fre, NULL);
    sfRenderWindow_drawSprite(wd, fr, NULL);
    sfText_destroy(fre);
    sfFont_destroy(font);
    sfSprite_destroy(fr);
    sfTexture_destroy(f);
    free(dam);
}

void disp_sp_tears(reduce *red, sfRenderWindow *wd)
{
    sfText *spt = sfText_create();
    sfFont *font = sfFont_createFromFile("ressources/upheavtt.ttf");
    sfSprite *sp = sfSprite_create();
    sfTexture *s = sfTexture_createFromFile("../Sprites/hudstats.png", NULL);
    sfSprite_setTexture(sp, s, sfTrue);
    sfSprite_setTextureRect(sp, (sfIntRect) {50, 3, 10, 10});
    sfSprite_setScale(sp, (sfVector2f) {3, 3});
    sfSprite_setPosition(sp, (sfVector2f) {74, 800});
    char *dam = str_concat(" ", my_int_str(red->py->st.shot_speed));
    sfText_setFont(spt, font);
    sfText_setString(spt, dam);
    sfText_setPosition(spt, (sfVector2f) {115, 800});
    sfText_setScale(spt, (sfVector2f) {0.75, 0.75});
    sfRenderWindow_drawText(wd, spt, NULL);
    sfRenderWindow_drawSprite(wd, sp, NULL);
    sfText_destroy(spt);
    sfFont_destroy(font);
    sfSprite_destroy(sp);
    sfTexture_destroy(s);
    free(dam);
}

void disp_damages(reduce *red, sfRenderWindow *wd)
{
    sfText *dmg = sfText_create();
    sfFont *font = sfFont_createFromFile("ressources/upheavtt.ttf");
    sfSprite *da = sfSprite_create();
    sfTexture *d = sfTexture_createFromFile("../Sprites/hudstats.png", NULL);
    sfSprite_setTexture(da, d, sfTrue);
    sfSprite_setTextureRect(da, (sfIntRect) {2, 19, 11, 11});
    sfSprite_setScale(da, (sfVector2f) {3, 3});
    sfSprite_setPosition(da, (sfVector2f) {74, 875});
    char *dam = str_concat(" ", my_int_str(red->py->st.damages));
    sfText_setFont(dmg, font);
    sfText_setString(dmg, dam);
    sfText_setPosition(dmg, (sfVector2f) {115, 875});
    sfText_setScale(dmg, (sfVector2f) {0.75, 0.75});
    sfRenderWindow_drawText(wd, dmg, NULL);
    sfRenderWindow_drawSprite(wd, da, NULL);
    sfText_destroy(dmg);
    sfFont_destroy(font);
    sfSprite_destroy(da);
    sfTexture_destroy(d);
    free(dam);
}

void disp_luck(reduce *red, sfRenderWindow *wd)
{
    sfText *luc = sfText_create();
    sfFont *font = sfFont_createFromFile("ressources/upheavtt.ttf");
    sfSprite *lu = sfSprite_create();
    sfTexture *l = sfTexture_createFromFile("../Sprites/hudstats.png", NULL);
    sfSprite_setTexture(lu, l, sfTrue);
    sfSprite_setTextureRect(lu, (sfIntRect) {19, 19, 9, 10});
    sfSprite_setScale(lu, (sfVector2f) {3, 3});
    sfSprite_setPosition(lu, (sfVector2f) {74, 950});
    char *dam = str_concat(" ", my_int_str(red->py->st.luck));
    sfText_setFont(luc, font);
    sfText_setString(luc, dam);
    sfText_setPosition(luc, (sfVector2f) {115, 950});
    sfText_setScale(luc, (sfVector2f) {0.75, 0.75});
    sfRenderWindow_drawText(wd, luc, NULL);
    sfRenderWindow_drawSprite(wd, lu, NULL);
    sfText_destroy(luc);
    sfFont_destroy(font);
    sfSprite_destroy(lu);
    sfTexture_destroy(l);
    free(dam);
}

void disp_stat_hud(reduce *red, sfRenderWindow *wd)
{
    disp_speed(red, wd);
    disp_freq_tears(red, wd);
    disp_sp_tears(red, wd);
    disp_damages(red, wd);
    disp_luck(red, wd);
}
