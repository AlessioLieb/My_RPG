/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** tears
*/

#include "../../includes/motor.h"

sfVector2f center_tears(int id, sfVector2f rect, reduce *red)
{
    sfVector2f t_pos = sfSprite_getPosition(red->py->sp);
    rect = (sfVector2f){t_pos.x + 20, t_pos.y};
    id == 1 ? rect.y += 80 : 0;
    id == 2 ? rect.y += 40 : 0;
    id == 2 ? rect.x += 80 : 0;
    id == 3 ? rect.x += 20 : 0;
    id == 4 ? rect.y += 80 : 0;
    id == 4 ? rect.x += 55 : 0;
    return (rect);
}

void shoot_tears(int id, reduce *red)
{
    sfVector2f rect;
    int nb_tears = verif_moving(red, 6);
    change_tears_aspect(red);
    rect = center_tears(id, rect, red);
    sfSprite_setPosition(red->te[nb_tears].t_sp, rect);
    red->te[nb_tears].move = true;
    red->te[nb_tears].is_shot = true;
    id == 1 ? sfSprite_setRotation(red->te[nb_tears].t_sp, 180) : 0;
    id == 1 ? red->te[nb_tears].direction = 1 : 0;
    id == 2 ? sfSprite_setRotation(red->te[nb_tears].t_sp, 0) : 0;
    id == 2 ? red->te[nb_tears].direction = 2 : 0;
    id == 3 ? sfSprite_setRotation(red->te[nb_tears].t_sp, 270) : 0;
    id == 3 ? red->te[nb_tears].direction = 3 : 0;
    id == 4 ? sfSprite_setRotation(red->te[nb_tears].t_sp, 90) : 0;
    id == 4 ? red->te[nb_tears].direction = 4 : 0;
}

void move_tears_up_down(int id, reduce *red, sfRenderWindow *wd, int i)
{
    if (red->te[i].direction == 3 && red->te[i].is_shot == true
    && check_collisions(3, red, i)) {
        sfSprite_move(red->te[i].t_sp, (sfVector2f){0, -red->te[i].speed});
        sfRenderWindow_drawSprite(wd, red->te[i].t_sp, NULL);
    }
    if (red->te[i].direction == 4 && red->te[i].is_shot == true
    && check_collisions(4, red, i)) {
        sfSprite_move(red->te[i].t_sp, (sfVector2f){0, red->te[i].speed});
        sfRenderWindow_drawSprite(wd, red->te[i].t_sp, NULL);
    }
}

void move_tears(int id, reduce *red, sfRenderWindow *wd)
{
    int nb_tears = verif_moving(red, 6);
    int i = 0;
    while (i < 1000) {
        if (red->te[i].direction == 1 && red->te[i].is_shot == true
        && check_collisions(1, red, i)) {
            sfSprite_move(red->te[i].t_sp,
            (sfVector2f){-red->te[i].speed, 0});
            sfRenderWindow_drawSprite(wd, red->te[i].t_sp, NULL);
        }
        if (red->te[i].direction == 2 && red->te[i].is_shot == true
        && check_collisions(2, red, i)) {
            sfSprite_move(red->te[i].t_sp, (sfVector2f){red->te[i].speed, 0});
            sfRenderWindow_drawSprite(wd, red->te[i].t_sp, NULL);
        }
        move_tears_up_down(id, red, wd, i);
        ++i;
    }
}

tears *init_st_array(tears *te, sfIntRect r, player *py)
{
    sfTexture *te_tex =
    sfTexture_createFromFile("assets/alleffects.png", NULL);
    for (int i = 0; i < 1000; ++i) {
        te[i].x = py->x;
        te[i].y = py->y;
        te[i].speed = 2;
        te[i].direction = 0;
        te[i].t_sp = sfSprite_create();
        te[i].move = false;
        te[i].is_shot = false;
        te[i].actual_sp = 0;
        sfSprite_setTexture(te[i].t_sp, te_tex, sfTrue);
        sfSprite_setTextureRect(te[i].t_sp, r);
        sfSprite_setScale(te[i].t_sp, (sfVector2f){3, 3});
    }
    return te;
}
