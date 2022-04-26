/*
** EPITECH PROJECT, 2021
** ouais
** File description:
** main.c
*/

#include "../includes/menu.h"

int call_main_func(char *str)
{
    window *wndw = malloc(sizeof(window));
    options *sprt = malloc(sizeof(options));
    players *perso = malloc(sizeof(players));
    sprt->actual_doors = malloc(sizeof(bool) * 6);
    rooms room = {0, 0, NULL, 0};
    gen_main(&room);
    for (int i = 0; i != 10; ++i)
        printf("%s\n", room.floor_rooms[i]);
    main_func(wndw, sprt, perso, &room);
}

int main(int ac, char **av)
{
    call_main_func(av[1]);
}
