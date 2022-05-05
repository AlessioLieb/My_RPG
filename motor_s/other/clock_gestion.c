/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** clock
*/

#include "../../includes/motor.h"

void stop_all_clocks(reduce *red)
{
    red->enem_t->move_ti.timer_total = 0;
    red->enem_t->move_ti.timer = 0;
    red->rm->timer_tears.timer_total = 0;
    red->rm->timer_tears.timer = 0;
    sfClock_restart(red->enem_t->total_clock);
}
