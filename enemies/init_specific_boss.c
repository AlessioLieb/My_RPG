/*
** EPITECH PROJECT, 2021
** B-MUL-200-MLH-2-1-myrpg-robin.denni
** File description:
** init_specific_boss.c
*/

#include "../includes/motor.h"

sfTexture *init_mdg(sfTexture *text_m, sfTexture *text_d)
{
    text_m = sfTexture_createFromFile("./Sprites/bosses/monstro.png", NULL);
    text_d = sfTexture_createFromFile("./Sprites/bosses/diggle.png", NULL);
    sfTexture *text_g =
    sfTexture_createFromFile("./Sprites/bosses/gurdy.png", NULL);
    return (text_g);
}

sfTexture *init_hgd(sfTexture *t_greed, sfTexture *t_husk)
{
    t_greed = sfTexture_createFromFile("./Sprites/bosses/greed.png", NULL);
    sfTexture *text_dark =
    sfTexture_createFromFile("./Sprites/bosses/dark_one.png", NULL);
    t_husk = sfTexture_createFromFile("./Sprites/bosses/husk.png", NULL);
    return (text_dark);
}
