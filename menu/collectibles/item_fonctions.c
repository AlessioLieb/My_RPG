/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** item fonction
*/

#include "../includes/motor.h"

int item_damage(player *py)
{
    py->st.damages++;
    return 1;
}

int item_speed(player *py)
{
    py->speed++;
    return 1;
}/*
int item_invu(player *py)
{
    py->speed++;
    return 1;
}
 */

int item_freq(player *py)
{
    py->st.freq_tears++;
    return 1;
}

int item_speed_tears(player *py)
{
    py->st.shot_speed++;
    return 1;
}

int item_life_augmentation(player *py)
{
    py->lf.total_life += 2;
    py->lf.red_hearth += 2;
    return 1;
}

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
    return 1;
}

int all_stat(player *py)
{
    py->st.damages++;
    py->speed++;
    py->st.freq_tears++;
    py->st.shot_speed++;
    py->lf.total_life += 2;
    return 1;
}