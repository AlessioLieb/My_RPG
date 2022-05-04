/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** create spe boss
*/

#include "../includes/motor.h"

static void create_last_boss(boss_t *boss)
{
    sfTexture *text_duke =
    sfTexture_createFromFile("./Sprites/bosses/duke.png", NULL);
    sfTexture *text_satan =
    sfTexture_createFromFile("./Sprites/bosses/satan.png", NULL);
    sfVector2f scale = {3, 3};
    boss[DUKE] = (boss_t){sfSprite_create(), (sfVector2f){-1, -1}, 40, 6,
    false, 77, 307, (boss_spawning_t) {"rooms/husk.room", 3000, 0, true}, 40
    };
    sfSprite_setTexture(boss[DUKE].sp, text_duke, sfTrue);
    sfSprite_setScale(boss[DUKE].sp, scale);
    sfSprite_setTextureRect(boss[DUKE].sp, (sfIntRect) {0, 0, 80, 64});
    boss[SATAN] = (boss_t){sfSprite_create(), (sfVector2f){-1, -1}, 100, 10,
    false, 271, 812, (boss_spawning_t) {"", 666, 0, false}, 100
    };
    sfSprite_setTexture(boss[SATAN].sp, text_satan, sfTrue);
    sfSprite_setScale(boss[SATAN].sp, scale);
    sfSprite_setTextureRect(boss[SATAN].sp, (sfIntRect) {0, 0, 271, 156});
}

static void create_greed_dark_husk(boss_t *boss)
{
    sfVector2f scale = {3, 3};
    sfTexture *t_greed =
    sfTexture_createFromFile("./Sprites/bosses/greed.png", NULL);
    sfTexture *text_dark =
    sfTexture_createFromFile("./Sprites/bosses/dark_one.png", NULL);
    boss[GREED] = (boss_t){sfSprite_create(), (sfVector2f){-1, -1}, 15, 20,
    false, 30, 89, (boss_spawning_t) {"", 10000, 0, false}, 15
    };
    sfSprite_setTexture(boss[GREED].sp, t_greed, sfTrue);
    sfSprite_setScale(boss[GREED].sp, scale);
    sfSprite_setTextureRect(boss[GREED].sp, (sfIntRect) {0, 0, 30, 32});
    boss[DARK_ONE] = (boss_t){sfSprite_create(), (sfVector2f){-1, -1}, 30, 12,
    false, 78, 419, (boss_spawning_t) {"", 10000, 0, false}, 30
    };
    sfSprite_setTexture(boss[DARK_ONE].sp, text_dark, sfTrue);
    sfSprite_setScale(boss[DARK_ONE].sp, scale);
    sfSprite_setTextureRect(boss[DARK_ONE].sp, (sfIntRect) {0, 0, 78, 69});
    create_last_boss(boss);
}

static void create_piloki_chub(boss_t *boss)
{
    sfTexture *p =
    sfTexture_createFromFile("./Sprites/bosses/pit.png", NULL);
    sfTexture *c =
    sfTexture_createFromFile("./Sprites/bosses/chub.png", NULL);
    sfVector2f scale = {3, 3};
    boss[PIT] = (boss_t){sfSprite_create(), (sfVector2f){-1, -1},20, 9,
    false, 70, 150, (boss_spawning_t) {"", 10000, 0, false}, 20
    };
    sfSprite_setTexture(boss[PIT].sp, p, sfTrue);
    sfSprite_setScale(boss[PIT].sp, scale);
    sfSprite_setTextureRect(boss[PIT].sp, (sfIntRect) {0, 0, 65, 70});
    boss[CHUB] = (boss_t){sfSprite_create(), (sfVector2f){-1, -1}, 70, 2,
    false, 65, 389, (boss_spawning_t) {"rooms/chub.room", 10000, 0, true}, 70
    };
    sfSprite_setTexture(boss[CHUB].sp, c, sfTrue);
    sfSprite_setScale(boss[CHUB].sp, scale);
    sfSprite_setTextureRect(boss[CHUB].sp, (sfIntRect) {0, 0, 65, 65});
    create_greed_dark_husk(boss);
}

static void create_gurdy_loki(boss_t *boss)
{
    sfVector2f scale = {3, 3};
    sfTexture *text_g =
    sfTexture_createFromFile("./Sprites/bosses/gurdy.png", NULL);
    sfTexture *l =
    sfTexture_createFromFile("./Sprites/bosses/loki.png", NULL);
    boss[GRUDY] = (boss_t){sfSprite_create(), (sfVector2f){-1, -1},50, 0,
    false, 138, 551, (boss_spawning_t) {"rooms/grudy.room", 15000, 0, true},
    50
    };
    sfSprite_setTexture(boss[GRUDY].sp, text_g, sfTrue);
    sfSprite_setScale(boss[GRUDY].sp, scale);
    sfSprite_setTextureRect(boss[GRUDY].sp, (sfIntRect) {0, 0, 138, 118});
    boss[LOKI] = (boss_t){sfSprite_create(), (sfVector2f){-1, -1}, 30, 6,
    false, 48, 287, (boss_spawning_t) {"rooms/loki.room", 6000, 0, true}, 30
    };
    sfSprite_setTexture(boss[LOKI].sp, l, sfTrue);
    sfSprite_setScale(boss[LOKI].sp, scale);
    sfSprite_setTextureRect(boss[LOKI].sp, (sfIntRect) {0, 0, 44, 46});
}

void create_monstro_diggle(boss_t *boss)
{
    sfTexture *text_m =
    sfTexture_createFromFile("./Sprites/bosses/monstro.png", NULL);
    sfTexture *text_d =
    sfTexture_createFromFile("./Sprites/bosses/diggle.png", NULL);
    sfVector2f scale = {3, 3};
    boss[MONSTRO] = (boss_t){sfSprite_create(), (sfVector2f){-1, -1}, 75, 3,
    false, 80, 253, (boss_spawning_t) {"rooms/monstro.room", 10000, 0, true},
    75
    };
    sfSprite_setTexture(boss[MONSTRO].sp, text_m, sfTrue);
    sfSprite_setScale(boss[MONSTRO].sp, scale);
    sfSprite_setTextureRect(boss[MONSTRO].sp, (sfIntRect) {0, 0, 80, 74});
    boss[DIGGLE] = (boss_t){sfSprite_create(), (sfVector2f){-1, -1}, 50, 7,
    false, 65, 520, (boss_spawning_t){"rooms/diggle.room", 7500, 0, true}, 50};
    sfSprite_setTexture(boss[DIGGLE].sp, text_d, sfTrue);
    sfSprite_setScale(boss[DIGGLE].sp, scale);
    sfSprite_setTextureRect(boss[DIGGLE].sp, (sfIntRect) {0, 0, 58, 52});
    create_piloki_chub(boss);
    create_gurdy_loki(boss);
    create_husk(boss);
}
