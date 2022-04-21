/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** hearth
*/

#include "../includes/motor.h"

life create_life(void)
{
    sfTexture *text = sfTexture_createFromFile("../Sprites/hearts.png", NULL);
    life li = (life) {6, 6, 2, sfSprite_create()};
    sfSprite_setTexture(li.h_sp, text, sfTrue);
    sfSprite_setScale(li.h_sp, (sfVector2f) {3, 3});
    return li;
}

void draw_blue_life(player *py, sfRenderWindow *rd)
{
    int j = 0;
    sfSprite_setTextureRect(py->lf.h_sp, (sfIntRect) {1, 17, 13, 12});
    for (; j < (py->lf.blue_hearth / 2); ++j) {
        sfSprite_setPosition(py->lf.h_sp,
        (sfVector2f) {50 + (13 * 3) * j, 100});
        sfRenderWindow_drawSprite(rd, py->lf.h_sp, NULL);
    }
    if ((py->lf.blue_hearth % 2) != 0) {
        sfSprite_setTextureRect(py->lf.h_sp, (sfIntRect) {17, 17, 13, 12});
        sfSprite_setPosition(py->lf.h_sp,
        (sfVector2f) {50 + (13 * 3) * j, 100});
        sfRenderWindow_drawSprite(rd, py->lf.h_sp, NULL);
    }
    --py->invulnerability;
}

void draw_life(player *py, sfRenderWindow *rd)
{
    int i = 0;
    sfSprite_setTextureRect(py->lf.h_sp, (sfIntRect) {33, 1, 13, 12});
    for (int w = 0; w < (py->lf.total_life / 2); ++w) {
        sfSprite_setPosition(py->lf.h_sp, (sfVector2f) {50 + (13 * 3) * w, 50});
        sfRenderWindow_drawSprite(rd, py->lf.h_sp, NULL);
    }
    sfSprite_setTextureRect(py->lf.h_sp, (sfIntRect) {1, 1, 13, 12});
    for (; i < (py->lf.red_hearth / 2); ++i) {
        sfSprite_setPosition(py->lf.h_sp, (sfVector2f) {50 + (13 * 3) * i, 50});
        sfRenderWindow_drawSprite(rd, py->lf.h_sp, NULL);
    }
    if ((py->lf.red_hearth % 2) != 0) {
        sfSprite_setTextureRect(py->lf.h_sp, (sfIntRect) {17, 1, 13, 12});
        sfSprite_setPosition(py->lf.h_sp, (sfVector2f) {50 + (13 * 3) * i, 50});
        sfRenderWindow_drawSprite(rd, py->lf.h_sp, NULL);
        ++i;
    }
    draw_blue_life(py, rd);
}
