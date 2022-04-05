
/*
** EPITECH PROJECT, 2021
** B-MUL-100-MLH-1-1-mywndw-oscar.frank
** File description:
** window.c
*/

#include "../includes/menu.h"

void params_window(window *wndw, options *sprt, players *perso)
{
    sfVideoMode mode = {WIDTH, HEIGHT, 32};
    sprt->welcome = sfTexture_createFromFile("ressources/welcome.png", NULL);
    sprt->barre = sfTexture_createFromFile("ressources/barre.png", NULL);
    sprt->pause_txt = sfTexture_createFromFile("ressources/pause.png", NULL);
    perso->txt_perso_wheel = sfTexture_createFromFile("ressources/player_wheel_choose.png", NULL);
    wndw->window = sfRenderWindow_create(mode, "my_world", sfResize | sfClose |
    sfFullscreen, NULL);
}

int event_window(window *wndw, options *sprt)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(wndw->window, &event)) {
        (event.type == sfEvtKeyPressed && sfKeyF4 == event.key.code) ?
        sfRenderWindow_close(wndw->window) : 0;
        (event.type == sfEvtKeyPressed && sfKeyL == event.key.code) ?
        sprt->begin = 0 : 0;
        (event.type == sfEvtMouseButtonReleased) ?
        catch_button(wndw, sprt, event) : 0;
        (event.type == sfEvtMouseButtonPressed) ?
        click_button(wndw, sprt, event) : 0;
        (sprt->begin == 3 && event.type == sfEvtKeyPressed && sfKeyEscape ==
        event.key.code) ? sprt->begin = 4 : 0;
        (sprt->begin == 4 && event.type == sfEvtKeyPressed
        && sfKeyQ == event.key.code) ? sprt->begin = 3 : 0;
    }
    return 0;
}
