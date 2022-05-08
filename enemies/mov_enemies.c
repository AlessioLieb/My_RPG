/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** move enemies
*/

#include "../includes/motor.h"

static bool check_move(sfVector2f tmp, int type, room *rm)
{
    sfImage *img = type == 2
    ? sfImage_createFromFile("assets/collisions/little.png")
    : sfImage_createFromFile("assets/collisions/big.png");
    bool res = true;
    sfVector2u size = sfImage_getSize(img);
    for (int i = 0; i < size.x; ++i)
        for (int j = 0; j < size.y; ++j) {
            res = ((sfImage_getPixel(img, i, j).r > 100 && sfImage_getPixel
                    (rm->room_col, tmp.x + i, tmp.y + j).r > 100)) ? false
                    : res;
        }
    sfImage_destroy(img);
    return res;
}

void move_adv(adv_t *actual, reduce_adv_t ad, reduce *red)
{
    sfVector2f nw_move = actual[ad.i].pos;
    int changed = 0;
    if (fabsf(actual[ad.i].pos.x - ad.player_pos.x) > fabsf
    (actual[ad.i].pos.y - ad.player_pos.y))
        nw_move.x += actual[ad.i].pos.x - ad.player_pos.x > 0
        ? -actual[ad.i].speed : actual[ad.i].speed;
    else
        nw_move.y += actual[ad.i].pos.y - ad.player_pos.y > 0
        ? -actual[ad.i].speed : actual[ad.i].speed;
    if (actual[ad.i].is_flying || actual[ad.i].speed == 0
    || check_move(nw_move, ad.type, red->rm))
        actual[ad.i].pos = nw_move;
}

void mov_all(adv_t *all, sfVector2f player_pos, int type, reduce *red)
{
    for (int i = 0; i < 10; ++i)
        if (all[i].pos.x != - 1 && all[i].pos.y != - 1) {
            move_adv(all, (reduce_adv_t){i, player_pos, type}, red);
            touch_player_enemy(all[i], player_pos, red);
        }
}

void move_boss(boss_t *actual, int i, sfVector2f player_pos)
{
    sfVector2f nw_move = actual[i].pos;
    if (fabsf(actual[i].pos.x - player_pos.x) > fabsf
    (actual[i].pos.y - player_pos.y))
        nw_move.x += actual[i].pos.x - player_pos.x > 0
        ? -actual[i].speed : actual[i].speed;
    else
        nw_move.y += actual[i].pos.y - player_pos.y > 0
        ? -actual[i].speed : actual[i].speed;
    actual[i].pos = nw_move;
}

void mov_all_boss(boss_t *all, sfVector2f player_pos, reduce *red)
{
    for (int i = 0; i < LEN_BOSS; ++i)
        if (all[i].pos.x != - 1 && all[i].pos.y != - 1) {
            move_boss(all, i, player_pos);
            touch_player_boss(all[i], player_pos, red);
        }
}
