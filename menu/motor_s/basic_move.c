/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** basic move
*/

#include "../includes/motor.h"

static bool map_collision(player *py)
{
    sfVector2f pos = sfSprite_getPosition(py->sp);
    bool end = true;
    if (pos.x + py->actual_speed.x  + 5 >= WIDTH - 275) {
        sfSprite_setPosition(py->sp, (sfVector2f) {WIDTH - 285, pos.y});
        end = false;
    }
    if (pos.x - py->actual_speed.x - 5 < 200) {
        sfSprite_setPosition(py->sp,(sfVector2f) {210, pos.y});
        end = false;
    }
    if (pos.y - py->actual_speed.y - 5 < 100) {
        sfSprite_setPosition(py->sp,(sfVector2f) {pos.x, 110});
        end = false;
    }
    if (pos.y + py->actual_speed.y + 5 >= HEIGHT - 275) {
        sfSprite_setPosition(py->sp, (sfVector2f) {pos.x, HEIGHT - 285});
        end = false;
    }
    if (!end)
        py->actual_speed = (sfVector2f) {0, 0};
    return end;
}

static int check_move_right(player *py, room *rm)
{
    int tmp_x = py->actual_speed.x >= py->speed ? py->speed : py->actual_speed.x + 1;
    if (!map_collision(py) || !collision_stone
    (rm, py, tmp_x, py->actual_speed.y))
        return 0;
    return 1;
}

static int check_move_left(player *py, room *rm)
{
    int tmp_x = py->actual_speed.x <= -py->speed ? - py->speed : py->actual_speed.x - 1;
    if (!map_collision(py)
    || !collision_stone(rm, py, tmp_x, py->actual_speed.y))
        return 0;
    return 1;
}

static int check_move_down(player *py, room *rm)
{
    int tmp_y = py->actual_speed.y <= -py->speed ? - py->speed : py->actual_speed.y - 1;
    if (!map_collision(py)
    || !collision_stone(rm, py, py->actual_speed.x, (tmp_y)))
        return 0;
    return 1;
}

static int check_move_up(player *py, room *rm)
{
    if (!map_collision(py)
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
