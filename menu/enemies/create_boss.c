/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** create boss
*/

#include "../includes/motor.h"

void place_boss_level(enemies_t *enemy)
{
    int choose;
    srand(time(NULL));
    choose = 1;
    enemy->boss_adv[choose].pos.x = WIDTH / 2;
    enemy->boss_adv[choose].pos.y = HEIGHT / 2;
}

boss_t *create_boss(void)
{
    boss_t *boss = malloc(sizeof(boss_t) * LEN_BOSS + 1);
    if (boss == NULL)
        return NULL;
    create_monstro_diggle(boss);
    //boss[LEN_BOSS] = NULL;
    return boss;
}