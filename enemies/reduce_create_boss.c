/*
** EPITECH PROJECT, 2021
** B-MUL-200-MLH-2-1-myrpg-robin.denni
** File description:
** reduce_create_boss.c
*/

#include "../includes/motor.h"

void create_husk(boss_t *boss)
{
    sfTexture *t_husk =
    sfTexture_createFromFile("./Sprites/bosses/husk.png", NULL);
    sfVector2f scale = {3, 3};
    boss[HUSK] = (boss_t){sfSprite_create(), (sfVector2f){-1, -1}, 50, 6,
    false, 77, 307, (boss_spawning_t){"rooms/husk.room", 5000, 0, true}, 50
    };
    sfSprite_setTexture(boss[HUSK].sp, t_husk, sfTrue);
    sfSprite_setScale(boss[HUSK].sp, scale);
    sfSprite_setTextureRect(boss[HUSK].sp, (sfIntRect){0, 0, 77, 64});
}
