/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** tears state
*/

#include "../../includes/motor.h"

void change_tears_aspect(reduce *red)
{
    int nb_tears = verif_moving(red, 6);
    if (red->py->st.damages >= 3 && red->py->st.damages < 6)
        sfSprite_setTextureRect(red->te[nb_tears].t_sp, (sfIntRect)
                {139, 190, 15, 15});
    if (red->py->st.damages >= 6)
        sfSprite_setTextureRect(red->te[nb_tears].t_sp, (sfIntRect)
                {318, 357, 28, 11});
    if (red->py->st.freq_tears >= 8) {
        sfSprite_setTextureRect(red->te[nb_tears].t_sp, (sfIntRect)
                {505, 465, 100, 26});
        sfSprite_setColor(red->te[nb_tears].t_sp, sfRed);
        red->py->st.damages = 0.05;
        red->py->st.freq_tears = 250;
        red->py->st.shot_speed = 75;
        red->py->st.speed = 6;
    }
}

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
    for (int i = 0; i < 10; ++i) {
        red->rm->piece[i].pos_collision.left = -1;
        red->rm->bombs[i].pos_collision.left = -1;
        red->rm->keys[i].pos_collision.left = -1;
    }
    if (red->rm->item != NULL) {
        red->rm->item = NULL;
        red->rm->old_i.cp--;
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
