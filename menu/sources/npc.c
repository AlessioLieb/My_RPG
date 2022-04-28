/*
** EPITECH PROJECT, 2021
** menu
** File description:
** draw_npc.c
*/

#include "../includes/motor.h"

void init_bulle_npc(window *wndw, options *sprt)
{
    sfVector2f prems = {240, 180};
    sfIntRect first = {0, 86, 80, 69};
    sprt->spbulle_npc = sfSprite_create();
    sfSprite_setTexture(sprt->spbulle_npc, sprt->text_npc, sfTrue);
    sfSprite_setTextureRect(sprt->spbulle_npc, first);
    sfSprite_setPosition(sprt->spbulle_npc, prems);
    sfSprite_setScale(sprt->spbulle_npc, (sfVector2f) {2, 2});
}

void init_npc(window *wndw, options *sprt)
{
    sfVector2f prems = {300, 250};
    sfIntRect first = {0, 0, 81, 72};
    sprt->npc = sfSprite_create();
    sfSprite_setTexture(sprt->npc, sprt->text_npc, sfTrue);
    sfSprite_setTextureRect(sprt->npc, first);
    sfSprite_setPosition(sprt->npc, prems);
    sfSprite_setScale(sprt->npc, (sfVector2f) {2, 2});
    init_bulle_npc(wndw, sprt);
}

void touch_npc(sfVector2f player_pos, options *sprt, window *wndw)
{
    sfIntRect tmp = {0, 0, 74, 67};
    tmp.left = 300;
    tmp.top = 250;
    sfIntRect player = (sfIntRect){player_pos.x, player_pos.y, 28 * 3, 33 * 3};
    sfIntRect overlap = (sfIntRect){1, 1, 1, 1};
    if (sfIntRect_intersects(&tmp, &player, &overlap))
        sfRenderWindow_drawSprite(wndw->window, sprt->spbulle_npc, NULL);
}

void draw_npc(window *wndw, options *sprt, room *rm, player *py)
{
    sfVector2f player_pos = sfSprite_getPosition(py->sp);
    if (rm->actual_room[0] == 4 && rm->actual_room[1] == 4)
        sfRenderWindow_drawSprite(wndw->window, sprt->npc, NULL);
    touch_npc(player_pos, sprt, wndw);
}