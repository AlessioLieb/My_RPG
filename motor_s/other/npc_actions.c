/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** npc actions
*/

#include "../../includes/motor.h"

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

void talking_npc( options *sprt, window *wndw, int level)
{
    sfVector2f prems = {450, 190};
    sfVector2f sec = {380, 180};
    char *floor;
    sprt->text_for_npc = sfText_create();
    sfSprite_setPosition(sprt->spbulle_npc, sec);
    sfText_setPosition(sprt->text_for_npc, prems);
    sfText_setFont(sprt->text_for_npc,
    sfFont_createFromFile("ressources/ft.ttf"));
    sfText_setString(sprt->text_for_npc, "place\nholder");
    sfText_setColor(sprt->text_for_npc, sfBlack);
    sfText_setScale(sprt->text_for_npc, (sfVector2f){0.5, 0.5});
    floor = edit_text_for_draw(choose_string(level));
    sfText_setString(sprt->text_for_npc, floor);
    sfRenderWindow_drawSprite(wndw->window, sprt->spbulle_npc, NULL);
    sfRenderWindow_drawText(wndw->window, sprt->text_for_npc, NULL);
}

char *choose_string(int lvl)
{
    if (lvl == 0)
        return "Help me to retrive my trophy ! For this kill all the bosses"
        "! Start by this floor by getting some items in the treasure room "
        "or in the shop.";
    if (lvl == 1)
        return "\nGreat ! You defeat your first boss ! Now use the items you "
        "got in the last level for reach the boss of this level";
    if (lvl == 2)
        return "Ho ? We are in the   depths ? We approching of the final boss "
        "! You have now some money or some collectible so don't"
        " forget the shop !";
    if (lvl == 3)
        return "I can feel the dark room from here ! Speed up you need to "
        "kill the boss from here ! You need to kill "
        "satan in the next level !";
    if (lvl == 4)
        return "It's the last time i see you ! Take care of you in the last "
        "level and thanks for all and defeat this giant "
        "satan head for me !";
    return "";
}

void other_keys_pressed(reduce *red, sfEvent event)
{
    red->py->player_key.key_a = event.key.code == sfKeyA ? true :
    red->py->player_key.key_a;
    red->py->player_key.key_e = event.key.code == sfKeyE ? true :
    red->py->player_key.key_e;
}

void other_keys_released(reduce *red, sfEvent event)
{
    red->py->player_key.key_a = event.key.code == sfKeyA ? false :
    red->py->player_key.key_a;
    red->py->player_key.key_e = event.key.code == sfKeyE ? false :
    red->py->player_key.key_e;
}
