/*
** EPITECH PROJECT, 2021
** menu
** File description:
** reduce_basic_move.c
*/

#include "../../includes/motor.h"

int move_sp_top(player *py, int top, room *rm)
{
    if (top == 21 && check_move_up(py, rm)) {
        py->actual_speed.y + 1 < py->speed ? ++py->actual_speed.y : 0;
        py->y += py->speed;
    }
    if (top == 87 && check_move_left(py, rm)) {
        py->actual_speed.x + 1 > -py->speed ? --py->actual_speed.x : 0;
        py->x -= py->speed;
    }
    if (top == 149 && check_move_right(py, rm)) {
        py->actual_speed.x + 1 < py->speed ? ++py->actual_speed.x : 0;
        py->x += py->speed;
    }
    if (top == 213 && check_move_down(py, rm)) {
        py->actual_speed.y + 1 > -py->speed ? --py->actual_speed.y : 0;
        py->y -= py->speed;
    }
}
