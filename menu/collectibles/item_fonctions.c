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
    return 1;
}
