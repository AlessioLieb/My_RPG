/*
** EPITECH PROJECT, 2021
** ouais
** File description:
** main.c
*/

#include "../includes/music.h"

static void reduce_stats_player(reduce *red)
{
    if (red->py->change_texture == 4) {
        red->py->st = (stats) {5, 2, 1, 2, 1};
        red->py->speed = 5;
        red->py->invent = (inventory) {200, 1, 1};
        red->py->lf = (life) {2, 2, 2, red->py->lf.hsp};
    }
}

void stats_player(reduce *red)
{
    if (red->py->change_texture == 1) {
        red->py->st = (stats) {6, 2, 1, 2, 1};
        red->py->speed = 7;
        red->py->invent = (inventory) {50, 1, 0};
        red->py->lf = (life) {6, 6, 0, red->py->lf.hsp};
    }
    if (red->py->change_texture == 2) {
        red->py->st = (stats) {5, 5, 1, 5, 3};
        red->py->speed = 5;
        red->py->invent = (inventory) {0, 15, 5};
        red->py->lf = (life) {3, 3, 0, red->py->lf.hsp};
    }
    if (red->py->change_texture == 3) {
        red->py->st = (stats) {4, 3, 2, 3, 3};
        red->py->speed = 4;
        red->py->invent = (inventory) {30, 7, 2};
        red->py->lf = (life) {6, 6, 4, red->py->lf.hsp};
    }
    reduce_stats_player(red);
}

reduce *init_all_structs(void)
{
    reduce *red = malloc(sizeof(reduce));

    red->wndw = malloc(sizeof(window));
    red->sprt = malloc(sizeof(options));
    red->perso = malloc(sizeof(players));
    red->py = creation_player();
    red->rm = create_room();
    red->te = create_tears(red->py);
    red->enem_t = create_enemies();
    red->so = create_sounds();
    red->s_bar = create_slide_bar();
    red->mu = create_music();
    return red;
}

static int call_main_func(void)
{
    reduce *red = init_all_structs();

    red->sprt->actual_doors = malloc(sizeof(bool) * 6);
    red->sprt->invent.last_pos = (sfVector2f) {200, 550};
    red->sprt->invent.len = 0;
    red->sprt->invent.object = NULL;
    red->sprt->invent.sprites = malloc(sizeof(sfSprite *) * NB_ITEMS + 1);
    rooms room = {0, 0, NULL, 0, NULL, false, NULL};
    gen_main(&room);
    init_mini_map(&room);
    clear_mini_map(&room);
    red->ro = &room;
    main_func(red, &room);
    return 0;
}

int main(void)
{
    srand(time(NULL));
    call_main_func();
    return 0;
}
