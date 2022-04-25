/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** create spe boss
*/

#include "../includes/motor.h"

void create_monstro_diggle(boss_t *boss)
{
    sfTexture *text_monstro = sfTexture_createFromFile("../Sprites/bosses/monstro.png", NULL);
    sfTexture *text_diggle = sfTexture_createFromFile("../Sprites/bosses/diggle.png", NULL);
    sfVector2f scale = {3, 3};
    boss[MONSTRO] = (boss_t){sfSprite_create(), (sfVector2f){-1, -1},50, 3,
    false,84, 253, (boss_spawning_t) {"rooms/monstro.room", 10000, 0, true}};
    sfSprite_setTexture(boss[MONSTRO].sp, text_monstro, sfTrue);
    sfSprite_setScale(boss[MONSTRO].sp, scale);
    sfSprite_setTextureRect(boss[MONSTRO].sp, (sfIntRect) {0, 0, 75, 76});
    boss[DIGGLE] = (boss_t){sfSprite_create(), (sfVector2f){-1, -1},35, 7,
    false,65, 520, (boss_spawning_t) {"rooms/diggle.room", 7500, 0, true}};
    sfSprite_setTexture(boss[DIGGLE].sp, text_diggle, sfTrue);
    sfSprite_setScale(boss[DIGGLE].sp, scale);
    sfSprite_setTextureRect(boss[DIGGLE].sp, (sfIntRect) {0, 0, 55, 52});
}
