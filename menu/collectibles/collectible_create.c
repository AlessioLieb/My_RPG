/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** collectible
*/

#include "../includes/motor.h"

static void launch_piece_bomb(room *rm, sfRenderWindow *wd, player *py,
sfIntRect player) {
    sfIntRect overlap = (sfIntRect){1, 1, 1, 1};
    for (int i = 0; i < 10; ++i) {
        if (rm->bombs[i].pos_collision.left != -1) {
            (sfIntRect_intersects(&rm->bombs[i].pos_collision,
            &player, &overlap)) ? launch_bombs(py, rm, i) : 0;
            sfRenderWindow_drawSprite(wd, rm->bombs[i].sp, NULL);
        }
        if (rm->keys[i].pos_collision.left != -1) {
            (sfIntRect_intersects(&rm->keys[i].pos_collision,
            &player, &overlap)) ? launch_key(py, rm, i) : 0;
            sfRenderWindow_drawSprite(wd, rm->keys[i].sp, NULL);
        }
    }
}

static void draw_bonus_reduce(room *rm, sfRenderWindow *wd, player *py,
sfIntRect player)
{
    sfIntRect overlap = (sfIntRect){1, 1, 1, 1};
    for (int i = 0; i < 10; ++i)
        if (rm->piece[i].pos_collision.left != -1) {
            (sfIntRect_intersects(&rm->piece[i].pos_collision,
            &player, &overlap)) ? launch_piece(py, rm, i) : 0;
            sfRenderWindow_drawSprite(wd, rm->piece[i].sp, NULL);
        }
    if (rm->item != NULL) {
        sfRenderWindow_drawSprite(wd, rm->item->sp, NULL);
        sfRenderWindow_drawSprite(wd, rm->item->altar, NULL);
        (sfIntRect_intersects(&rm->item->pos_collision,
        &player, &overlap)) ? launch_item(py, rm) : 0;
    }
    launch_piece_bomb(rm, wd, py, player);
}

void draw_bonus(room *rm, sfRenderWindow *wd, player *py, rooms *ro)
{
    sfVector2f player_pos = sfSprite_getPosition(py->sp);
    sfIntRect player = (sfIntRect){player_pos.x, player_pos.y, 28 * 3, 33 * 3};
    sfIntRect overlap = (sfIntRect){1, 1, 1, 1};
    for (int i = 0; i < 4; ++i)
        if (rm->red_hearth[i].pos_collision.left != -1) {
            (sfIntRect_intersects(&rm->red_hearth[i].pos_collision,
            &player, &overlap)) ? got_hearth(rm, i, py) : 0;
            sfRenderWindow_drawSprite(wd, rm->red_hearth[i].sp, NULL);
        }
    for (int i = 0; i < 2; ++i)
        if (rm->blue_hearth[i].pos_collision.left != -1) {
            (sfIntRect_intersects(&rm->blue_hearth[i].pos_collision,
            &player, &overlap)) ? got_blue_hearth(rm, i, py) : 0;
            sfRenderWindow_drawSprite(wd, rm->blue_hearth[i].sp, NULL);
        }
    draw_bonus_reduce(rm, wd, py, player);
}

static void place_bonus_reduce(room *rm)
{
    for (int i = 0; i < 10; ++i) {
        if (rand() % (i + 5 - (rm->luck / 3)) == 0) {
            rm->piece[i].pos_collision.left = 200 + rand() % 1400;
            rm->piece[i].pos_collision.top = 200 + rand() % 600;
            sfSprite_setPosition(rm->piece[i].sp, (sfVector2f) {rm->piece[i]
            .pos_collision.left, rm->piece[i].pos_collision.top});
        }
        if (rand() % (i + 7 - (rm->luck / 3)) == 0) {
            rm->bombs[i].pos_collision.left = 200 + rand() % 1400;
            rm->bombs[i].pos_collision.top = 200 + rand() % 600;
            sfSprite_setPosition(rm->bombs[i].sp, (sfVector2f) {rm->bombs[i]
            .pos_collision.left, rm->bombs[i].pos_collision.top});
        }
        if (rand() % (i + 8 - (rm->luck / 3)) == 0) {
            rm->keys[i].pos_collision.left = 200 + rand() % 1400;
            rm->keys[i].pos_collision.top = 200 + rand() % 600;
            sfSprite_setPosition(rm->keys[i].sp, (sfVector2f) {rm->keys[i]
            .pos_collision.left, rm->keys[i].pos_collision.top});
        }
    }
}

void place_bonus(room *rm)
{
    for (int i = 0; i < 4; ++i)
        if (rand() % (i + 20 - rm->luck) == 0) {
            rm->red_hearth[i].pos_collision.left = 200 + rand() % 1400;
            rm->red_hearth[i].pos_collision.top = 200 + rand() % 600;
            sfSprite_setPosition(rm->red_hearth[i].sp,
            (sfVector2f) {rm->red_hearth[i]
            .pos_collision.left, rm->red_hearth[i].pos_collision.top});
        }
    for (int i = 0; i < 2; ++i)
        if (rand() % (i + 40 - rm->luck) == 0) {
            rm->blue_hearth[i].pos_collision.left = 200 + rand() % 1400;
            rm->blue_hearth[i].pos_collision.top = 200 + rand() % 600;
            sfSprite_setPosition(rm->blue_hearth[i].sp,
            (sfVector2f) {rm->blue_hearth[i]
            .pos_collision.left, rm->blue_hearth[i].pos_collision.top});
        }
    place_bonus_reduce(rm);
}
