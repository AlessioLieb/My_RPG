/*
** EPITECH PROJECT, 2022
** item
** File description:
** item for the tresor room
*/

#include "../includes/motor.h"

static void choose_effect(collectible *item, int choose)
{
    if (choose == ALL_STATS)
        item->change = &all_stats_up;
    if (choose == BOMBS)
        item->change = &bombs_up;
    if (choose == DMG)
        item->change = &item_damage;
    if (choose == FLY_I)
        item->change = &fly_player;
    if (choose == HEALTH)
        item->change = &item_life_augmentation;
    if (choose == KEYS)
        item->change = &keys_up;
    if (choose == MONEY)
        item->change = &money_up;
    if (choose == SPEED)
        item->change = &item_speed;
    if (choose == TEARS)
        item->change = &item_freq;
    if (choose == LUCK)
        item->change = &luck_up;
}

static char *select_item(int choose)
{
    if (choose == ALL_STATS)
        return item_selected("../Sprites/Items/all_stats_up/",
        rand() % NB_ALL_STATS);
    if (choose == BOMBS)
        return item_selected("../Sprites/Items/bombs_up/", rand() % NB_BOMBS);
    if (choose == DMG)
        return item_selected("../Sprites/Items/dmg_up/", rand() % NB_DMG);
    if (choose == FLY_I)
        return item_selected("../Sprites/Items/fly/", rand() % NB_FLY_I);
    if (choose == HEALTH)
        return item_selected("../Sprites/Items/health_up/", rand() % NB_HEALTH);
    if (choose == KEYS)
        return item_selected("../Sprites/Items/keys_up/", rand() % NB_KEYS);
    if (choose == MONEY)
        return item_selected("../Sprites/Items/money_up/", rand() % NB_MONEY);
    if (choose == SPEED)
        return item_selected("../Sprites/Items/speed_up/", rand() % NB_SPEED);
    if (choose == TEARS)
        return item_selected("../Sprites/Items/tears_up/", rand() % NB_TEARS);
    if (choose == LUCK)
        return item_selected("../Sprites/Items/luck_up/", rand() % NB_LUCK);
}

static void reduce_place_item(room *rm, char *tmp, collectible *item, sfTexture *text)
{
    sfVector2f rect = {1920 / 2 - 50, 1080 / 2 - 100};
    sfVector2f rect1 = {1920 / 2 - 45, 1080 / 2};
    text = sfTexture_createFromFile(tmp, NULL);
    item->sp = sfSprite_create();
    item->altar = sfSprite_create();
    sfSprite_setTexture(item->altar, item->altar_text, sfTrue);
    sfSprite_setPosition(item->sp, rect);
    sfSprite_setScale(item->altar, (sfVector2f) {3 * (32 / 27), 3 * (32 / 27)});
    sfSprite_setPosition(item->altar, rect1);
    sfSprite_setScale(item->sp, (sfVector2f) {3, 3});
    sfSprite_setTexture(item->sp, text, sfTrue);
    item->pos_collision = (sfIntRect) {1920 / 2 - 50, 1080 / 2 - 100, 75, 166};
}

void place_item(room *rm)
{
    sfTexture *text;
    char *tmp;
    collectible *item = malloc(sizeof(collectible));
    int choose = rand() % LEN_FOLDERS;
    tmp = select_item(choose);
    item->altar_text = sfTexture_createFromFile("../Sprites/altar.png", NULL);
    srand(time(NULL));
    while (!already_got(tmp, rm->old_i)) {
        choose = rand() % LEN_FOLDERS;
        tmp = select_item(choose);
    }
    rm->old_i.old[rm->old_i.cp] = tmp;
    ++rm->old_i.cp;
    reduce_place_item(rm, tmp, item, text);
    choose_effect(item, choose);
    rm->item = item;
}
