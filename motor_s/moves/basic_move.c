/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** basic move
*/

#include "../../includes/motor.h"

static bool map_collision(player *py)
{
    sfVector2f pos = sfSprite_getPosition(py->sp);
    bool end = true;
    if (pos.x + py->actual_speed.x  + 5 >= WIDTH - 275) {
        sfSprite_setPosition(py->sp, (sfVector2f){WIDTH - 285, pos.y});
        end = false;
    }
    pos.x - py->actual_speed.x - 5 < 200 ?
    sfSprite_setPosition(py->sp,(sfVector2f){210, pos.y}) : 0;
    pos.x - py->actual_speed.x - 5 < 200 ? end = false : 0;
    if (pos.y - py->actual_speed.y - 5 < 100) {
        sfSprite_setPosition(py->sp,(sfVector2f){pos.x, 110});
        end = false;
    }
    if (pos.y + py->actual_speed.y + 5 >= HEIGHT - 275) {
        sfSprite_setPosition(py->sp, (sfVector2f){pos.x, HEIGHT - 285});
        end = false;
    }
    if (!end)
        py->actual_speed = (sfVector2f){0, 0};
    return end;
}

int check_move_right(player *py, room *rm)
{
    int tmp_y = (py->actual_speed.y >= 0) ?  py->actual_speed.y + 10
    : py->actual_speed.y;
    int tmp_x = (py->actual_speed.y >= 0) ? 10 : 0;
    if (!map_collision(py) || !collision_stone
    (rm, py, tmp_x, tmp_y))
        return 0;
    return 1;
}

int check_move_left(player *py, room *rm)
{
    int tmp_x = py->actual_speed.x <= -py->speed
    ? - py->speed : py->actual_speed.x - 1;
    if (!map_collision(py)
    || !collision_stone(rm, py, tmp_x, py->actual_speed.y))
        return 0;
    return 1;
}

int check_move_down(player *py, room *rm)
{
    int tmp_y = py->actual_speed.y <= -py->speed
    ? - py->speed : py->actual_speed.y - 1;
    if (!map_collision(py)
    || !collision_stone(rm, py, py->actual_speed.x, (tmp_y)))
        return 0;
    return 1;
}

int check_move_up(player *py, room *rm)
{
    if (!map_collision(py)
    || !collision_stone(rm, py, py->actual_speed.x, py->actual_speed.y + 1))
        return 0;
    return 1;
}
