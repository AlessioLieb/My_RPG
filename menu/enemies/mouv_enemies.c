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

static void move_adv(adv_t *actual, int i, sfVector2f player_pos, int type, room *rm)
{
    sfVector2f nw_move = actual[i].pos;
    int changed = 0;
    if (fabsf(actual[i].pos.x - player_pos.x) > fabsf
    (actual[i].pos.y - player_pos.y)) {
        nw_move.x += actual[i].pos.x - player_pos
                .x > 0 ? -actual[i].speed : actual[i].speed;
    } else {
        nw_move.y += actual[i].pos.y - player_pos
                .y > 0 ? -actual[i].speed : actual[i].speed;
    }
    if (actual[i].is_flying || actual[i].speed == 0
    || check_move(nw_move, type, rm))
        actual[i].pos = nw_move;
}

static void mouv_all(adv_t *all, sfVector2f player_pos, int type, room *rm)
{
    for (int i = 0; i < 10; ++i)
        if (all[i].pos.x != - 1 && all[i].pos.y != - 1)
            move_adv(all, i, player_pos, type, rm);
}

void move_enemies(enemies_t *enem_t, player *py, room *rm)
{
    sfVector2f p_pos = sfSprite_getPosition(py->sp);
    enem_t->move_ti.timer_total += sfClock_getElapsedTime(enem_t->total_clock)
    .microseconds - enem_t->move_ti.timer;
    while (enem_t->move_ti.timer_total > 50000) {
        mouv_all(enem_t->flying_adv, p_pos, 0, rm);
        mouv_all(enem_t->big_adv, p_pos, 1, rm);
        mouv_all(enem_t->little_adv, p_pos, 2, rm);
        mouv_all(enem_t->no_mouving_adv, p_pos, 3, rm);
        enem_t->move_ti.timer_total -= 50000;
    }
    enem_t->move_ti.timer =
    sfClock_getElapsedTime(enem_t->total_clock).microseconds;
}
