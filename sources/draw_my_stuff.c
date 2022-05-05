/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** draw my stuff
*/

#include "../includes/motor.h"

int update_my_stuff(options *opt, char **new_array, int new_len)
{
    if (new_len == opt->invent.len)
        return 0;
    opt->invent.sprites[opt->invent.len] = sfSprite_create();
    sfSprite_setTexture(opt->invent.sprites[opt->invent.len],
    sfTexture_createFromFile(new_array[new_len - 1], NULL), sfTrue);
    if (opt->invent.last_pos.x < 570)
        opt->invent.last_pos.x += 75;
    else {
        opt->invent.last_pos.x = 275;
        opt->invent.last_pos.y += 75;
    }
    sfSprite_setPosition(opt->invent.sprites[opt->invent.len],
    opt->invent.last_pos);
    sfSprite_setScale(opt->invent.sprites[opt->invent.len],
    (sfVector2f) {2, 2});
    opt->invent.len = new_len;
    return 1;
}

void put_params_to_timer(char *nb, sfText *hud, sfFont *font, window *wndw)
{
    sfText_setFont(hud, font);
    sfText_setString(hud, nb);
    sfText_setPosition(hud, (sfVector2f) {(1550), 230});
    sfText_setScale(hud, (sfVector2f) {2, 2});
    sfText_rotate(hud, 10);
    sfText_setColor(hud, sfBlack);
    sfRenderWindow_drawText(wndw->window, hud, NULL);
}


void update_my_stuff_end(options *opt, window *wndw)
{
    sfText *hud = sfText_create();
    sfFont *font = sfFont_createFromFile("ressources/upheavtt.ttf");
    sfVector2f place = {750, 450};
    for (int i = 0; i != opt->invent.len; ++i) {
        if (place.x >= 750 + 75 * 5) {
            place.y += 95;
            place.x = 750;
        }
        sfSprite_setPosition(opt->invent.sprites[i], place);
        place.x += 75;
        sfSprite_setScale(opt->invent.sprites[i],
        (sfVector2f) {3, 3});
        sfRenderWindow_drawSprite(wndw->window, opt->invent.sprites[i], NULL);
    }
    char *nb = str_concat("", my_int_str(wndw->last_time[0]));
    nb = str_concat(nb, " : ");
    nb = str_concat(nb, my_int_str(wndw->last_time[1]));
    put_params_to_timer(nb, hud, font, wndw);
    sfText_destroy(hud);
    sfFont_destroy(font);
}
