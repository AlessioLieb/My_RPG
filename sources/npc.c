/*
** EPITECH PROJECT, 2021
** menu
** File description:
** draw_npc.c
*/

#include "../includes/motor.h"

void init_bulle_npc(window *wndw, options *sprt)
{
    sfVector2f prems = {450, 190};
    sfIntRect first = {5, 94, 142, 67};
    sprt->spbulle_npc = sfSprite_create();
    sprt->text_for_npc = sfText_create();
    sfText_setPosition(sprt->text_for_npc, prems);
    sfText_setFont(sprt->text_for_npc,
    sfFont_createFromFile("ressources/ft.ttf"));
    sfText_setString(sprt->text_for_npc, "place\nholder");
    sfText_setColor(sprt->text_for_npc, sfBlack);
    sfText_setScale(sprt->text_for_npc, (sfVector2f){0.5, 0.5});
    sfSprite_setTexture(sprt->spbulle_npc, sprt->text_npc, sfTrue);
    sfSprite_setTextureRect(sprt->spbulle_npc, first);
    prems.x = 380;
    prems.y = 180;
    sfSprite_setPosition(sprt->spbulle_npc, prems);
    sfSprite_setScale(sprt->spbulle_npc, (sfVector2f){2, 2});
}

static void reduce_init_npc(window *wndw, options *sprt)
{
    sfIntRect money_rect = {82, 25, 28, 34};
    sfIntRect bombs_rect = {120, 26, 28, 34};
    sfIntRect keys_rect = {157, 19, 41, 41};
    sfSprite_setTextureRect(sprt->sal[MONEY_S].sp, money_rect);
    sfSprite_setTextureRect(sprt->sal[BOMBS_S].sp, bombs_rect);
    sfSprite_setTextureRect(sprt->sal[KEYS_S].sp, keys_rect);
    sprt->sal[MONEY_S].place_touch = (sfIntRect){600, 250, 28 * 3, 34 * 10};
    sprt->sal[BOMBS_S].place_touch = (sfIntRect){900, 250, 28 * 3, 34 * 10};
    sprt->sal[KEYS_S].place_touch = (sfIntRect){1200, 250, 28 * 3, 34 * 10};
}

void init_npc(window *wndw, options *sprt)
{
    sfVector2f prems = {300, 250};
    sfIntRect first = {0, 0, 81, 72};
    sprt->npc = sfSprite_create();
    sfSprite_setTexture(sprt->npc, sprt->text_npc, sfTrue);
    sfSprite_setTextureRect(sprt->npc, first);
    sfSprite_setPosition(sprt->npc, prems);
    sfSprite_setScale(sprt->npc, (sfVector2f){2, 2});
    init_bulle_npc(wndw, sprt);
    sprt->sal = malloc(sizeof(saler_t) * LEN_SALER + 1);
    for (int i = 0; i < LEN_SALER; ++i) {
        prems.x += 300;
        sprt->sal[i].sp = sfSprite_create();
        sfSprite_setTexture(sprt->sal[i].sp, sprt->text_npc, sfTrue);
        sfSprite_setScale(sprt->sal[i].sp, (sfVector2f){3, 3});
        sfSprite_setPosition(sprt->sal[i].sp, prems);
    }
    reduce_init_npc(wndw, sprt);
}

void touch_npc(sfVector2f player_pos, options *sprt, window *wndw, int level)
{
    sfIntRect tmp = {0, 0, 130, 250};
    tmp.left = 300;
    tmp.top = 250;
    sfIntRect player = (sfIntRect){player_pos.x, player_pos.y, 28 * 3, 33 * 3};
    sfIntRect overlap = (sfIntRect){1, 1, 1, 1};
    if (sfIntRect_intersects(&tmp, &player, &overlap))
        talking_npc(sprt, wndw, level);
}

void draw_npc(window *wndw, options *sprt, reduce *red)
{
    sfVector2f player_pos = sfSprite_getPosition(red->py->sp);
    if (red->rm->actual_room[0] == 4 && red->rm->actual_room[1] == 4) {
        sfRenderWindow_drawSprite(wndw->window, sprt->npc, NULL);
        touch_npc(player_pos, sprt, wndw, red->ro->lvl);
    }
    if (get_actual_room_char(red) == 'M')
        for (int i = 0; i < LEN_SALER; ++i) {
            sfRenderWindow_drawSprite(wndw->window, sprt->sal[i].sp, NULL);
            touch_saler((saler_red_t){player_pos, i}, sprt, wndw, red);
        }
}
