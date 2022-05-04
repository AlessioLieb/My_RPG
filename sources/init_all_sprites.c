/*
** EPITECH PROJECT, 2021
** B-MUL-200-MLH-2-1-myrpg-robin.denni
** File description:
** init_all_sprites.c
*/

#include "../includes/menu.h"

void reduce_init_sprites(window *wndw, options *sprt)
{
    init_trophy(wndw, sprt);
    init_win(wndw, sprt);
    init_npc(wndw, sprt);
    init_loose_scrn(wndw, sprt);
    init_win_scrn(wndw, sprt);
    init_opt_screen(wndw, sprt);
    init_lvl_m(wndw, sprt);
}

void init_sprites(window *wndw, options *sprt)
{
    init_welcome(wndw, sprt);
    init_barre(wndw, sprt);
    init_pause(wndw, sprt);
    init_tuto(wndw, sprt);
    init_doo(wndw, sprt);
    init_doc(wndw, sprt);
    init_dto(wndw, sprt);
    init_dtc(wndw, sprt);
    init_dlo(wndw, sprt);
    init_dlc(wndw, sprt);
    init_tdo(wndw, sprt);
    init_tdc(wndw, sprt);
    init_bdo(wndw, sprt);
    init_bdc(wndw, sprt);
    init_trap(wndw, sprt);
    reduce_init_sprites(wndw, sprt);
}
