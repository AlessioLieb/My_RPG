/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** stone
*/

#include "../../includes/motor.h"

int count_stone(char *str)
{
    int count = 0;
    for (int i = 0; str[i] != '\0'; ++i)
        (str[i] == 'B') ? ++count : 0;
    return (count);
}

stone *create_stone(char *str, rooms *ro)
{
    int rd = 0;
    sfIntRect rect;
    stone *array_stone = malloc(sizeof(stone) * count_stone(str));
    sfTexture *text = sfTexture_createFromFile
    ("assets/allroomobjects.png", NULL);
    srand(time(NULL));
    for (int i = 0; i < count_stone(str); ++i) {
        rd = rand() % 3;
        if (ro->lvl == 0 || ro->lvl == 1)
            rect = (sfIntRect) {0 + (27 * rd), 432, 27, 30};
        if (ro->lvl == 2 || ro->lvl == 3)
            rect = (sfIntRect) {0 + (27 * rd), 462, 27, 30};
        if (ro->lvl == 4)
            rect = (sfIntRect) {0 + (27 * rd), 493, 27, 30};
        array_stone[i].sp = sfSprite_create();
        sfSprite_setTexture(array_stone[i].sp, text, sfTrue);
        sfSprite_setTextureRect
        (array_stone[i].sp, rect);
        sfSprite_setScale(array_stone[i].sp, (sfVector2f) {3, 3});
        array_stone[i].nb_stone = rd;
    }
    return array_stone;
}

void place_stone(room *rm, player *py, char *str, rooms *ro)
{
    int count = 0;
    rm->st = create_stone(str, ro);
    sfImage *f_stone = sfImage_createFromFile("assets/collisions/stone1.png");
    sfImage *s_stone = sfImage_createFromFile("assets/collisions/stone2.png");
    sfImage *t_stone = sfImage_createFromFile("assets/collisions/stone3.png");
    rm->room_col = sfImage_create(WIDTH, HEIGHT);
    rm->len_stone = count_stone(str);
    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] == 'B') {
            sfSprite_setPosition(rm->st[count].sp, (sfVector2f)
            {i % 22 * 78 + 140, (i / 22 * 90) + 82});
            if (rm->st[count].nb_stone == 0)
                sfImage_copyImage(rm->room_col,
                f_stone, i % 22 * 78 + 140 + 10,(i / 22 * 90) + 82,
                (sfIntRect) {0, 0, 0, 0}, sfTrue);
            if (rm->st[count].nb_stone == 1)
                sfImage_copyImage(rm->room_col,
                s_stone, i % 22 * 78 + 140 + 10, (i / 22 * 90) + 82,
                (sfIntRect) {0, 0, 0, 0}, sfTrue);
            if (rm->st[count].nb_stone == 2)
                sfImage_copyImage(rm->room_col, t_stone, i % 22 * 78 + 140 + 10
                , (i / 22 * 90) + 62, (sfIntRect) {0, 0, 0, 0}, sfTrue);
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
    sfVector2f player_tmp = sfSprite_getPosition(py->sp);
    sfVector2f end = player_tmp;
    bool res = true;
    player_tmp.x += x;
    player_tmp.y += y;
    end.x -= x;
    end.y -= y;
    for (int i = 0; i < 83; ++i)
        for (int j = 0; j < 70; ++j)
            res = (sfImage_getPixel(py->collision_box, i, j).r
            == sfImage_getPixel
            (rm->room_col, player_tmp.x + i, player_tmp.y + j).r
            && sfImage_getPixel(py->collision_box, i, j).r != 0) ? false : res;
    if (!res) {
        py->actual_speed = (sfVector2f) {0, 0};
        if (y >= 0)
            end.y += 5;
        if (x >= 0)
            end.x += 5;
        sfSprite_setPosition(py->sp, end);
    }
    return res;
}
