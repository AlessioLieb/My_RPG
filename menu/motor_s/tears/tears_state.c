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
