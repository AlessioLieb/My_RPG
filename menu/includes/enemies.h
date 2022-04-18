/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** enemies
*/

#ifndef ENEMIES_H_
    #define ENEMIES_H_

    #include "../includes/motor.h"

typedef struct {
    sfSprite *sp;
    sfVector2f pos;
    bool is_shooting;
    bool is_flying;
    int pv;
    int speed;
}adv_t;

typedef struct {
    adv_t *no_mouving_adv;
    adv_t *big_adv;
    adv_t *flying_adv;
    adv_t *little_adv;
    adv_t *wall_adv;
}enemies_t;

enemies_t *create_enemies(void);
void place_enemies(char *str, enemies_t *enem_t);
void draw_enemies(enemies_t *enem_t, sfRenderWindow *wndw);
#endif
