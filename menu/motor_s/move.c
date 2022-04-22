/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** move
*/

#include "../includes/motor.h"

player *creation_player(void)
{
    player *py = malloc(sizeof(player));
    sfIntRect place = {130, 19, 28, 35};
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
    py->lf = create_life();
    py->invulnerability = 1000;
    py->invent = create_inventory();
    py->player_key = (event_key) {false, false, false, false, false, false, false, false};
    py->move_timer = (timer){0, 0};
    py->anim_timer = (timer){0, 0};
    py->tears_timer = (timer){0, 0};
    sfSprite_setTexture(py->sp, py->tx, sfTrue);
    sfSprite_setTextureRect(py->sp, place);
    sfSprite_setScale(py->sp, (sfVector2f){3, 3});
    sfSprite_setPosition(py->sp, (sfVector2f){py->x, py->y});
    py->time = sfClock_create();
    return py;
}

void player_room(sfRenderWindow *wd, reduce *red, options *sprt)
{
    sfRenderWindow_drawSprite(wd, red->rm->sp, NULL);
    draw_doors(red->rm, red->ro, wd, sprt);
    sfRenderWindow_drawSprite(wd, red->py->sp, NULL);
    draw_stone(red->rm, wd);
    move_tears(2, red, wd);
}

int move_sprite(player *py, int top, room *rm)
{
    int next = 0;
    if (!move_sp_top(py, top, rm))
        return 1;
    py->actual_sp ? ++py->actual_sp : 0;
    if (py->actual_sp == 4) {
        sfSprite_setTextureRect(py->sp, (sfIntRect){227, top, 28, 34});
        py->actual_sp = 0;
        next = 1;
    }
    if (py->actual_sp == 2 && !next)
        sfSprite_setTextureRect(py->sp, (sfIntRect) {130, top, 29, 34});
    if (py->actual_sp == 0 && !next) {
        sfSprite_setTextureRect(py->sp, (sfIntRect) {32, top, 29, 34});
        py->actual_sp = 1;
    }
    if (py->invulnerability >= 500 && rand() % 2 == 0)
        sfSprite_setTextureRect(py->sp, (sfIntRect){181, 181, 28, 33});
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

void slow_player(player *py)
{
    if (!py->player_key.key_q && py->actual_speed.x < 0)
        ++py->actual_speed.x;
    if (!py->player_key.key_d && py->actual_speed.x > 0)
        --py->actual_speed.x;
    if (!py->player_key.key_z && py->actual_speed.y < 0)
        ++py->actual_speed.y;
    if (!py->player_key.key_s && py->actual_speed.y > 0)
        --py->actual_speed.y;
}

void move_player_check(reduce *red)
{
    red->py->anim_timer.timer_total += sfClock_getElapsedTime
    (red->py->time).microseconds - red->py->anim_timer.timer;
    while (red->py->anim_timer.timer_total > 10000) {
        red->py->player_key.key_q ? move_sprite(red->py, 87, red->rm) : 0;
        red->py->player_key.key_d ? move_sprite(red->py, 149, red->rm) : 0;
        red->py->player_key.key_z ? move_sprite(red->py, 213, red->rm) : 0;
        red->py->player_key.key_s ? move_sprite(red->py, 21, red->rm) : 0;
        red->py->anim_timer.timer_total -= 10000;
    }
    red->py->anim_timer.timer =
    sfClock_getElapsedTime(red->py->time).microseconds;
    red->py->tears_timer.timer_total += sfClock_getElapsedTime
    (red->py->time).microseconds - red->py->tears_timer.timer;
    while (red->py->tears_timer.timer_total > 300000) {
        red->py->player_key.key_left ? shoot_tears(1, red) : 0;
        red->py->player_key.key_right ? shoot_tears(2, red) : 0;
        red->py->player_key.key_up ? shoot_tears(3, red) : 0;
        red->py->player_key.key_down ? shoot_tears(4, red) : 0;
        red->py->tears_timer.timer_total -= 300000;
    }
    red->py->tears_timer.timer =
    sfClock_getElapsedTime(red->py->time).microseconds;
    slow_player(red->py);
}

void move_event(sfEvent event, reduce *red)
{
    key_action_pressed(event, red);
}

room *create_room(char *str)
{
    room *rm = malloc(sizeof(room));
    sfTexture *txt = sfTexture_createFromFile("assets/allrooms.png", NULL);
    sfTexture *text =
    sfTexture_createFromFile("../Sprites/allpickups.png", NULL);
    rm->sp = sfSprite_create();
    sfSprite_setTexture(rm->sp, txt, sfTrue);
    sfSprite_setTextureRect(rm->sp, (sfIntRect){0, 0, 468, 312});
    sfSprite_setScale(rm->sp, (sfVector2f) {1920.0 / 468.0, 1080.0 / 312.0});
    rm->len_stone = 15;
    rm->st = create_stone(str);
    rm->red_hearth = create_red_hearth(text);
    rm->blue_hearth = create_blue_hearth(text);
    rm->piece = create_piece(text);
    return rm;
}
