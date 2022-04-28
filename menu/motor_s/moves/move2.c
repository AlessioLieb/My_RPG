/*
** EPITECH PROJECT, 2021
** menu
** File description:
** move2.c
*/

#include "../../includes/motor.h"

void slow_player(player *py)
{
    if (!py->player_key.key_q && py->actual_speed.x < 0)
        py->actual_speed.x += 0.25;
    if (!py->player_key.key_d && py->actual_speed.x > 0)
        py->actual_speed.x -= 0.25;
    if (!py->player_key.key_z && py->actual_speed.y < 0)
        py->actual_speed.y += 0.25;
    if (!py->player_key.key_s && py->actual_speed.y > 0)
        py->actual_speed.y -= 0.25;
}

void move_player_check(reduce *red)
{
    red->py->anim_timer.timer_total += sfClock_getElapsedTime
    (red->py->time).microseconds - red->py->anim_timer.timer;
    while (red->py->anim_timer.timer_total > 50000) {
        red->py->player_key.key_q ? move_sprite(red->py, 87, red->rm) : 0;
        red->py->player_key.key_d ? move_sprite(red->py, 149, red->rm) : 0;
        red->py->player_key.key_z ? move_sprite(red->py, 213, red->rm) : 0;
        red->py->player_key.key_s ? move_sprite(red->py, 21, red->rm) : 0;
        red->py->anim_timer.timer_total -= 50000;
    }
    reduce_move_player_check(red);
    while (red->py->tears_timer.timer_total > (500000 / (red->py->st.freq_tears / 2))) {
        red->py->player_key.key_left ? shoot_tears(1, red) :
        red->py->player_key.key_right ? shoot_tears(2, red) :
        red->py->player_key.key_up ? shoot_tears(3, red) :
        red->py->player_key.key_down ? shoot_tears(4, red) : 0;
        red->py->tears_timer.timer_total -= 500000 / (red->py->st.freq_tears / 2);
    }
    red->py->tears_timer.timer =
    sfClock_getElapsedTime(red->py->time).microseconds;
    slow_player(red->py);
}

void move_event(sfEvent event, reduce *red)
{
    key_action_pressed(event, red);
}

void reduce_init_room(room *rm, sfTexture *txt)
{
    rm->fo = sfSprite_create();
    rm->ft = sfSprite_create();
    rm->fl = sfSprite_create();
    rm->shop_room = sfSprite_create();
    rm->item = NULL;
    sfSprite_setTexture(rm->fo, txt, sfTrue);
    sfSprite_setTexture(rm->ft, txt, sfTrue);
    sfSprite_setTexture(rm->fl, txt, sfTrue);
    sfSprite_setTexture(rm->shop_room, txt, sfTrue);
    sfSprite_setTextureRect(rm->fo, (sfIntRect){0, 0, 468, 312});
    sfSprite_setScale(rm->fo, (sfVector2f) {1920.0 / 468.0, 1080.0 / 312.0});
    sfSprite_setTextureRect(rm->ft, (sfIntRect){469, 314, 468, 312});
    sfSprite_setScale(rm->ft, (sfVector2f) {1920.0 / 468.0, 1080.0 / 312.0});
    sfSprite_setTextureRect(rm->fl, (sfIntRect){0, 627, 468, 312});
    sfSprite_setScale(rm->fl, (sfVector2f) {1920.0 / 468.0, 1080.0 / 312.0});
    sfSprite_setTextureRect(rm->shop_room, (sfIntRect) {469, 0 , 468, 312});
    sfSprite_setScale(rm->shop_room,
    (sfVector2f) {1920.0 / 468.0, 1080.0 / 312.0});
}

room *create_room(void)
{
    room *rm = malloc(sizeof(room));
    sfTexture *txt = sfTexture_createFromFile("assets/allrooms.png", NULL);
    sfTexture *text =
    sfTexture_createFromFile("../Sprites/allpickups.png", NULL);
    reduce_init_room(rm, txt);
    rm->len_stone = 15;
    rm->st = NULL;
    rm->red_hearth = create_red_hearth(text);
    rm->blue_hearth = create_blue_hearth(text);
    rm->piece = create_piece(text);
    rm->change_room = true;
    return rm;
}
