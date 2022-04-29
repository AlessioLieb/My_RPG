/*
** EPITECH PROJECT, 2021
** ouais
** File description:
** main.c
*/

#include "../includes/motor.h"

static int call_main_func(void)
{
    window *wndw = malloc(sizeof(window));
    options *sprt = malloc(sizeof(options));
    players *perso = malloc(sizeof(players));
    sprt->actual_doors = malloc(sizeof(bool) * 6);
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
