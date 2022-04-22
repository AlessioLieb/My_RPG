/*
** EPITECH PROJECT, 2021
** B-MUL-100-MLH-1-1-mywndw-oscar.frank
** File description:
** window.c
*/

#include "../includes/menu.h"
#include "../includes/motor.h"

void params_window(window *wndw, options *sprt, players *perso)
{
    sfVideoMode mode = {WIDTH, HEIGHT, 32};
    sprt->welcome = sfTexture_createFromFile("ressources/welcome.png", NULL);
    sprt->barre = sfTexture_createFromFile("ressources/barre.png", NULL);
    sprt->pause_txt = sfTexture_createFromFile("ressources/pause.png", NULL);
    perso->txt_perso_wheel =
    sfTexture_createFromFile("ressources/player_wheel_choose.png", NULL);
    sprt->tuto = sfTexture_createFromFile("../Sprites/allrooms.png", NULL);
    sprt->doors = sfTexture_createFromFile("../Sprites/allroomobjects.png",
    NULL);
    wndw->window = sfRenderWindow_create(mode, "niktameralessio", sfResize
    | sfClose | sfFullscreen, NULL);
}

int event_window(window *wndw, options *sprt, reduce *red)
{
    sfEvent event;
    while (sfRenderWindow_pollEvent(wndw->window, &event)) {
        (event.type == sfEvtKeyPressed && sfKeyF4 == event.key.code)
        ? sfRenderWindow_close(wndw->window) : 0;
        (event.type == sfEvtKeyPressed && sfKeyL == event.key.code)
        ? sprt->begin = 0 : 0;
        (event.type == sfEvtMouseButtonReleased)
        ? catch_button(wndw, sprt, event) : 0;
        (event.type == sfEvtMouseButtonPressed)
        ? click_button(wndw, sprt, event) : 0;
        (sprt->begin == 3 && event.type == sfEvtKeyPressed
        && sfKeyEscape == event.key.code) ? sprt->begin = 4 : 0;
        (sprt->begin == 4 && event.type == sfEvtKeyPressed
        && sfKeyQ == event.key.code) ? sprt->begin = 3 : 0;
        move_event(event, red);
    }
    return 0;
}

void init_rm_sprt(room *rm, options *sprt)
{
    rm->actual_room = malloc(sizeof(int) * 2);
    rm->actual_room[0] = 4;
    rm->actual_room[1] = 4;
    rm->open = true;
    sprt->actual_doors[0] = false;
    sprt->actual_doors[1] = false;
    sprt->actual_doors[2] = false;
    sprt->actual_doors[3] = false;
    sprt->plus_lvl = false;
}
