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
