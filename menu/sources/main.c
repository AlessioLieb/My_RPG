/*
** EPITECH PROJECT, 2021
** ouais
** File description:
** main.c
*/

#include "../includes/motor.h"

static void reduce_stats_player(reduce *red)
{
    if (red->py->change_texture == 4) {
        red->py->st = (stats) {5, 2, 1, 2, 5};
        red->py->speed = 5;
        red->py->invent = (inventory) {200, 1, 5};
        red->py->lf = (life) {2, 2, 2, red->py->lf.hsp};
    }
}

void stats_player(reduce *red)
{
    if (red->py->change_texture == 1) {
        red->py->st = (stats) {6, 6, 6, 9, 1};
        red->py->speed = 8;
        red->py->invent = (inventory) {50, 1, 0};
        red->py->lf = (life) {8, 8, 0, red->py->lf.hsp};
    }
    if (red->py->change_texture == 2) {
        red->py->st = (stats) {5, 4, 1, 4, 1};
        red->py->speed = 5;
        red->py->invent = (inventory) {0, 5, 1};
        red->py->lf = (life) {3, 3, 0, red->py->lf.hsp};
    }
    if (red->py->change_texture == 3) {
        red->py->st = (stats) {3, 3, 2, 3, 3};
        red->py->speed = 3;
        red->py->invent = (inventory) {15, 1, 2};
        red->py->lf = (life) {6, 6, 4, red->py->lf.hsp};
    }
    reduce_stats_player(red);
}

static int call_main_func(void)
{
    window *wndw = malloc(sizeof(window));
    options *sprt = malloc(sizeof(options));
    players *perso = malloc(sizeof(players));
    sprt->actual_doors = malloc(sizeof(bool) * 6);
    sprt->invent.last_pos = (sfVector2f) {200, 550};
    sprt->invent.len = 0;
    sprt->invent.object = NULL;
    sprt->invent.sprites = malloc(sizeof(sfSprite *) * NB_ITEMS + 1);
    rooms room = {0, 0, NULL, 0, NULL, false, NULL};
    gen_main(&room);
    init_mini_map(&room);
    clear_mini_map(&room);
    main_func(wndw, sprt, perso, &room);
    return 0;
}

int main(void)
{
    srand(time(NULL));
    call_main_func();
    return 0;
}
