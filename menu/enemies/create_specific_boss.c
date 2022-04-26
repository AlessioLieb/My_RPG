/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** create spe boss
*/

#include "../includes/motor.h"

static void create_greed(boss_t *boss)
{
    sfTexture *text_greed = sfTexture_createFromFile("../Sprites/bosses/greed.png", NULL);
    sfVector2f scale = {3, 3};
    boss[GREED] = (boss_t){sfSprite_create(), (sfVector2f){-1, -1}, 15, 15,
    false,30, 89, (boss_spawning_t) {"", 10000, 0, false}};
    sfSprite_setTexture(boss[GREED].sp, text_greed, sfTrue);
    sfSprite_setScale(boss[GREED].sp, scale);
    sfSprite_setTextureRect(boss[GREED].sp, (sfIntRect) {0, 0, 30, 32});
}

static void create_pit_loki_chub(boss_t *boss)
{
    sfTexture *text_pit = sfTexture_createFromFile("../Sprites/bosses/pit.png", NULL);
    sfTexture *text_loki = sfTexture_createFromFile("../Sprites/bosses/loki.png", NULL);
    sfTexture *text_chub = sfTexture_createFromFile("../Sprites/bosses/chub.png", NULL);
    sfVector2f scale = {3, 3};
    boss[PIT] = (boss_t){sfSprite_create(), (sfVector2f){-1, -1},20, 9,
    false,68, 194, (boss_spawning_t) {"", 10000, 0, false}};
    sfSprite_setTexture(boss[PIT].sp, text_pit, sfTrue);
    sfSprite_setScale(boss[PIT].sp, scale);
    sfSprite_setTextureRect(boss[PIT].sp, (sfIntRect) {0, 0, 65, 64});
    boss[LOKI] = (boss_t){sfSprite_create(), (sfVector2f){-1, -1},30, 6,
    false,48, 287, (boss_spawning_t) {"rooms/loki.room", 6000, 0, true}};
    sfSprite_setTexture(boss[LOKI].sp, text_loki, sfTrue);
    sfSprite_setScale(boss[LOKI].sp, scale);
    sfSprite_setTextureRect(boss[LOKI].sp, (sfIntRect) {0, 0, 44, 46});
    boss[CHUB] = (boss_t){sfSprite_create(), (sfVector2f){-1, -1},70, 2,
    false,65, 389, (boss_spawning_t) {"rooms/chub.room", 10000, 0, true}};
    sfSprite_setTexture(boss[CHUB].sp, text_chub, sfTrue);
    sfSprite_setScale(boss[CHUB].sp, scale);
    sfSprite_setTextureRect(boss[CHUB].sp, (sfIntRect) {0, 0, 65, 65});
    create_greed(boss);
}

void create_monstro_diggle(boss_t *boss)
{
    sfTexture *text_monstro = sfTexture_createFromFile("../Sprites/bosses/monstro.png", NULL);
    sfTexture *text_diggle = sfTexture_createFromFile("../Sprites/bosses/diggle.png", NULL);
    sfTexture *text_grudy = sfTexture_createFromFile("../Sprites/bosses/gurdy.png", NULL);
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
    boss[GRUDY] = (boss_t){sfSprite_create(), (sfVector2f){-1, -1},200, 0,
    false,138, 551, (boss_spawning_t) {"rooms/grudy.room", 15000, 0, true}};
    sfSprite_setTexture(boss[GRUDY].sp, text_grudy, sfTrue);
    sfSprite_setScale(boss[GRUDY].sp, scale);
    sfSprite_setTextureRect(boss[GRUDY].sp, (sfIntRect) {0, 0, 135, 118});
    create_pit_loki_chub(boss);
}
