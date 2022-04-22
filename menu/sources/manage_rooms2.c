/*
** EPITECH PROJECT, 2021
** menu
** File description:
** manage_rooms2.c
*/

#include "../includes/motor.h"

void floor_pass(rooms *ro, reduce *red, options *sprt)
{
    ++ro->lvl;
    gen_main(ro);
    red->rm->actual_room[0] = 4;
    red->rm->actual_room[1] = 4;
    sprt->plus_lvl = false;
}

void player_room(sfRenderWindow *wd, reduce *red, options *sprt)
{
    draw_room(wd, red, red->ro);
    draw_doors(red->rm, red->ro, wd, sprt);
    sfRenderWindow_drawSprite(wd, red->py->sp, NULL);
    draw_stone(red->rm, wd);
    move_tears(2, red, wd);
}
