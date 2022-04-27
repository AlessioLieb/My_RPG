/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** collectible
*/

#include "../includes/motor.h"

void draw_bonus(room *rm, sfRenderWindow *wd, player *py)
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
    for (int i = 0; i < 2; ++i)
        if (rm->piece[i].pos_collision.left != -1) {
            (sfIntRect_intersects(&rm->piece[i].pos_collision,
            &player, &overlap)) ? launch_piece(py, rm, i) : 0;
            sfRenderWindow_drawSprite(wd, rm->piece[i].sp, NULL);
        }
    if (rm->item != NULL) {
        sfRenderWindow_drawSprite(wd, rm->item->sp, NULL);
        (sfIntRect_intersects(&rm->item->pos_collision,
        &player, &overlap)) ? launch_item(py, rm) : 0;
    }
}

void place_bonus(room *rm)
{
    srand(time(NULL));
    for (int i = 0; i < 4; ++i)
        if (rand() % (i + 20) == 0) {
            rm->red_hearth[i].pos_collision.left = 200 + rand() % 1400;
            rm->red_hearth[i].pos_collision.top = 200 + rand() % 600;
            sfSprite_setPosition(rm->red_hearth[i].sp,
            (sfVector2f) {rm->red_hearth[i]
            .pos_collision.left, rm->red_hearth[i].pos_collision.top});
    }
    for (int i = 0; i < 2; ++i)
        if (rand() % (i + 40) == 0) {
            rm->blue_hearth[i].pos_collision.left = 200 + rand() % 1400;
            rm->blue_hearth[i].pos_collision.top = 200 + rand() % 600;
            sfSprite_setPosition(rm->blue_hearth[i].sp,
            (sfVector2f) {rm->blue_hearth[i]
            .pos_collision.left, rm->blue_hearth[i].pos_collision.top});
        }
    for (int i = 0; i < 10; ++i)
        if (rand() % (i + 5) == 0) {
            rm->piece[i].pos_collision.left = 200 + rand() % 1400;
            rm->piece[i].pos_collision.top = 200 + rand() % 600;
            sfSprite_setPosition(rm->piece[i].sp, (sfVector2f) {rm->piece[i]
            .pos_collision.left, rm->piece[i].pos_collision.top});
        }
}
