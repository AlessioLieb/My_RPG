/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** enemies player
*/

#include "../includes/motor.h"

void touch_player_enemy(adv_t adv, sfVector2f player_pos, player *py)
{
    sfIntRect tmp = sfSprite_getTextureRect(adv.sp);
    tmp.left = adv.pos.x;
    tmp.top = adv.pos.y;
    sfIntRect player = (sfIntRect){player_pos.x, player_pos.y, 28 * 3, 33 * 3};
    sfIntRect overlap = (sfIntRect){1, 1, 1, 1};
    if (py->invulnerability <= 0 && sfIntRect_intersects(&tmp, &player,
    &overlap)) {
        py->invulnerability = 500;
        py->lf.blue_hearth > 0 ? --py->lf.blue_hearth : --py->lf.red_hearth;
        sfSprite_setTextureRect(py->sp, (sfIntRect){181, 181, 28, 33});
    }
}

void touch_player_boss(boss_t adv, sfVector2f player_pos, player *py)
{
    sfIntRect tmp = sfSprite_getTextureRect(adv.sp);
    tmp.left = adv.pos.x;
    tmp.top = adv.pos.y;
    sfIntRect player = (sfIntRect){player_pos.x, player_pos.y, 28 * 3, 33 * 3};
    sfIntRect overlap = (sfIntRect){1, 1, 1, 1};
    if (py->invulnerability <= 0 && sfIntRect_intersects(&tmp, &player,
    &overlap)) {
        py->invulnerability = 500;
        if (py->lf.blue_hearth > 1)
            py->lf.blue_hearth -= 2;
        else
            py->lf.red_hearth -= 2;
        sfSprite_setTextureRect(py->sp, (sfIntRect){181, 181, 28, 33});
    }
}
