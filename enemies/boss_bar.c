/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** gestion of the boss life bar
*/

#include "../includes/motor.h"

void draw_rectangle_framebuffer(sfVector2f pos, sfVector2i size,
sfUint8 *framebuffer, sfColor color)
{
    for (int y = pos.y; y < pos.y + size.y; ++y)
        for (int x = pos.x; x < pos.x + size.x; ++x)
            *(sfColor * )(4 * (y * WIDTH + x) + framebuffer) = color;
}

boss_life_t create_boss_bar(void)
{
    boss_life_t boss_life;
    sfTexture *text =
    sfTexture_createFromFile("./Sprites/boss_bar.png", NULL);
    boss_life.framebuffer = malloc(sizeof(sfUint8) * HEIGHT * WIDTH * 4 * 8);
    if (boss_life.framebuffer == NULL)
        return (boss_life_t){NULL, NULL, NULL, NULL, -2};
    boss_life.end_start = sfSprite_create();
    boss_life.life_bar = sfSprite_create();
    boss_life.text_framebuffer = sfTexture_create(WIDTH, HEIGHT);
    sfSprite_setTexture(boss_life.life_bar,
    boss_life.text_framebuffer, sfTrue);
    sfSprite_setTexture(boss_life.end_start, text, sfTrue);
    sfSprite_setScale(boss_life.end_start, (sfVector2f){4, 4});
    sfSprite_setPosition(boss_life.end_start, (sfVector2f){678, 140});
    boss_life.active = -1;
    return boss_life;
}

void display_boss_life(enemies_t *enemy, int i, sfRenderWindow *wd)
{
    sfVector2i length_bar;
    float cast_pv = enemy->boss_adv[i].pv;
    float cast_total_life = enemy->boss_adv[i].total_life;
    float x = (cast_pv / cast_total_life);
    length_bar.y = 48;
    length_bar.x = x * 444.0;
    sfRenderWindow_drawSprite(wd, enemy->boss_life.end_start, NULL);
    draw_rectangle_framebuffer((sfVector2f){0, 0}, (sfVector2i)
    {WIDTH, HEIGHT}, enemy->boss_life.framebuffer, sfTransparent);
    draw_rectangle_framebuffer((sfVector2f){750, 156}, length_bar,
    enemy->boss_life.framebuffer, sfRed);
    sfTexture_updateFromPixels(enemy->boss_life.text_framebuffer,
    enemy->boss_life.framebuffer, WIDTH, HEIGHT, 0, 0);
    sfRenderWindow_drawSprite(wd, enemy->boss_life.life_bar, NULL);
}
