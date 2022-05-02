/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** npc
*/

#include "../../includes/motor.h"

static void reduce_action_saler(int i, reduce *red)
{
    if (i == KEYS_S && red->py->player_key.key_e
    && red->py->invent.key >= 10) {
        red->py->lf.total_life += 2;
        red->py->invent.key -= 10;
        red->py->player_key.key_e = false;
    }
}

static void action_saler(int i, reduce *red)
{
    if (i == MONEY_S && red->py->player_key.key_a
    && red->py->invent.money >= 50) {
        place_item(red->rm);
        red->py->invent.money -= 50;
        red->py->player_key.key_a = false;
    }
    if (i == BOMBS_S && red->py->player_key.key_a
    && red->py->invent.bomb >= 10) {
        red->py->lf.blue_hearth += 2;
        red->py->invent.bomb -= 10;
        red->py->player_key.key_a = false;
    }
    if (i == KEYS_S && red->py->player_key.key_a && red->py->invent.key >= 5 &&
    red->py->lf.red_hearth + 2 <= red->py->lf.total_life) {
        red->py->lf.red_hearth += 2;
        red->py->invent.key -= 5;
        red->py->player_key.key_a = false;
    }
    reduce_action_saler(i, red);
}

static void talking_saler(options *sprt, window *wndw, int i, reduce *red)
{
    sfVector2f prems = {450 + 300 * (i + 1), 190};
    sfVector2f sec = {380 + 300 * (i + 1), 180};
    char *floor = i == 0 ? "\n          [Press a]\n       I'll give you an\n  "
    "  item for 50 coins" : i == 1 ? "\n          [Press a]\n       I'll "
    "give you a \nblue heart for 10 bombs" : i == 2 ? "          [Press a]"
    "\n    I'll give you a red\n     hearth for 5 keys\n          [Press e]"
    "\n  I'll give you a hearth\nplacement for 10 keys" : 0;
    sprt->text_for_npc = sfText_create();
    sfSprite_setPosition(sprt->spbulle_npc, sec);
    sfText_setPosition(sprt->text_for_npc, prems);
    sfText_setFont(sprt->text_for_npc,
    sfFont_createFromFile("ressources/ft.ttf"));
    sfText_setString(sprt->text_for_npc, "place\nholder");
    sfText_setColor(sprt->text_for_npc, sfBlack);
    sfText_setScale(sprt->text_for_npc, (sfVector2f) {0.5, 0.5});
    sfText_setString(sprt->text_for_npc, floor);
    sfRenderWindow_drawSprite(wndw->window, sprt->spbulle_npc, NULL);
    sfRenderWindow_drawText(wndw->window, sprt->text_for_npc, NULL);
}

void touch_saler(sfVector2f player_pos, options *sprt, window *wndw, int i,
reduce *red)
{
    sfIntRect player = (sfIntRect){player_pos.x, player_pos.y, 28 * 3, 33 * 3};
    sfIntRect overlap = (sfIntRect){1, 1, 1, 1};
    if (sfIntRect_intersects(&sprt->sal[i].place_touch, &player, &overlap)) {
        talking_saler(sprt, wndw, i, red);
        action_saler(i, red);
    }
}
