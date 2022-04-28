/*
** EPITECH PROJECT, 2021
** menu
** File description:
** init_mini_map.c
*/

#include "../includes/motor.h"

void init_nroom_sprites(rooms *ro)
{
    sfVector2f room_scale = {3.5, 3.5};
    sfIntRect rect1 = {64, 0, 9, 8};
    sfIntRect rect2 = {55, 0, 9, 8};
    ro->n_room_known = sfSprite_create();
    sfSprite_setTexture(ro->n_room_known, ro->text, sfTrue);
    sfSprite_setTextureRect(ro->n_room_known, rect1);
    sfSprite_setScale(ro->n_room_known, room_scale);
    ro->n_room_unknown = sfSprite_create();
    sfSprite_setTexture(ro->n_room_unknown, ro->text, sfTrue);
    sfSprite_setTextureRect(ro->n_room_unknown, rect2);
    sfSprite_setScale(ro->n_room_unknown, room_scale);
}

void init_broom_sprites(rooms *ro)
{
    sfVector2f room_scale = {3.5, 3.5};
    sfIntRect rect1 = {64, 16, 9, 8};
    sfIntRect rect2 = {55, 16, 9, 8};
    ro->b_room_known = sfSprite_create();
    sfSprite_setTexture(ro->b_room_known, ro->text, sfTrue);
    sfSprite_setTextureRect(ro->b_room_known, rect1);
    sfSprite_setScale(ro->b_room_known, room_scale);
    ro->b_room_unknown = sfSprite_create();
    sfSprite_setTexture(ro->b_room_unknown, ro->text, sfTrue);
    sfSprite_setTextureRect(ro->b_room_unknown, rect2);
    sfSprite_setScale(ro->b_room_unknown, room_scale);
}

void init_treasure_sprites(rooms *ro)
{
    sfVector2f room_scale = {3.5, 3.5};
    sfIntRect rect1 = {64, 8, 9, 8};
    sfIntRect rect2 = {55, 8, 9, 8};
    ro->t_room_known = sfSprite_create();
    sfSprite_setTexture(ro->t_room_known, ro->text, sfTrue);
    sfSprite_setTextureRect(ro->t_room_known, rect1);
    sfSprite_setScale(ro->t_room_known, room_scale);
    ro->t_room_unknown = sfSprite_create();
    sfSprite_setTexture(ro->t_room_unknown, ro->text, sfTrue);
    sfSprite_setTextureRect(ro->t_room_unknown, rect2);
    sfSprite_setScale(ro->t_room_unknown, room_scale);
}

void init_shop_sprites(rooms *ro)
{
    sfVector2f room_scale = {3.5, 3.5};
    sfIntRect rect1 = {64, 24, 9, 8};
    sfIntRect rect2 = {55, 24, 9, 8};
    ro->s_room_known = sfSprite_create();
    sfSprite_setTexture(ro->s_room_known, ro->text, sfTrue);
    sfSprite_setTextureRect(ro->s_room_known, rect1);
    sfSprite_setScale(ro->s_room_known, room_scale);
    ro->s_room_unknown = sfSprite_create();
    sfSprite_setTexture(ro->s_room_unknown, ro->text, sfTrue);
    sfSprite_setTextureRect(ro->s_room_unknown, rect2);
    sfSprite_setScale(ro->s_room_unknown, room_scale);
}

void init_minimap_sprites(rooms *ro)
{
    sfIntRect rect = {0, 0, 55, 55};
    sfVector2f scale = {6, 6};
    sfVector2f pos = {1550, 0};
    sfVector2f room_scale = {3.5, 3.5};
    sfIntRect rect1 = {55, 40, 9, 8};

    ro->text = sfTexture_createFromFile("../Sprites/minimap.png", NULL);
    ro->map = sfSprite_create();
    sfSprite_setTexture(ro->map, ro->text, sfTrue);
    sfSprite_setTextureRect(ro->map, rect);
    sfSprite_setScale(ro->map, scale);
    sfSprite_setPosition(ro->map, pos);
    ro->actual_room_sprite = sfSprite_create();
    sfSprite_setTexture(ro->actual_room_sprite, ro->text, sfTrue);
    sfSprite_setTextureRect(ro->actual_room_sprite, rect1);
    sfSprite_setScale(ro->actual_room_sprite, room_scale);
}
