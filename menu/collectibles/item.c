/*
** EPITECH PROJECT, 2022
** item
** File description:
** item for the tresor room
*/

#include "../includes/motor.h"

void launch_item(player *py, room *rm)
{
    if ((*(rm->item->change))(py)) {
        sfSprite_destroy(rm->item->sp);
        rm->item = NULL;
    }
}

static void choose_effect(collectible *item, int choose)
{
    if (choose == ALL_STATS)
        item->change = &item_speed;
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
        item->change = &item_speed_tears;
}

static char *item_selected(char *path, int nb)
{
    char *new_str = malloc(sizeof(char) * str_len(path) + 15);
    char *int_str = my_int_str(nb);
    char *extension = ".png";
    int i = 0;
    int j = 0;
    int e = 0;
    for (; path[i] != '\0'; ++i)
        new_str[i] = path[i];
    for (; int_str[j] != '\0'; ++j)
        new_str[i + j] = int_str[j];
    for (; extension[e] != '\0'; ++e)
        new_str[i + j + e] = extension[e];
    new_str[i + j + e] = '\0';
    return new_str;
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
}

void place_item(room *rm)
{
    sfTexture *text;
    collectible *item = malloc(sizeof(collectible));
    int choose = 0;
    srand(time(NULL));
    choose = rand() % LEN_FOLDERS;
    text = sfTexture_createFromFile(select_item(choose), NULL);
    item->sp = sfSprite_create();
    sfSprite_setPosition(item->sp, (sfVector2f) {200, 200});
    sfSprite_setScale(item->sp, (sfVector2f) {3, 3});
    sfSprite_setTexture(item->sp, text, sfTrue);
    item->pos_collision = (sfIntRect) {200, 200, 75, 66};
    choose_effect(item, choose);
    rm->item = item;
}
