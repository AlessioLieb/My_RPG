/*
** EPITECH PROJECT, 2021
** B-MUL-200-MLH-2-1-myrpg-robin.denni
** File description:
** reduce_item.c
*/

#include "../includes/motor.h"

static void very_too_deep_reduce(collectible *item, int choose, char *tmp)
{
    if (choose == TEARS && strcomp(tmp, "../Sprites/Items/tears_up/5.png")
    == 0)
        item->change = &soul;
    if (choose == TEARS && strcomp(tmp, "../Sprites/Items/tears_up/6.png")
    == 0)
        item->change = &dolly;
    if (choose == TEARS && strcomp(tmp, "../Sprites/Items/tears_up/8.png")
    == 0)
        item->change = &tooth;
}

static void too_deep_reduce(collectible *item, int choose, char *tmp)
{
    if (choose == SPEED && strcomp(tmp, "../Sprites/Items/speed_up/7.png")
    == 0)
        item->change = &speed_ball;
    if (choose == SPEED && strcomp(tmp, "../Sprites/Items/speed_up/8.png")
    == 0)
        item->change = &screw;
    if (choose == TEARS && strcomp(tmp, "../Sprites/Items/tears_up/2.png")
    == 0)
        item->change = &odd;
    if (choose == TEARS && strcomp(tmp, "../Sprites/Items/tears_up/3.png")
    == 0)
        item->change = &squeezy;
    if (choose == TEARS && strcomp(tmp, "../Sprites/Items/tears_up/4.png")
    == 0)
        item->change = &torn;
    very_too_deep_reduce(item, choose, tmp);
}

static void very_deep_reduce(collectible *item, int choose, char *tmp)
{
    if (choose == HEALTH && strcomp(tmp, "../Sprites/Items/health_up/3.png")
    == 0)
        item->change = &body;
    if (choose == HEALTH && strcomp(tmp, "../Sprites/Items/health_up/6.png")
    == 0)
        item->change = &fat;
    if (choose == HEALTH && strcomp(tmp, "../Sprites/Items/health_up/9.png")
    == 0)
        item->change = &scab;
    if (choose == HEALTH && strcomp(tmp, "../Sprites/Items/health_up/15.png")
    == 0)
        item->change = &meat;
    if (choose == SPEED && strcomp(tmp, "../Sprites/Items/speed_up/2.png")
    == 0)
        item->change = &pyj;
    if (choose == SPEED && strcomp(tmp, "../Sprites/Items/speed_up/4.png")
    == 0)
        item->change = &binky;
    too_deep_reduce(item, choose, tmp);
}

static void deep_reduce(collectible *item, int choose, char *tmp)
{
    if (choose == DMG && strcomp(tmp, "../Sprites/Items/dmg_up/17.png") == 0)
        item->change = &arrow;
    if (choose == DMG && strcomp(tmp, "../Sprites/Items/dmg_up/19.png") == 0)
        item->change = &ipecac;
    if (choose == DMG && strcomp(tmp, "../Sprites/Items/dmg_up/21.png") == 0)
        item->change = &brimstone;
    if (choose == DMG && strcomp(tmp, "../Sprites/Items/dmg_up/25.png") == 0)
        item->change = &cat;
    if (choose == LUCK && strcomp(tmp, "../Sprites/Items/luck_up/0.png") == 0)
        item->change = &mind;
    if (choose == FLY_I && strcomp(tmp, "../Sprites/Items/fly/0.png") == 0)
        item->change = &fate;
    if (choose == FLY_I && strcomp(tmp, "../Sprites/Items/fly/1.png") == 0)
        item->change = &demon;
    if (choose == HEALTH && strcomp(tmp, "../Sprites/Items/health_up/1.png")
    == 0)
        item->change = &bandage;
    very_deep_reduce(item, choose, tmp);
}

void reduce_choose_effect(collectible *item, int choose, char *tmp)
{
    if (choose == ALL_STATS && strcomp(tmp,
    "../Sprites/Items/all_stats_up/0.png") == 0)
        item->change = &god_head;
    if (choose == ALL_STATS && strcomp(tmp,
    "../Sprites/Items/all_stats_up/2.png") == 0)
        item->change = &mushroom;
    if (choose == DMG && strcomp(tmp, "../Sprites/Items/dmg_up/0.png") == 0)
        item->change = &cricket;
    if (choose == DMG && strcomp(tmp, "../Sprites/Items/dmg_up/3.png") == 0)
        item->change = &polyphemus;
    if (choose == DMG && strcomp(tmp, "../Sprites/Items/dmg_up/5.png") == 0)
        item->change = &abaddon;
    if (choose == DMG && strcomp(tmp, "../Sprites/Items/dmg_up/6.png") == 0)
        item->change = &masc;
    if (choose == DMG && strcomp(tmp, "../Sprites/Items/dmg_up/10.png") == 0)
        item->change = &death;
    if (choose == DMG && strcomp(tmp, "../Sprites/Items/dmg_up/11.png") == 0)
        item->change = &stigmata;
    deep_reduce(item, choose, tmp);
}
