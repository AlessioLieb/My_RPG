/*
** EPITECH PROJECT, 2021
** menu
** File description:
** room sounds
*/

#include "../includes/music.h"

void play_sound(reduce *red)
{
    /*red->so->p_hurt = sfSound_create();
    sfSoundBuffer *p_hurt =
    sfSoundBuffer_createFromFile("./sounds/sfx/p_hurt.wav");
    sfSound_setBuffer(red->so->p_hurt, p_hurt);*/
    sfSound_play(red->so->p_hurt);
}
