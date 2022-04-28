/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** item fonction
*/

#include "../includes/motor.h"

int bombs_up(player *py)
{
    py->invent.bomb++;
    return 1;
}

int keys_up(player *py)
{
    py->invent.key++;
    return 1;
}

int luck_up(player *py)
{
    py->invent.money++;
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
    ("assets/collisions/isaac_border.png");
    sfSprite_setTexture(py->sp, sfTexture_createFromFile("assets/theotime_fly.png", NULL), sfFalse);
    return 1;
}
