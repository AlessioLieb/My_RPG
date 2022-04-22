/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** touch enemy
*/

#include "../includes/motor.h"

bool touch_three_reduce(reduce *red, sfIntRect tears)
{
    sfIntRect tmp;
    sfIntRect overlap = {1, 1, 1, 1};
    bool check = true;
    for (int i = 0; i < 10; ++i) {
        if (red->enem_t->flying_adv[i].pos.x != -1) {
            tmp = sfSprite_getTextureRect(red->enem_t->little_adv[i].sp);
            tmp.left = red->enem_t->flying_adv[i].pos.x;
            tmp.top = red->enem_t->flying_adv[i].pos.y;
            tmp.height *= 2;
            check = (sfIntRect_intersects(&tmp, &tears, &overlap))
                    ? touched_enemy(red, i, 'F') : check;
        }
        if (!check)
            return false;
    }
    return true;
}

bool touch_reduce_reduce(reduce *red, sfIntRect tears)
{
    sfIntRect tmp;
    sfIntRect overlap = {1, 1, 1, 1};
    bool check = true;
    for (int i = 0; i < 10; ++i) {
        if (red->enem_t->little_adv[i].pos.x != -1) {
            tmp = sfSprite_getTextureRect(red->enem_t->little_adv[i].sp);
            tmp.left = red->enem_t->little_adv[i].pos.x;
            tmp.top = red->enem_t->little_adv[i].pos.y;
            check = (sfIntRect_intersects(&tmp, &tears, &overlap))
                    ? touched_enemy(red, i, 'L') : check;
        }
        if (!check)
            return false;
    }
    return touch_three_reduce(red, tears);
}

bool touch_reduce_enemy(reduce *red, sfIntRect tears)
{
    sfIntRect tmp;
    sfIntRect overlap = {1, 1, 1, 1};
    bool check = true;
    for (int i = 0; i < 10; ++i) {
        if (red->enem_t->no_moving_adv[i].pos.x != -1) {
            tmp = sfSprite_getTextureRect(red->enem_t->no_moving_adv[i].sp);
            tmp.left = red->enem_t->no_moving_adv[i].pos.x;
            tmp.top = red->enem_t->no_moving_adv[i].pos.y;
            check = (sfIntRect_intersects(&tmp, &tears, &overlap))
                    ? touched_enemy(red, i, 'N') : check;
        }
        if (!check)
            return false;
    }
    return touch_reduce_reduce(red, tears);
}

bool touch_enemy(sfVector2f tears_pos, reduce *red)
{
    sfIntRect tears = (sfIntRect) {tears_pos.x, tears_pos.y, 45, 45};
    sfIntRect tmp;
    sfIntRect overlap = {1, 1, 1, 1};
    bool check = true;
    for (int i = 0; i < 10; ++i) {
        if (red->enem_t->big_adv[i].pos.x != -1) {
            tmp = sfSprite_getTextureRect(red->enem_t->big_adv[i].sp);
            tmp.left = red->enem_t->big_adv[i].pos.x;
            tmp.top = red->enem_t->big_adv[i].pos.y;
            tmp.height *= 2;
            check = (sfIntRect_intersects(&tmp, &tears, &overlap))
                    ? touched_enemy(red, i, 'I') : check;
        }
        if (!check)
            return false;
    }
    return touch_reduce_enemy(red, tears);
}
