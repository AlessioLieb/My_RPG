/*
** EPITECH PROJECT, 2021
** ouais
** File description:
** main_func.c
*/

#include "../includes/music.h"

void check_move_all(reduce *red)
{
    red->py->move_timer.timer_total += sfClock_getElapsedTime
    (red->py->time).microseconds - red->py->move_timer.timer;
    while (red->py->move_timer.timer_total > 10000) {
        if (!check_move_right(red->py, red->rm))
            red->py->actual_speed = (sfVector2f) {0, 0};
        sfSprite_move(red->py->sp, red->py->actual_speed);
        move_player_check(red, red->py->st.freq_tears / 2);
        red->py->move_timer.timer_total -= 10000;
    }
    red->py->move_timer.timer =
    sfClock_getElapsedTime(red->py->time).microseconds;
}

int my_game(window *wndw, sfEvent event, reduce *red, options *sprt)
{
    red->rm->luck = red->py->st.luck;
    choose_texture_player(red, sprt);
    recharge_room(red, false, false);
    player_room(wndw->window, red, sprt);
    check_move_all(red);
    draw_life(red->py, wndw->window);
    draw_bonus(red->rm, wndw->window, red->py, red->ro);
    nb_piece_hud(red->py->invent.money, wndw->window);
    nb_bomb_hud(red->py->invent.bomb, wndw->window);
    nb_key_hud(red->py->invent.key, wndw->window);
    draw_npc(wndw, sprt, red);
    disp_stat_hud(red, wndw->window);
    nb_time_hud(sfClock_getElapsedTime(red->py->time).microseconds / 1000000,
    wndw->window, wndw, sprt);
    is_touched_button(wndw, sprt);
    if (red->py->new_item) {
        update_my_stuff(sprt, red->rm->old_i.old, red->rm->old_i.cp);
        red->py->new_item = false;
    }
    return 0;
}

void enemies_verification(enemies_t *enem_t, room *rm)
{
    int count = 0;

    for (int i = 0; i != 10; ++i) {
        enem_t->big_adv[i].pos.x != -1 ? ++count : 0;
        enem_t->flying_adv[i].pos.x != -1 ? ++count : 0;
        enem_t->little_adv[i].pos.x != -1 ? ++count : 0;
        enem_t->no_moving_adv[i].pos.x != -1 ? ++count : 0;
        enem_t->boss_adv[i].pos.x != -1 ? ++count : 0;
    }
    if (count == 0)
        rm->open = true;
    else
        rm->open = false;
}

void reduce_main_func(reduce *red, rooms *ro)
{
    red->sprt->plus_lvl == true ? floor_pass(red->ro, red, red->sprt,
    red->mu) : 0;
    event_window(red->wndw, red->sprt, red);
    music_launcher(red, red->mu->id_m, red->sprt->begin, red->mu);
    (red->sprt->begin == 8) ? red->mu->id_m = 10 : 0;
    (red->sprt->begin == 1) ? draw_spwelcome(red->wndw, red->sprt) : 0;
    (red->sprt->begin == 2 || red->sprt->begin == 3)
    ? screen_choose_player(red->wndw, red->sprt, red->perso) : 0;
    (red->sprt->begin == 9) ? dopt_sprt(red->wndw, red->sprt, red,
    red->s_bar) : 0;
    is_touched_button(red->wndw, red->sprt);
    enemies_verification(red->enem_t, red->rm);
    (red->sprt->begin == 4) ? draw_spause(red->wndw, red->sprt, red) : 0;
    (red->sprt->begin == 3) ? doors_colisions(red->sprt, red->rm,
    red->py) : 0;
    (red->sprt->begin == 3 || red->sprt->begin == 6)
    ? my_game(red->wndw, red->event, red, red->sprt) : 0;
    (red->sprt->begin == 3 && red->mu->id_m == 0) ? ++red->mu->id_m : 0;
    (red->sprt->begin == 3) ? update_mini_map(red->ro, red->rm) : 0;

}

int main_func(reduce *red, rooms *ro)
{
    init_rm_sprt(red->rm, red->sprt);
    init_all(red->wndw, red->sprt, red->perso);
    while (sfRenderWindow_isOpen(red->wndw->window)) {
        reduce_main_func(red, ro);
        red->sprt->begin == 3 ? draw_mini_map(red->ro, red->wndw->window,
        red->rm) : 0;
        (red->sprt->begin == 3 && red->py->lf.red_hearth < 1)
        ? red->sprt->begin = 7 : 0;
        (red->sprt->begin == 2 || red->sprt->begin == 6 ||
        red->sprt->begin == 3 && red->sprt->anim == 3) ?
        display_framebuffer(red->wndw, red->sprt) : 0;
        (red->sprt->begin == 7) ? draw_loose_scrn(red->wndw, red->sprt) : 0;
        (red->sprt->begin == 8) ? dwin_sprt(red->wndw, red->sprt) : 0;
        (red->sprt->begin == 8) ? update_my_stuff_end(red->sprt, red->wndw) : 0;
        reduce_clear_display(red->wndw);
    }
    end_buffer(red->sprt);
}
