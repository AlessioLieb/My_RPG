/*
** EPITECH PROJECT, 2021
** B-MUL-200-MLH-2-1-myrpg-robin.denni
** File description:
** reduce.c
*/

#include "../../includes/motor.h"

bool collision_stone_tears(reduce *red, int x, int y, int nb)
{
    sfVector2f pos_tmp;
    sfIntRect tmp;
    sfVector2f tears_tmp = sfSprite_getPosition(red->te[nb].t_sp);
    sfIntRect tears_pos = (sfIntRect)
    {tears_tmp.y + y, tears_tmp.x + x, 15 * 3, 15 * 3};
    sfIntRect overlap = (sfIntRect){1, 1, 1, 1};
    for (int i = 0; i < red->rm->len_stone; ++i) {
        pos_tmp = sfSprite_getPosition(red->rm->st[i].sp);
        tmp = (sfIntRect){pos_tmp.y, pos_tmp.x + 32, 27 * 3, 37};
        if (sfIntRect_intersects(&tmp, &tears_pos, &overlap))
            return false;
    }
    return true;
}

tears *create_tears(player *py)
{
    tears *te = malloc(sizeof(tears) * 100);
    sfIntRect r = {402, 285, 15, 15};
    te = init_st_array(te, r, py);
}

void reduce_move_player_check(reduce *red)
{
    red->py->anim_timer.timer =
    sfClock_getElapsedTime(red->py->time).microseconds;
    red->py->tears_timer.timer_total += sfClock_getElapsedTime
    (red->py->time).microseconds - red->py->tears_timer.timer;
}

void disp_stat_hud(reduce *red, sfRenderWindow *wd)
{
    disp_speed(red, wd);
    disp_freq_tears(red, wd);
    disp_sp_tears(red, wd);
    disp_damages(red, wd);
    disp_luck(red, wd);
    if (red->py->it_des->active)
        disp_description(red, wd);
    int t = sfClock_getElapsedTime(red->py->it_des->des_clock).microseconds
    / 1000000;
    if (t > 2) {
        red->py->it_des->active = false;
        red->py->it_des->l_h_active = false;
        red->py->it_des->all_st_active = false;
    }
}

stats create_stats(void)
{
    stats st;
    st.damages = 4;
    st.freq_tears = 4;
    st.luck = 1;
    st.shot_speed = 4;
    st.speed = 8;
    return st;
}
