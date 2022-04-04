/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** stone
*/

#include "../includes/motor.h"

stone *create_stone(void)
{
    stone *array_stone = malloc(sizeof(stone) * 15);
    sfTexture *text = sfTexture_createFromFile("assets/allroomobjects.png", NULL);
    sfIntRect one = {0, 436, 25, 27};
    srand(time(NULL));
    for (int i = 0; i < 15; ++i) {
        array_stone[i].sp = sfSprite_create();
        sfSprite_setTexture(array_stone[i].sp, text, sfTrue);
        sfSprite_setTextureRect
        (array_stone[i].sp, (sfIntRect)
        {0 + (27 * (rand() % 3)), 432, 27, 30});
        sfSprite_setScale(array_stone[i].sp, (sfVector2f) {3, 3});
    }
    return array_stone;
}

void place_stone(room *rm, player *py)
{
    srand(time(NULL));
    rm->len_stone = 3 + rand() % 12;
    for (int i = 0; i < rm->len_stone; ++i)
        sfSprite_setPosition(rm->st[i].sp, (sfVector2f)
        {250 + (90 * (rand() % 12)), 250 + (110 * (rand() % 6))});
}

void draw_stone(room *rm, sfRenderWindow *wd)
{
    for (int i = 0; i < rm->len_stone; ++i)
        sfRenderWindow_drawSprite(wd, rm->st[i].sp, NULL);
}

bool collision_stone(room *rm, player *py, int x, int y)
{
    sfVector2f pos_tmp;
    sfIntRect tmp;
    sfVector2f player_tmp = sfSprite_getPosition(py->sp);
    sfIntRect player_pos = (sfIntRect) {player_tmp.y + y, player_tmp.x + x, 28 * 3, 35 * 3};
    sfIntRect overlap = (sfIntRect){1, 1, 1, 1};
    for (int i = 0; i < rm->len_stone; ++i) {
        pos_tmp = sfSprite_getPosition(rm->st[i].sp);
        tmp = (sfIntRect){pos_tmp.y, pos_tmp.x + 32, 27 * 3, 37};
        if (sfIntRect_intersects(&tmp, &player_pos, &overlap))
            return false;
    }
    return true;
}