/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** run
*/

#ifndef MUSIC_H_
    #define MUSIC_H_

    #include "motor.h"

void floor_pass(rooms *ro, reduce *red, options *sprt, music *mu);
void music_launcher(reduce *red, int floor, int state, music *mu);
music *create_music(void);
void reduce_clear_display(window *wndw);
sounds *create_sounds(void);
void play_sound_hurt(reduce *red);
void play_sound_dies(void);
slide_bar *create_slide_bar(void);
void sound_bar_handling(reduce *red, slide_bar *s_bar, sfRenderWindow *wd);
int choose_texture_player(reduce *red, options *sprt);
void dopt_sprt(window *wndw, options *sprt, reduce *red, slide_bar *s_bar);

#endif
