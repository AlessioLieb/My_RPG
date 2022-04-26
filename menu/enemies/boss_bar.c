/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** gestion of the boss life bar
*/

#include "../includes/motor.h"

void draw_rectangle_framebuffer(sfVector2f pos, sfVector2f size, sfUint8 *framebuffer, sfColor color)
{
    for (int y = pos.y; y < pos.y + size.y; ++y)
        for (int x = pos.x; x < pos.x + size.x; ++x)
            *(sfColor * )(4 * (y * WIDTH + x) + framebuffer) = color;
}

boss_life_t create_boss_bar(void)
{
    boss_life_t boss_life;
    boss_life.framebuffer = malloc(sizeof(sfUint8) * HEIGHT * WIDTH * 4 * 8);
    boss_life.end_start = sfSprite_create();
    boss_life.life_bar = sfSprite_create();
    boss_life.text_framebuffer = sfTexture_create(WIDTH, HEIGHT);
    sfSprite_setTexture(boss_life.life_bar,
    boss_life.text_framebuffer, sfTrue);
    boss_life.active = -1;
    return boss_life;
}

void display_boss_life(enemies_t *enemy, int i, sfRenderWindow *wd)
{
    draw_rectangle_framebuffer((sfVector2f){0, 0}, (sfVector2f){WIDTH, HEIGHT},
    enemy->boss_life.framebuffer, sfTransparent);
    draw_rectangle_framebuffer((sfVector2f){500, 100}, (sfVector2f){enemy->boss_adv[i].pv * 3, 50},
    enemy->boss_life.framebuffer, sfRed);
    sfTexture_updateFromPixels(enemy->boss_life.text_framebuffer,
    enemy->boss_life.framebuffer, WIDTH, HEIGHT, 0, 0);
    sfRenderWindow_drawSprite(wd, enemy->boss_life.life_bar, NULL);
}