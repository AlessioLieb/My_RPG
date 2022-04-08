/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** basic move
*/

#include "../includes/motor.h"

static int check_move_right(player *py, room *rm)
{
    sfVector2f pos = sfSprite_getPosition(py->sp);
    int tmp_x = py->actual_speed.x >= py->speed ? py->speed : py->actual_speed.x + 1;
    if (pos.x + py->actual_speed.x + 5 >= WIDTH - 275
    || !collision_stone(rm, py, tmp_x, py->actual_speed.y))
        return 0;
    return 1;
}

static int check_move_left(player *py, room *rm)
{
    sfVector2f pos = sfSprite_getPosition(py->sp);
    int tmp_x = py->actual_speed.x <= -py->speed ? - py->speed : py->actual_speed.x - 1;
    if (pos.x - py->actual_speed.x < 200
    || !collision_stone(rm, py, tmp_x, py->actual_speed.y))
        return 0;
    return 1;
}

static int check_move_down(player *py, room *rm)
{
    sfVector2f pos = sfSprite_getPosition(py->sp);
    if (pos.y - py->actual_speed.y < 100
    || !collision_stone(rm, py, py->actual_speed.x, - (py->actual_speed.y + 1)))
        return 0;
    return 1;
}

static int check_move_up(player *py, room *rm)
{
    sfVector2f pos = sfSprite_getPosition(py->sp);
    if (pos.y + py->actual_speed.y >= HEIGHT - 275
    || !collision_stone(rm, py, py->actual_speed.x, py->actual_speed.y + 1))
        return 0;
    return 1;
}

int move_sp_top(player *py, int top, room *rm)
{
    int ret = 0;
    if (top == 21 && check_move_up(py, rm)) {
        py->actual_speed.y + 1 < py->speed ? ++py->actual_speed.y : 0;
        ret = 1;
    }
    if (top == 87 && check_move_left(py, rm)) {
        py->actual_speed.x + 1 > -py->speed ? --py->actual_speed.x : 0;
        ret = 1;
    }
    if (top == 149 && check_move_right(py, rm)) {
        py->actual_speed.x + 1 < py->speed ? ++py->actual_speed.x : 0;
        ret = 1;
    }
    if (top == 213 && check_move_down(py, rm)) {
        py->actual_speed.y + 1 > -py->speed ? --py->actual_speed.y : 0;
        ret = 1;
    }
    return ret;
}
