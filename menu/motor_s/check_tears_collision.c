/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** tears collision
*/

#include "../includes/motor.h"

int check_left(sfVector2f pos, reduce *red, int nb)
{
    sfVector2f pos_te = sfSprite_getPosition(red->te[nb].t_sp);
    if ((pos_te.x - red->te[nb].speed) < 200
    || !collision_stone_tears(red, -red->te[nb].speed, 0, nb)
    || !touch_enemy(pos_te, red)) {
        red->te[nb].is_shot = false;
        return 1;
    }
    return 0;
}

int check_right(sfVector2f pos, reduce *red, int nb)
{
    sfVector2f pos_te = sfSprite_getPosition(red->te[nb].t_sp);
    if ((pos_te.x + red->te[nb].speed) >= WIDTH - 200
    || !collision_stone_tears(red, red->te[nb].speed, 0, nb)
    || !touch_enemy(pos_te, red)) {
        red->te[nb].is_shot = false;
        return 1;
    }
    return 0;
}

int check_up(sfVector2f pos, reduce *red, int nb)
{
    sfVector2f pos_te = sfSprite_getPosition(red->te[nb].t_sp);
    if ((pos_te.y - red->te[nb].speed) < 100
    || !collision_stone_tears(red, 0, -red->te[nb].speed, nb)
    || !touch_enemy(pos_te, red)) {
        red->te[nb].is_shot = false;
        return 1;
    }
    return 0;
}

int check_down(sfVector2f pos, reduce *red, int nb)
{
    sfVector2f pos_te = sfSprite_getPosition(red->te[nb].t_sp);
    if ((pos_te.y + red->te[nb].speed) >= HEIGHT - 150
    || !collision_stone_tears(red, 0, red->te[nb].speed, nb)
    || !touch_enemy(pos_te, red)) {
        red->te[nb].is_shot = false;
        return 1;
    }
    return 0;
}

int check_collisions(int id, reduce *red, int nb)
{
    sfVector2f pos = sfSprite_getPosition(red->te[nb].t_sp);
    if (id == 1 && !check_left(pos, red, nb))
        return 1;
    if (id == 2 && !check_right(pos, red, nb))
        return 1;
    if (id == 3 && !check_up(pos, red, nb))
        return 1;
    if (id == 4 && !check_down(pos, red, nb))
        return 1;
    return 0;
}
