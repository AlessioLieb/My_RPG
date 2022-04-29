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

int my_str_compare(char const *str_one, char const *str_two)
{
    if (str_len(str_one) != str_len(str_two))
        return 0;
    for (int i = 0; str_one[i] != '\0'; ++i)
        if (str_one[i] != str_two[i])
            return 0;
    return 1;
}

static bool already_got(char *tmp, old_item_t old_t)
{
    for (int i = 0; i < old_t.cp; ++i)
        if (my_str_compare(tmp, old_t.old[i]))
            return false;
    return true;
}

void place_item(room *rm)
{
    sfTexture *text;
    char *tmp;
    collectible *item = malloc(sizeof(collectible));
    int choose = 0;
    sfVector2f rect = {1920 / 2 - 50, 1080 / 2 - 100};
    sfVector2f rect1 = {1920 / 2 - 45, 1080 / 2};
    tmp = select_item(choose);
    item->altar_text = sfTexture_createFromFile("../Sprites/altar.png", NULL);
    srand(time(NULL));
    while (!already_got(tmp, rm->old_i)) {
        choose = rand() % LEN_FOLDERS;
        tmp = select_item(choose);
    }
    rm->old_i.old[rm->old_i.cp] = tmp;
    ++rm->old_i.cp;
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
    choose_effect(item, choose);
    rm->item = item;
}
