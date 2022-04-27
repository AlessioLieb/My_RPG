/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** run
*/

#ifndef MUSIC_H_
    #define MUSIC_H_

    #include "motor.h"

typedef struct {
    sfSound *p_hurt;
    sfSound *tr_room;
    sfSound *p_die;
}sounds;

typedef struct {
    sfMusic *men;
    sfMusic *fl_1_2;
    sfMusic *fl_3_4;
    sfMusic *fl_5;
    sfMusic *music;
    int id_m;
    int tmp_id;
    sounds *so;
}music;

void floor_pass(rooms *ro, reduce *red, options *sprt, music *mu);
void music_launcher(reduce *red, int floor, int state, music *mu);
music *create_music(void);

#endif