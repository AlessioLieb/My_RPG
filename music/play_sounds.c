/*
** EPITECH PROJECT, 2021
** menu
** File description:
** room sounds
*/

#include "../includes/music.h"

void play_sound_hurt(reduce *red)
{
    sfSound_play(red->so->p_hurt);
}

void play_sound_dies()
{
    sfSound *p_die = sfSound_create();
    sfSoundBuffer *p_die_b =
    sfSoundBuffer_createFromFile("./sounds/sfx/p_die.wav");
    sfSound_setBuffer(p_die, p_die_b);
    sfSound_play(p_die);
}
