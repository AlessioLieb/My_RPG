/*
** EPITECH PROJECT, 2021
** B-MUL-200-MLH-2-1-myrpg-robin.denni
** File description:
** reduce_place_stone.c
*/

#include "../../includes/motor.h"

void reduce_place_f(sfImage *f_stone, room *rm, int i)
{
    sfImage_copyImage(rm->room_col, f_stone, i % 22 * 78 + 140 + 10,
    (i / 22 * 90) + 82, (sfIntRect) {0, 0, 0, 0}, sfTrue);
}

void reduce_place_s(sfImage *s_stone, room *rm, int i)
{
    sfImage_copyImage(rm->room_col, s_stone, i % 22 * 78 + 140 + 10,
    (i / 22 * 90) + 82, (sfIntRect) {0, 0, 0, 0}, sfTrue);
}

void reduce_place_t(sfImage *t_stone, room *rm, int i)
{
    sfImage_copyImage(rm->room_col, t_stone, i % 22 * 78 + 140 + 10,
    (i / 22 * 90) + 62, (sfIntRect) {0, 0, 0, 0}, sfTrue);
}
