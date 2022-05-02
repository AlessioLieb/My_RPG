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
    sfText_setScale(sprt->text_for_npc, (sfVector2f) {0.5, 0.5});
    sfSprite_setTexture(sprt->spbulle_npc, sprt->text_npc, sfTrue);
    sfSprite_setTextureRect(sprt->spbulle_npc, first);
    prems.x = 380;
    prems.y = 180;
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

static char *edit_text_for_draw(char *str)
{
    char *new_str = malloc(sizeof(char) * str_len(str) * 2 + 1);
    int cp = 0;
    int y = 0;
    for (int i = 0; str[i] != '\0'; ++i) {
        ++cp;
        new_str[y] = str[i];
        if (cp > 21 && str[i] == ' ') {
            cp = 0;
            new_str[y] = '\n';
        }
        ++y;
    }
    new_str[y] = '\0';
    return new_str;
}

char *choose_string(int lvl)
{
    if (lvl == 0)
        return "Help me to retrive my trophy ! For you'll need to kill all"
        " the bosses ! Start by getting some items in the treasure room or"
        " in the shop.";
    if (lvl == 1)
        return "\nGreat ! You defeated your first boss ! Now use the items"
        " you earned in the last level for reach the boss of this floor";
    if (lvl == 2)
        return "Oh ? We are in the depths ? We are approching the final boss "
        "! You have now some money and collectibles so don't"
        " forget to check the shop !";
    if (lvl == 3)
        return "I can feel the dark room, we are close ! Speed up you need"
        " to kill the boss from this floor ! You need to kill satan in the"
        " next level !";
    if (lvl == 4)
        return "It's the last time i see you ! Take care of you in the last"
        " level, thanks for all and defeat this giant satan head for me !";
    return "";
}

void touch_npc(sfVector2f player_pos, options *sprt, window *wndw, int level)
{
    sfIntRect tmp = {0, 0, 130, 250};
    sfVector2f prems = {450, 190};
    char *floor;
    tmp.left = 300;
    tmp.top = 250;
    sfIntRect player = (sfIntRect){player_pos.x, player_pos.y, 28 * 3, 33 * 3};
    sfIntRect overlap = (sfIntRect){1, 1, 1, 1};
    if (sfIntRect_intersects(&tmp, &player, &overlap)) {
        sprt->text_for_npc = sfText_create();
        sfText_setPosition(sprt->text_for_npc, prems);
        sfText_setFont(sprt->text_for_npc,
        sfFont_createFromFile("ressources/ft.ttf"));
        sfText_setString(sprt->text_for_npc, "place\nholder");
        sfText_setColor(sprt->text_for_npc, sfBlack);
        sfText_setScale(sprt->text_for_npc, (sfVector2f) {0.5, 0.5});
        floor = edit_text_for_draw(choose_string(level));
        sfText_setString(sprt->text_for_npc, floor);
        sfRenderWindow_drawSprite(wndw->window, sprt->spbulle_npc, NULL);
        sfRenderWindow_drawText(wndw->window, sprt->text_for_npc, NULL);
    }
}

void draw_npc(window *wndw, options *sprt, reduce *red)
{
    sfVector2f player_pos = sfSprite_getPosition(red->py->sp);
    if (red->rm->actual_room[0] == 4 && red->rm->actual_room[1] == 4) {
        sfRenderWindow_drawSprite(wndw->window, sprt->npc, NULL);
        touch_npc(player_pos, sprt, wndw, red->ro->lvl);
    } else
        sfText_setString(sprt->text_for_npc, NULL);
}
