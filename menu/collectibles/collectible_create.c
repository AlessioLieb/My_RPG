/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** collectible
*/

#include "../includes/motor.h"

int add_one_red_hearth(player *py)
{
    if (py->lf.total_life <= py->lf.red_hearth)
        return 0;
    if (py->lf.total_life == py->lf.red_hearth + 1) {
        ++py->lf.red_hearth;
        return 1;
    }
    py->lf.red_hearth += 2;
    return 0;
}

int add_one_semi_red_hearth(player *py)
{
    if (py->lf.total_life <= py->lf.red_hearth)
        return 0;
    py->lf.red_hearth++;
    return 1;
}

collectible *create_red_hearth(sfTexture *text)
{
    collectible *r_hearth = malloc(sizeof(collectible) * 5);
    sfIntRect complete = (sfIntRect) {0, 0, 16, 13};
    sfIntRect semi = (sfIntRect) {16, 0, 16, 13};
    srand(time(NULL));
    for (int i = 0; i < 10; ++i) {
        r_hearth[i].sp = sfSprite_create();
        sfSprite_setTexture(r_hearth[i].sp, text, sfTrue);
        if (rand % 2 == 0) {
            sfSprite_setTextureRect(r_hearth[i].sp, complete);
            r_hearth[i].change = &add_one_red_hearth;
        } else {
            sfSprite_setTextureRect(r_hearth[i].sp, semi);
            r_hearth[i].change = &add_one_semi_red_hearth;
        }
        r_hearth[i].pos_collision = (sfIntRect) {-1, -1, 16 * 3, 13 * 3};
        sfSprite_setScale(r_hearth[i].sp, (sfVector2f) {3, 3}));
    }
    return r_hearth;
}

void draw_bonus(room *rm)
{

}
void place_bonus(room *rm)
{
    srand(time(NULL));
    for (int i = 0; i < 5; ++i)
        if (rand() % i + 1 == 0) {
            rm->red_hearth[i].pos_collision.x = 200 + rand() % 1400;
            rm->red_hearth[i].pos_collision.y = 200 + rand() % 600;
    }
}