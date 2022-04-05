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
    sfSprite_setTexture(py->sp, py->tx, sfTrue);
    sfSprite_setTextureRect(py->sp, place);
    sfSprite_setScale(py->sp, (sfVector2f){3, 3});
    sfSprite_setPosition(py->sp, (sfVector2f){py->x, py->y});
    return py;
}

void player_room(player *py, sfRenderWindow *wd, room *rm)
{
    sfRenderWindow_drawSprite(wd, rm->sp, NULL);
    sfRenderWindow_drawSprite(wd, py->sp, NULL);
    draw_stone(rm, wd);
}

int move_sprite(player *py, sfRenderWindow *wd, int top, room *rm)
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
    if (py->actual_sp == 2 && !next) {
        sfSprite_setTextureRect(py->sp, (sfIntRect) {130, top, 29, 34});
    }
    if (py->actual_sp == 0 && !next) {
        sfSprite_setTextureRect(py->sp, (sfIntRect) {32, top, 29, 34});
        py->actual_sp = 1;
    }
    py->as_moved = true;
    return 0;
}

void move_event(player *py, sfRenderWindow *wd, sfEvent event, room *rm)
{
    py->as_moved = false;
    if (event.type == sfEvtKeyPressed) {
        event.key.code == sfKeyE ? sfRenderWindow_close(wd) : 0;
        event.key.code == sfKeyQ ? move_sprite(py, wd, 87, rm) : 0;
        event.key.code == sfKeyD ? move_sprite(py, wd, 149, rm) : 0;
        event.key.code == sfKeyZ ? move_sprite(py, wd, 213, rm) : 0;
        event.key.code == sfKeyS ? move_sprite(py, wd, 21, rm) : 0;
    }
}

room *create_room(void)
{
    room *rm = malloc(sizeof(room));
    sfTexture *txt = sfTexture_createFromFile("assets/allrooms.png", NULL);
    rm->sp = sfSprite_create();
    rm->actual_room = 0;
    sfSprite_setTexture(rm->sp, txt, sfTrue);
    sfSprite_setTextureRect(rm->sp, (sfIntRect){0, 0, 468, 312});
    sfSprite_setScale(rm->sp, (sfVector2f) {1920.0 / 468.0, 1080.0 / 312.0});
    rm->len_stone = 15;
    rm->st = create_stone();
    return rm;
}

int main(void)
{
    sfRenderWindow *wd = sfRenderWindow_create((sfVideoMode)
            {1920, 1080, 32},  "isaac", sfFullscreen | sfClose, NULL);
    player *py = creation_player();
    room *rm = create_room();
    sfEvent event;
    place_stone(rm, py);
    while (sfRenderWindow_isOpen(wd)) {
        sfRenderWindow_clear(wd, sfBlack);
        while (sfRenderWindow_pollEvent(wd, &event))
            move_event(py, wd, event, rm);
        player_room(py, wd, rm);
        sfRenderWindow_display(wd);
    }
    return 1;
}
