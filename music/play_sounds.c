/*
** EPITECH PROJECT, 2021
** menu
** File description:
** room sounds
*/

#include "../includes/music.h"

void play_sound_hurt(reduce *red)
{
    sfSound_setVolume(red->so->p_hurt, red->so->sound_volume);
    sfSound_play(red->so->p_hurt);
}

void play_sound_dies(reduce *red)
{
    sfSound *p_die = sfSound_create();
    sfSoundBuffer *p_die_b =
    sfSoundBuffer_createFromFile("./sounds/sfx/p_die.wav");
    sfSound_setBuffer(p_die, p_die_b);
    sfSound_setVolume(p_die, red->so->sound_volume);
    sfSound_play(p_die);
}

slide_bar *init_slide_bar(slide_bar *s_bar)
{
    sfVector2f sc = {5, 5};
    sfIntRect r_b = {0, 0, 102, 14};
    sfTexture *b_tex = sfTexture_createFromFile("assets/sound_bar.png", NULL);

    for (int i = 0; i < 2; ++i) {
        s_bar[i].vol = 100;
        s_bar[i].bar = sfSprite_create();
        s_bar[i].bu = sfSprite_create();
        sfSprite_setTexture(s_bar[i].bar, b_tex, sfTrue);
        sfSprite_setTexture(s_bar[i].bu, b_tex, sfTrue);
        sfSprite_setScale(s_bar[i].bar, sc);
        sfSprite_setScale(s_bar[i].bu, sc);
        sfSprite_setTextureRect(s_bar[i].bar, r_b);
    }
    return s_bar;
}

slide_bar *create_slide_bar(void)
{
    slide_bar *s_bar = malloc(sizeof(slide_bar) * 2);

    s_bar = init_slide_bar(s_bar);
    sfIntRect r_bu_r = {0, 14, 28, 25};
    sfIntRect r_bu_b = {0, 39, 28, 25};
    s_bar[0].b_pos = (sfVector2f){850, 180};
    s_bar[1].b_pos = (sfVector2f){850, 340};
    s_bar[0].bu_pos = (sfVector2f){1300, 150};
    s_bar[1].bu_pos = (sfVector2f){1400, 310};
    sfSprite_setTextureRect(s_bar[0].bu, r_bu_r);
    sfSprite_setTextureRect(s_bar[1].bu, r_bu_b);
    sfSprite_setPosition(s_bar[0].bar, s_bar[0].b_pos);
    sfSprite_setPosition(s_bar[1].bar, s_bar[1].b_pos);
    sfSprite_setPosition(s_bar[0].bu, s_bar[0].bu_pos);
    sfSprite_setPosition(s_bar[1].bu, s_bar[1].bu_pos);

    return s_bar;
}

void sound_bar_handling(reduce *red, slide_bar *s_bar, sfRenderWindow *wd)
{
    sfVector2i tmp = sfMouse_getPosition(NULL);
    if (red->sprt->mus_t.mouv_music && tmp.x >= 890 && tmp.x <= 1320) {
        red->sprt->ar_btn[HEAD_MUSIC].pos.x = tmp.x - 50;
        sfSprite_setPosition(red->sprt->ar_btn[HEAD_MUSIC].sprt,
        red->sprt->ar_btn[HEAD_MUSIC].pos);
        red->mu->music_volume = ((red->sprt->ar_btn
        [HEAD_MUSIC].pos.x - 839) / 435.0) * 100.0;
    }
    if (red->sprt->mus_t.mouv_sound && tmp.x >= 890 && tmp.x <= 1320) {
        red->sprt->ar_btn[HEAD_SOUND].pos.x = tmp.x - 50;
        sfSprite_setPosition(red->sprt->ar_btn[HEAD_SOUND].sprt,
        red->sprt->ar_btn[HEAD_SOUND].pos);
        red->so->sound_volume = ((red->sprt->ar_btn
        [HEAD_SOUND].pos.x - 839) / 435.0) * 100.0;
    }
    sfRenderWindow_drawSprite(wd, s_bar[0].bar, NULL);
    sfRenderWindow_drawSprite(wd, s_bar[1].bar, NULL);
}

