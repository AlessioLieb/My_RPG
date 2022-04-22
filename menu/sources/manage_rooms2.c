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
    if (sprt->win_cond == false)
        sfRenderWindow_drawSprite(wd, red->py->sp, NULL);
    else {
        sfSprite_setPosition(sprt->win, (sfVector2f) {1920 / 2 -
        ((32 * 3.5) / 2), 115});
        sfRenderWindow_drawSprite(wd, sprt->win, NULL);
    }
    draw_stone(red->rm, wd);
    move_tears(2, red, wd);
}

void trap_colisions(options *sprt, room *ry, player *py)
{
    sfIntRect overlap = {1, 1, 1, 1};
    sfIntRect trap = sfSprite_getTextureRect(sprt->trap);
    sfVector2f t_pos = sfSprite_getPosition(sprt->trap);
    sfIntRect player = sfSprite_getTextureRect(py->sp);
    sfVector2f p_pos = sfSprite_getPosition(py->sp);
    player.left = p_pos.x;
    player.top = p_pos.y;
    trap.left = t_pos.x;
    trap.top = t_pos.y;
    if (sfIntRect_intersects(&trap, &player, &overlap) == true
    && sprt->actual_doors[4] == true) {
        sfSprite_setPosition(py->sp, (sfVector2f) {1920 / 2, 1080 / 2});
        sprt->plus_lvl = true;
    }
}

void trophy_colisions(options *sprt, room *rm, player *py)
{
    sfIntRect overlap = {1, 1, 1, 1};
    sfIntRect trophy = sfSprite_getTextureRect(sprt->trophy);
    sfVector2f t_pos = sfSprite_getPosition(sprt->trophy);
    sfIntRect player = sfSprite_getTextureRect(py->sp);
    sfVector2f p_pos = sfSprite_getPosition(py->sp);
    player.left = p_pos.x;
    player.top = p_pos.y;
    trophy.left = t_pos.x;
    trophy.top = t_pos.y;
    if (sfIntRect_intersects(&trophy, &player, &overlap) == true
    && sprt->actual_doors[5] == true)
        sprt->win_cond = true;
}

void close_door(rooms *ro, options *sprt, int x, int y)
{
    if (ro->floor_rooms[y][x - 1] == ' ' || ro->floor_rooms[y][x - 1] == '?')
        sprt->actual_doors[3] = false;
    if (ro->floor_rooms[y][x + 1] == ' ' || ro->floor_rooms[y][x + 1] == '?')
        sprt->actual_doors[1] = false;
    if (ro->floor_rooms[y - 1][x] == ' ' || ro->floor_rooms[y - 1][x] == '?')
        sprt->actual_doors[0] = false;
    if (ro->floor_rooms[y + 1][x] == ' ' || ro->floor_rooms[y + 1][x] == '?')
        sprt->actual_doors[2] = false;
}
