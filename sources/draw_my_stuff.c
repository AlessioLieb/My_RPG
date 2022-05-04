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

int update_my_stuff_end(options *opt, window *wndw)
{
    sfVector2f place = {750, 450};
    for (int i = 0; i != opt->invent.len; ++i) {
        sfSprite_setPosition(opt->invent.sprites[i], place);
        place.x += 75;
        sfSprite_setScale(opt->invent.sprites[i],
        (sfVector2f) {3, 3});
        sfRenderWindow_drawSprite(wndw->window, opt->invent.sprites[i], NULL);
    }
    return 1;
}
