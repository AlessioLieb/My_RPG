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
    py->speed = 15;
    py->tx = sfTexture_createFromFile("assets/isaac.png", NULL);
    py->sp = sfSprite_create();
    py->as_moved = false;
    py->actual_sp = 0;
    py->collision_box =
    sfImage_createFromFile("assets/collisions/isaac_border.png");
    py->actual_speed = (sfVector2f) {0, 0};
    sfSprite_setTexture(py->sp, py->tx, sfTrue);
    sfSprite_setTextureRect(py->sp, place);
    sfSprite_setScale(py->sp, (sfVector2f){3, 3});
    sfSprite_setPosition(py->sp, (sfVector2f){py->x, py->y});
    return py;
}

void player_room(sfRenderWindow *wd, reduce *red)
{
    sfRenderWindow_drawSprite(wd, red->rm->sp, NULL);
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
    py->as_moved = 2;
    return 0;
}

void move_event(sfEvent event, reduce *red)
{
    --red->py->as_moved;
    if (event.type == sfEvtKeyPressed) {
        event.key.code == sfKeyQ ? move_sprite(red->py, 87, red->rm) : 0;
        event.key.code == sfKeyD ? move_sprite(red->py, 149, red->rm) : 0;
        event.key.code == sfKeyZ ? move_sprite(red->py, 213, red->rm) : 0;
        event.key.code == sfKeyS ? move_sprite(red->py, 21, red->rm) : 0;
        event.key.code == sfKeyLeft ? shoot_tears(1, red) : 0;
        event.key.code == sfKeyRight ? shoot_tears(2, red) : 0;
        event.key.code == sfKeyUp ? shoot_tears(3, red) : 0;
        event.key.code == sfKeyDown ? shoot_tears(4, red) : 0;
    }
    if (red->py->as_moved <= 0)
        red->py->actual_speed = (sfVector2f) {0, 0};
    sfSprite_move(red->py->sp, red->py->actual_speed);
}

room *create_room(char *str)
{
    room *rm = malloc(sizeof(room));
    sfTexture *txt = sfTexture_createFromFile("assets/allrooms.png", NULL);
    rm->sp = sfSprite_create();
    rm->actual_room = 0;
    sfSprite_setTexture(rm->sp, txt, sfTrue);
    sfSprite_setTextureRect(rm->sp, (sfIntRect){0, 0, 468, 312});
    sfSprite_setScale(rm->sp, (sfVector2f) {1920.0 / 468.0, 1080.0 / 312.0});
    rm->len_stone = 15;
    rm->st = create_stone(str);
    return rm;
}
