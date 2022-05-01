/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** create_enemies
*/

#include "../includes/motor.h"

adv_t *no_moving_adv_create(void)
{
    sfTexture *one =
    sfTexture_createFromFile("../Sprites/m_anim/constant.png", NULL);
    sfTexture *two =
    sfTexture_createFromFile("../Sprites/m_anim/horf.png", NULL);
    sfIntRect place = {0, 0, 31, 30};
    adv_t *no_mov = malloc(sizeof(adv_t) * NB_NO_MOUVING);
    sfVector2f scale = {3, 3};
    int tmp = 0;
    srand(time(NULL));
    for (int i = 0; i < NB_NO_MOUVING; ++i) {
        tmp = rand() % 2;
        no_mov[i].sp = sfSprite_create();
        if (tmp == 0)
            sfSprite_setTexture(no_mov[i].sp, one, sfTrue);
        if (tmp == 1)
            sfSprite_setTexture(no_mov[i].sp, two, sfTrue);
        reduce_init_nomov(i, no_mov, scale, place);
    }
    return no_mov;
}

adv_t *big_adv_create(void)
{
    sfTexture *array_text[] =
    {sfTexture_createFromFile("../Sprites/m_anim/fatty.png",
    NULL), sfTexture_createFromFile("../Sprites/m_anim/muli.png", NULL),
    sfTexture_createFromFile("../Sprites/m_anim/muliboom.png", NULL),
    sfTexture_createFromFile("../Sprites/m_anim/squirt.png", NULL),
    sfTexture_createFromFile("../Sprites/m_anim/skinny.png", NULL), NULL};
    sfIntRect place = {0, 0, 60, 70};
    adv_t *adv = malloc(sizeof(adv_t) * NB_BIG);
    srand(time(NULL));
    for (int i = 0; i < NB_BIG; ++i) {
        adv[i].sp = sfSprite_create();
        sfSprite_setTexture(adv[i].sp, array_text[rand() % 5], sfTrue);
        sfSprite_setTextureRect(adv[i].sp, place);
        sfSprite_setScale(adv[i].sp, (sfVector2f) {3, 3});
        reduce_init_big(i, adv);
    }
    return adv;
}

adv_t *flying_adv_create(void)
{
    sfTexture *array_text[] = {sfTexture_createFromFile
    ("../Sprites/m_anim/boom_fly.png", NULL), sfTexture_createFromFile
    ("../Sprites/m_anim/fly.png", NULL), sfTexture_createFromFile
    ("../Sprites/m_anim/haunted.png", NULL), sfTexture_createFromFile
    ("../Sprites/m_anim/shooter.png", NULL), NULL};
    sfIntRect place = {0, 0, 33, 29};
    adv_t *adv = malloc(sizeof(adv_t) * NB_FLY);
    sfVector2f scale = {3, 3};
    srand(time(NULL));
    for (int i = 0; i < NB_FLY; ++i) {
        adv[i].sp = sfSprite_create();
        sfSprite_setTexture(adv[i].sp, array_text[rand() % 4], sfTrue);
        sfSprite_setTextureRect(adv[i].sp, place);
        sfSprite_setScale(adv[i].sp, scale);
        reduce_init_fly(i, adv);
    }
    return adv;
}

adv_t *little_adv_create(void)
{
    sfTexture *array_text[] = {sfTexture_createFromFile
    ("../Sprites/m_anim/bodies.png", NULL), sfTexture_createFromFile
    ("../Sprites/m_anim/dip.png", NULL), sfTexture_createFromFile
    ("../Sprites/m_anim/charger.png", NULL), NULL};
    sfIntRect place = {0, 0, 28, 25};
    adv_t *adv = malloc(sizeof(adv_t) * NB_LITTLE);
    sfVector2f scale = {3, 3};
    srand(time(NULL));
    for (int i = 0; i < NB_LITTLE; ++i) {
        adv[i].sp = sfSprite_create();
        sfSprite_setTexture(adv[i].sp, array_text[rand() % 3], sfTrue);
        sfSprite_setTextureRect(adv[i].sp, place);
        sfSprite_setScale(adv[i].sp, scale);
        adv[i].speed = 9;
        adv[i].pos = (sfVector2f){-1, -1};
        adv[i].is_flying = false;
        adv[i].is_shooting = false;
        adv[i].pv = 3;
    }
    return adv;
}

enemies_t *create_enemies(void)
{
    enemies_t *enem_t = malloc(sizeof(enemies_t));
    enem_t->no_moving_adv = no_moving_adv_create();
    enem_t->big_adv = big_adv_create();
    enem_t->flying_adv = flying_adv_create();
    enem_t->little_adv = little_adv_create();
    enem_t->ti.timer_total = 0;
    enem_t->ti.timer = 0;
    enem_t->move_ti.timer_total = 0;
    enem_t->move_ti.timer = 0;
    enem_t->total_clock = sfClock_create();
    enem_t->boss_adv = create_boss();
    enem_t->boss_life = create_boss_bar();
    return enem_t;
}
