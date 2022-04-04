/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** basic move
*/

#include "../includes/motor.h"

int check_move_right(player *py)
{
    sfVector2f pos = sfSprite_getPosition(py->sp);
    if (pos.x + py->actual_sp >= WIDTH - 275)
        return 0;
    return 1;
}

int check_move_left(player *py)
{
    sfVector2f pos = sfSprite_getPosition(py->sp);
    if (pos.x - py->actual_sp < 200)
        return 0;
    return 1;
}

int check_move_down(player *py)
{
    sfVector2f pos = sfSprite_getPosition(py->sp);
    if (pos.y - py->actual_sp < 100)
        return 0;
    return 1;
}

int check_move_up(player *py, room *rm)
{
    sfVector2f pos = sfSprite_getPosition(py->sp);
    if (pos.y + py->actual_sp >= HEIGHT - 275 || !collision_stone(rm, py, 0, py->speed))
        return 0;
    return 1;
}

int move_sp_top(player *py, int top, room *rm)
{
    int ret = 0;
    if (top == 21 && check_move_up(py, rm)) {
        sfSprite_move(py->sp, (sfVector2f) {0, py->speed});
        ret = 1;
    }
    if (top == 87 && check_move_left(py)) {
        sfSprite_move(py->sp, (sfVector2f) {-py->speed, 0});
        ret = 1;
    }
    if (top == 149 && check_move_right(py)) {
        sfSprite_move(py->sp, (sfVector2f) {py->speed, 0});
        ret = 1;
    }
    if (top == 213 && check_move_down(py)) {
        sfSprite_move(py->sp, (sfVector2f) {0, -py->speed});
        ret = 1;
    }
    return ret;
}
