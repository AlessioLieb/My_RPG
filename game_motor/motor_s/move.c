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
    py->speed = 10;
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

void move_player(player *py, sfRenderWindow *wd)
{
    sfIntRect nw;
    /*
    if (!py->as_moved) {
        nw = sfSprite_getTextureRect(py->sp);
        nw.left = 130;
        sfSprite_setTextureRect(py->sp, nw);
    }
     */
    sfRenderWindow_drawSprite(wd, py->sp, NULL);
}

void move_sp_top(player *py, int top)
{
    if (top == 21)
        sfSprite_move(py->sp, (sfVector2f){0, py->speed});
    if (top == 87)
        sfSprite_move(py->sp, (sfVector2f){-py->speed, 0});
    if (top == 149)
        sfSprite_move(py->sp, (sfVector2f){py->speed, 0});
    if (top == 213)
        sfSprite_move(py->sp, (sfVector2f){0, -py->speed});
}

int move_sprite(player *py, sfRenderWindow *wd, int top)
{
    int next = 0;
    if (0)
        return 1;
    move_sp_top(py, top);
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

void move_event(player *py, sfRenderWindow *wd, sfEvent event)
{
    py->as_moved = false;
    if (event.type == sfEvtKeyPressed) {
        event.key.code == sfKeyE ? sfRenderWindow_close(wd) : 0;
        event.key.code == sfKeyQ ? move_sprite(py, wd, 87) : 0;
        event.key.code == sfKeyD ? move_sprite(py, wd, 149) : 0;
        event.key.code == sfKeyZ ? move_sprite(py, wd, 213) : 0;
        event.key.code == sfKeyS ? move_sprite(py, wd, 21) : 0;
        printf("%d\n", py->actual_sp);
    }
}

int main(void)
{
    sfRenderWindow *wd = sfRenderWindow_create((sfVideoMode)
            {1920, 1080, 32},  "isaac", sfFullscreen | sfClose, NULL);
    player *py = creation_player();
    sfEvent event;
    while (sfRenderWindow_isOpen(wd)) {
        sfRenderWindow_clear(wd, sfBlack);
        while (sfRenderWindow_pollEvent(wd, &event))
            move_event(py, wd, event);
        move_player(py, wd);
        sfRenderWindow_display(wd);
    }
    return 1;
}