/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** stone
*/

#include "../includes/motor.h"

int count_stone(char *str)
{
    int count = 0;
    for (int i = 0; str[i] != '\0'; ++i)
        (str[i] == 'B') ? ++count : 0;
    return (count);
}

stone *create_stone(char *str)
{
    stone *array_stone = malloc(sizeof(stone) * count_stone(str));
    sfTexture *text = sfTexture_createFromFile
    ("assets/allroomobjects.png", NULL);
    srand(time(NULL));
    for (int i = 0; i < count_stone(str); ++i) {
        array_stone[i].sp = sfSprite_create();
        sfSprite_setTexture(array_stone[i].sp, text, sfTrue);
        sfSprite_setTextureRect
        (array_stone[i].sp, (sfIntRect)
        {0 + (27 * (rand() % 3)), 432, 27, 30});
        sfSprite_setScale(array_stone[i].sp, (sfVector2f) {3, 3});
    }
    return array_stone;
}

void place_stone(room *rm, player *py, char *str)
{
    int count = 0;
    rm->len_stone = count_stone(str);
    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] == 'B') {
            sfSprite_setPosition(rm->st[count].sp, (sfVector2f)
            {i % 22 * 78 + 140, (i / 22 * 90) + 82});
            ++count;
        }
    }
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
    sfIntRect player_pos = (sfIntRect)
            {player_tmp.y + y, player_tmp.x + x, 28 * 3, 25 * 3};
    sfIntRect overlap = (sfIntRect){1, 1, 1, 1};
    for (int i = 0; i < rm->len_stone; ++i) {
        pos_tmp = sfSprite_getPosition(rm->st[i].sp);
        tmp = (sfIntRect){pos_tmp.y, pos_tmp.x + 32, 27 * 3, 37};
        if (sfIntRect_intersects(&tmp, &player_pos, &overlap))
            return false;
    }
    return true;
}
