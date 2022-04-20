/*
** EPITECH PROJECT, 2021
** B-MUL-200-MLH-2-1-myrpg-robin.denni
** File description:
** reduce.c
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

tears *create_tears(player *py)
{
    tears *te = malloc(sizeof(tears) * 100);
    sfIntRect r = {402, 285, 15, 15};
    te = init_st_array(te, r, py);
}
