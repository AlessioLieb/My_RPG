/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** anim_boss
*/

#include "../includes/motor.h"

void draw_boss(boss_t *bst, sfRenderWindow *wd)
{
    for (int i = 0; i < 2; ++i)
        if (bst[i].pos.x != -1)
            sfRenderWindow_drawSprite(wd, bst[i].sp, NULL);
}

static void anim_boss(boss_t *bst, int i)
{
    sfIntRect place;
    if (bst[i].pos.x != -1) {
        place = sfSprite_getTextureRect(bst[i].sp);
        if (place.left + bst[i].decal_texture >= bst[i].max_decal)
            place.left = 0;
        else
            place.left += bst[i].decal_texture;
        sfSprite_setTextureRect(bst[i].sp, place);
        sfSprite_setPosition(bst[i].sp, bst[i].pos);
    }
}

void anim_boss_loop(enemies_t *enemy)
{
    for (int i = 0; i < 2; ++i)
        anim_boss(enemy->boss_adv, i);
}