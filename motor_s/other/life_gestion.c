/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** hearth
*/

#include "../../includes/motor.h"

life create_life(void)
{
    sfTexture *text = sfTexture_createFromFile("../Sprites/hearts.png", NULL);
    life li = (life) {6, 6, 2, sfSprite_create()};
    sfSprite_setTexture(li.hsp, text, sfTrue);
    sfSprite_setScale(li.hsp, (sfVector2f) {3, 3});
    return li;
}

void draw_blue_life(player *py, sfRenderWindow *rd)
{
    int j = 0;
    sfSprite_setTextureRect(py->lf.hsp, (sfIntRect) {1, 17, 13, 12});
    for (; j < (py->lf.blue_hearth / 2); ++j) {
        sfSprite_setPosition(py->lf.hsp,
        (sfVector2f) {50 + (13 * 3) * j, 100});
        sfRenderWindow_drawSprite(rd, py->lf.hsp, NULL);
    }
    if ((py->lf.blue_hearth % 2) != 0) {
        sfSprite_setTextureRect(py->lf.hsp, (sfIntRect) {17, 17, 13, 12});
        sfSprite_setPosition(py->lf.hsp,
        (sfVector2f) {50 + (13 * 3) * j, 100});
        sfRenderWindow_drawSprite(rd, py->lf.hsp, NULL);
    }
    --py->invulnerability;
}

void draw_life(player *py, sfRenderWindow *rd)
{
    int i = 0;
    sfSprite_setTextureRect(py->lf.hsp, (sfIntRect) {33, 1, 13, 12});
    for (int w = 0; w < (py->lf.total_life / 2); ++w) {
        sfSprite_setPosition(py->lf.hsp, (sfVector2f) {50 + (13 * 3) * w, 50});
        sfRenderWindow_drawSprite(rd, py->lf.hsp, NULL);
    }
    sfSprite_setTextureRect(py->lf.hsp, (sfIntRect) {1, 1, 13, 12});
    for (; i < (py->lf.red_hearth / 2); ++i) {
        sfSprite_setPosition(py->lf.hsp, (sfVector2f) {50 + (13 * 3) * i, 50});
        sfRenderWindow_drawSprite(rd, py->lf.hsp, NULL);
    }
    if ((py->lf.red_hearth % 2) != 0) {
        sfSprite_setTextureRect(py->lf.hsp, (sfIntRect) {17, 1, 13, 12});
        sfSprite_setPosition(py->lf.hsp, (sfVector2f) {50 + (13 * 3) * i, 50});
        sfRenderWindow_drawSprite(rd, py->lf.hsp, NULL);
        ++i;
    }
    draw_blue_life(py, rd);
}

void init_player(player *py)
{
    py->x = WIDTH / 2;
    py->y = HEIGHT / 2;
    py->speed = 5;
    py->tx = sfTexture_createFromFile("assets/isaac.png", NULL);
    py->sp = sfSprite_create();
    py->as_moved = false;
    py->actual_sp = 0;
    py->collision_box =
    sfImage_createFromFile("assets/collisions/isaac_border.png");
    py->actual_speed = (sfVector2f) {0, 0};
}
