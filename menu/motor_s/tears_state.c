/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** tears state
*/

#include "../includes/motor.h"

void disp_tears(reduce *red, sfRenderWindow *wd)
{
    int i = 0;
    while (red->te[i].move != false) {
        sfRenderWindow_drawSprite(wd, red->te[i].t_sp, NULL);
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
