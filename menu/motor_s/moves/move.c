/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** move
*/

#include "../../includes/motor.h"

player *creation_player(void)
{
    player *py = malloc(sizeof(player));
    sfIntRect place = {125, 14, 44, 40};
    init_player(py);
    py->lf = create_life();
    py->invulnerability = 0;
    py->invent = create_inventory();
    py->st = create_stats();
    py->player_key = (event_key) {false, false, false, false, false,
    false, false, false};
    py->move_timer = (timer){0, 0};
    py->anim_timer = (timer){0, 0};
    py->tears_timer = (timer){0, 0};
    sfSprite_setTexture(py->sp, py->tx, sfTrue);
    sfSprite_setTextureRect(py->sp, place);
    sfSprite_setScale(py->sp, (sfVector2f){3, 3});
    sfSprite_setPosition(py->sp, (sfVector2f){py->x, py->y});
    py->time = sfClock_create();
    py->change_texture = 0;
    return py;
}

void draw_room(sfRenderWindow *wd, reduce *red, rooms *ro)
{
    int x = red->rm->actual_room[1];
    int y = red->rm->actual_room[0];

    if (ro->lvl == 0 || ro->lvl == 1)
        sfRenderWindow_drawSprite(wd, red->rm->fo, NULL);
    if (ro->lvl == 2 || ro->lvl == 3)
        sfRenderWindow_drawSprite(wd, red->rm->ft, NULL);
    if (ro->lvl == 4)
        sfRenderWindow_drawSprite(wd, red->rm->fl, NULL);
    if (ro->floor_rooms[x][y] == 'M')
        sfRenderWindow_drawSprite(wd, red->rm->shop_room, NULL);
}

int move_sprite(player *py, int top, room *rm)
{
    int next = 0;

    if (!move_sp_top(py, top, rm))
        return 1;
    py->actual_sp ? ++py->actual_sp : 0;
    if (py->actual_sp == 4) {
        sfSprite_setTextureRect(py->sp, (sfIntRect){222, top - 5, 44, 40});
        py->actual_sp = 0;
        next = 1;
    }
    if (py->actual_sp == 2 && !next)
        sfSprite_setTextureRect(py->sp, (sfIntRect) {125, top - 5, 44, 40});
    if (py->actual_sp == 0 && !next) {
        sfSprite_setTextureRect(py->sp, (sfIntRect) {27, top - 5, 44, 40});
        py->actual_sp = 1;
    }
    if (py->invulnerability >= 0 && rand() % 2 == 0)
        sfSprite_setTextureRect(py->sp, (sfIntRect){176, 176, 44, 40});
    return 0;
}

void key_action_realeased(sfEvent event, reduce *red)
{
    if (event.type == sfEvtKeyReleased) {
        red->py->player_key.key_q = event.key.code == sfKeyQ ? false :
        red->py->player_key.key_q;
        red->py->player_key.key_d = event.key.code == sfKeyD ? false :
        red->py->player_key.key_d;
        red->py->player_key.key_z = event.key.code == sfKeyZ ? false :
        red->py->player_key.key_z;
        red->py->player_key.key_s = event.key.code == sfKeyS ? false :
        red->py->player_key.key_s;
        red->py->player_key.key_left = event.key.code == sfKeyLeft ? false :
        red->py->player_key.key_left;
        red->py->player_key.key_right = event.key.code == sfKeyRight ? false :
        red->py->player_key.key_right;
        red->py->player_key.key_up = event.key.code == sfKeyUp ? false :
        red->py->player_key.key_up;
        red->py->player_key.key_down = event.key.code == sfKeyDown ? false :
        red->py->player_key.key_down;
    }
}

void key_action_pressed(sfEvent event, reduce *red)
{
    if (event.type == sfEvtKeyPressed) {
        red->py->player_key.key_q = event.key.code == sfKeyQ ? true :
        red->py->player_key.key_q;
        red->py->player_key.key_d = event.key.code == sfKeyD ? true :
        red->py->player_key.key_d;
        red->py->player_key.key_z = event.key.code == sfKeyZ ? true :
        red->py->player_key.key_z;
        red->py->player_key.key_s = event.key.code == sfKeyS ? true :
        red->py->player_key.key_s;
        red->py->player_key.key_left = event.key.code == sfKeyLeft ? true :
        red->py->player_key.key_left;
        red->py->player_key.key_right = event.key.code == sfKeyRight ? true :
        red->py->player_key.key_right;
        red->py->player_key.key_up = event.key.code == sfKeyUp ? true :
        red->py->player_key.key_up;
        red->py->player_key.key_down = event.key.code == sfKeyDown ? true :
        red->py->player_key.key_down;
    }
    key_action_realeased(event, red);
}
