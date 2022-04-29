/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** tears state
*/

#include "../../includes/motor.h"

void clear_tears(reduce *red)
{
    int i = 0;
    while (i < 100) {
        red->te[i].is_shot = false;
        ++i;
    }
    for (int i = 0; i < 4; ++i)
        red->rm->red_hearth[i].pos_collision.left = -1;
    for (int i = 0; i < 2; ++i)
        red->rm->blue_hearth[i].pos_collision.left = -1;
    for (int i = 0; i < 10; ++i)
        red->rm->piece[i].pos_collision.left = -1;
}

int verif_moving(reduce *red, int nb_tears)
{
    int nb = 0;

    while (nb < 100) {
        if (red->te[nb].is_shot == false)
            return nb;
        ++nb;
    }
    return nb;
}
