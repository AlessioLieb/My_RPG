/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** anim_boss
*/

#include "../includes/motor.h"

void draw_boss(boss_t *bst, sfRenderWindow *wd)
{
    for (int i = 0; i < LEN_BOSS; ++i)
        if (bst[i].pos.x != -1)
            sfRenderWindow_drawSprite(wd, bst[i].sp, NULL);
}

char *create_map_str(char *to_read)
{
    int file = open(to_read, O_RDONLY);
    char *buff = malloc(sizeof(char) * LEN_MAP + 1);
    if (file == -1) return NULL;
    if (read(file, buff, LEN_MAP) == -1) return NULL;
    close(file);
    buff[LEN_MAP] = '\0';
    return buff;
}

static void anim_boss(boss_t *bst, int i, enemies_t *enemy)
{
    sfIntRect place;
    char *map;
    if (bst[i].pos.x != -1) {
        place = sfSprite_getTextureRect(bst[i].sp);
        if (place.left + bst[i].decal_texture >= bst[i].max_decal)
            place.left = 0;
        else
            place.left += bst[i].decal_texture;
        sfSprite_setTextureRect(bst[i].sp, place);
        sfSprite_setPosition(bst[i].sp, bst[i].pos);
        enemy->boss_life.active = i;
        if (bst[i].bospt.is_spawning && bst[i].bospt.actual == 0) {
            map = create_map_str(bst[i].bospt.file_spawn);
            place_enemies(map, enemy);
            free(map);
        }
        bst[i].bospt.actual = bst[i].bospt.actual >=
        bst[i].bospt.delay ? 0 : bst[i].bospt.actual + 20;
    }
}

void anim_boss_loop(enemies_t *enemy)
{
    for (int i = 0; i < LEN_BOSS; ++i)
        anim_boss(enemy->boss_adv, i, enemy);
}