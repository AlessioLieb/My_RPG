/*
** EPITECH PROJECT, 2021
** B-MUL-200-MLH-2-1-myrpg-robin.denni
** File description:
** manage_rooms.c
*/

#include "../includes/motor.h"

void draw_tuto(sfRenderWindow *wd, options *sprt)
{
    sfRenderWindow_drawSprite(wd, sprt->tutorial, NULL);
}

void draw_doors(room *rm, rooms *ro, sfRenderWindow *wd, options *sprt)
{
    if (rm->actual_room[0] == 4 && rm->actual_room[1] == 4)
        draw_tuto(wd, sprt);
}

void floor_pass(rooms *ro, reduce *red)
{
    ++ro->lvl;
    gen_main(ro);
    red->rm->actual_room[0] = 4;
    red->rm->actual_room[1] = 4;
}
