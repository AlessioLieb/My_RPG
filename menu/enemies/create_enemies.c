/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** create_enemies
*/

#include "../includes/enemies.h"

adv_t *no_mouving_adv_create(void)
{
    sfTexture *one = sfTexture_createFromFile("../Sprites/m_anim/constant.png", NULL);
    sfTexture *two = sfTexture_createFromFile("../Sprites/m_anim/horf.png", NULL);
    sfIntRect place = {0, 0, 30, 30};
    adv_t *no_mouv = malloc(sizeof(adv_t) * 10);
    sfVector2f scale = {3, 3};
    int tmp = 0;
    srand(time(NULL));
    for (int i = 0; i < 10; ++i) {
        tmp = rand() % 2;
        no_mouv[i].sp = sfSprite_create();
        if (tmp == 0)
            sfSprite_setTexture(no_mouv[i].sp, one, sfTrue);
        if (tmp == 1)
            sfSprite_setTexture(no_mouv[i].sp, two, sfTrue);
        sfSprite_setTextureRect(no_mouv[i].sp, place);
        sfSprite_setScale(no_mouv[i].sp, scale);
        no_mouv[i].speed = 0;
        no_mouv[i].pos = (sfVector2f){-1, -1};
        no_mouv[i].is_flying = false;
        no_mouv[i].is_shooting = true;
        no_mouv[i].pv = 10;
    }
    return no_mouv;
}

adv_t *big_adv_create(void)
{
    sfTexture *array_text[] = {sfTexture_createFromFile("../Sprites/m_anim/fatty.png",
    NULL), sfTexture_createFromFile("../Sprites/m_anim/muli.png", NULL),
    sfTexture_createFromFile("../Sprites/m_anim/muliboom.png", NULL),
    sfTexture_createFromFile("../Sprites/m_anim/skinny.png", NULL), NULL};
    sfIntRect place = {0, 0, 60, 60};
    adv_t *adv = malloc(sizeof(adv_t) * 10);
    sfVector2f scale = {3, 3};
    srand(time(NULL));
    for (int i = 0; i < 10; ++i) {
        adv[i].sp = sfSprite_create();
        sfSprite_setTexture(adv[i].sp, array_text[rand() % 4], sfTrue);
        sfSprite_setTextureRect(adv[i].sp, place);
        sfSprite_setScale(adv[i].sp, scale);
        adv[i].speed = 5;
        adv[i].pos = (sfVector2f){-1, -1};
        adv[i].is_flying = false;
        adv[i].is_shooting = false;
        adv[i].pv = 20;
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
    adv_t *adv = malloc(sizeof(adv_t) * 10);
    sfVector2f scale = {3, 3};
    srand(time(NULL));
    for (int i = 0; i < 10; ++i) {
        adv[i].sp = sfSprite_create();
        sfSprite_setTexture(adv[i].sp, array_text[rand() % 4], sfTrue);
        sfSprite_setTextureRect(adv[i].sp, place);
        sfSprite_setScale(adv[i].sp, scale);
        adv[i].speed = 20;
        adv[i].pos = (sfVector2f){-1, -1};
        adv[i].is_flying = true;
        adv[i].is_shooting = false;
        adv[i].pv = 10;
    }
    return adv;
}

adv_t *little_adv_create(void)
{
    sfTexture *array_text[] = {sfTexture_createFromFile
    ("../Sprites/m_anim/bodies.png", NULL), sfTexture_createFromFile
    ("../Sprites/m_anim/dip.png", NULL), sfTexture_createFromFile
    ("../Sprites/m_anim/charger.png", NULL), NULL};
    sfIntRect place = {0, 0, 24, 25};
    adv_t *adv = malloc(sizeof(adv_t) * 10);
    sfVector2f scale = {3, 3};
    srand(time(NULL));
    for (int i = 0; i < 10; ++i) {
        adv[i].sp = sfSprite_create();
        sfSprite_setTexture(adv[i].sp, array_text[rand() % 3], sfTrue);
        sfSprite_setTextureRect(adv[i].sp, place);
        sfSprite_setScale(adv[i].sp, scale);
        adv[i].speed = 10;
        adv[i].pos = (sfVector2f){-1, -1};
        adv[i].is_flying = false;
        adv[i].is_shooting = false;
        adv[i].pv = 7;
    }
    return adv;
}

/* a faire pour les araignées
adv_t *wall_adv_create(void)
{
    sfTexture *array_text[] = {sfTexture_createFromFile
    ("../Sprites/m_anim/bodies.png", NULL), sfTexture_createFromFile
    ("../Sprites/m_anim/dip.png", NULL), sfTexture_createFromFile
    ("../Sprites/m_anim/charger.png", NULL), NULL};
    sfIntRect place = {0, 0, 60, 60};
    adv_t *adv = malloc(sizeof(adv_t) * 10);
    sfVector2f scale = {3, 3};
    srand(time(NULL));
    for (int i = 0; i < 10; ++i) {
        adv[i].sp = sfSprite_create();
        sfSprite_setTexture(adv[i].sp, array_text[rand() % 3], sfTrue);
        sfSprite_setTextureRect(adv[i].sp, place);
        sfSprite_setScale(adv[i].sp, scale);
        adv[i].speed = 3;
        adv[i].pos = (sfVector2f){0, 0};
        adv[i].is_flying = false;
        adv[i].is_shooting = true;
        adv[i].pv = 10;
    }
    return adv;
}
*/

enemies_t *create_enemies(void)
{
    enemies_t *enem_t = malloc(sizeof(enemies_t));
    enem_t->no_mouving_adv = no_mouving_adv_create();
    enem_t->big_adv = big_adv_create();
    enem_t->flying_adv = flying_adv_create();
    enem_t->little_adv = little_adv_create();
    enem_t->wall_adv = NULL;
    return enem_t;
}