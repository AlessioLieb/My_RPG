/*
** EPITECH PROJECT, 2021
** menu
** File description:
** draw_npc.c
*/

#include "../includes/motor.h"

void init_npc(window *wndw, options *sprt) {
    sfVector2f prems = {275, 65};
    sfIntRect first = {0, 0, 1920, 1080};
    sprt->npc = sfSprite_create();
    sfSprite_setTexture(sprt->npc, sprt->text_npc, sfTrue);
    sfSprite_setPosition(sprt->npc, prems);
    sfSprite_setScale(sprt->npc, (sfVector2f) {2, 2});
}

void draw_npc(window *wndw, options *sprt, room *rm) {
    if (rm->actual_room[0] == 4 && rm->actual_room[1] == 4)
        sfRenderWindow_drawSprite(wndw->window, sprt->npc, NULL);
}
