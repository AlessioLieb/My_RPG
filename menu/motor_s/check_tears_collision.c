/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** tears collision
*/

#include "../includes/motor.h"

bool collision_stone_tears(reduce *red, int x, int y, int nb)
{
    sfVector2f pos_tmp;
    sfIntRect tmp;
    sfVector2f tears_tmp = sfSprite_getPosition(red->te[nb].t_sp);
    sfIntRect tears_pos = (sfIntRect)
            {tears_tmp.y + y, tears_tmp.x + x, 15 * 3, 15 * 3};
    sfIntRect overlap = (sfIntRect){1, 1, 1, 1};
    for (int i = 0; i < red->rm->len_stone; ++i) {
        pos_tmp = sfSprite_getPosition(red->rm->st[i].sp);
        tmp = (sfIntRect){pos_tmp.y, pos_tmp.x + 32, 27 * 3, 37};
        if (sfIntRect_intersects(&tmp, &tears_pos, &overlap))
            return false;
    }
    return true;
}

int check_left(sfVector2f pos, reduce *red, int nb)
{
    sfVector2f pos_te = sfSprite_getPosition(red->te[nb].t_sp);
    if ((pos_te.x - red->te[nb].speed) < 200 || !collision_stone_tears(red, -red->te[nb].speed, 0, nb)) {
        red->te[nb].is_shot = false;
        return 1;
    }
    return 0;
}

int check_right(sfVector2f pos, reduce *red, int nb)
{
    sfVector2f pos_te = sfSprite_getPosition(red->te[nb].t_sp);
    if ((pos_te.x + red->te[nb].speed) >= WIDTH - 200 || !collision_stone_tears(red, red->te[nb].speed, 0, nb)) {
        red->te[nb].is_shot = false;
        return 1;
    }
    return 0;
}

int check_up(sfVector2f pos, reduce *red, int nb)
{
    sfVector2f pos_te = sfSprite_getPosition(red->te[nb].t_sp);
    if ((pos_te.y - red->te[nb].speed) < 100 || !collision_stone_tears(red, 0, -red->te[nb].speed, nb)) {
        red->te[nb].is_shot = false;
        return 1;
    }
    return 0;
}

int check_down(sfVector2f pos, reduce *red, int nb)
{
    sfVector2f pos_te = sfSprite_getPosition(red->te[nb].t_sp);
    if ((pos_te.y + red->te[nb].speed) >= HEIGHT - 150 || !collision_stone_tears(red, 0, red->te[nb].speed, nb)) {
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