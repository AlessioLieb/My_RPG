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

int choose_texture_player(reduce *red, options *sprt)
{
    if (red->py->change_texture)
        return 1;
    (sprt->choose == 0) ? sfSprite_setTexture(red->py->sp,
    sfTexture_createFromFile("assets/robin.png", NULL), sfFalse) : 0;
    (sprt->choose == 1) ? sfSprite_setTexture(red->py->sp,
    sfTexture_createFromFile("assets/theotime.png", NULL), sfFalse) : 0;
    (sprt->choose == 2) ? sfSprite_setTexture(red->py->sp,
    sfTexture_createFromFile("assets/alessio.png", NULL), sfFalse) : 0;
    (sprt->choose == 3) ? sfSprite_setTexture(red->py->sp,
    sfTexture_createFromFile("assets/oscar.png", NULL), sfFalse) : 0;
    red->py->change_texture = sprt->choose + 1;
    stats_player(red);
    return 0;
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
    wndw->window);
    is_touched_button(wndw, sprt);
    if (red->py->new_item) {
        update_my_stuff(sprt,red->rm->old_i.old, red->rm->old_i.cp);
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

int main_func(window *wndw, options *sprt, players *perso, rooms *ro)
{
    player *py = creation_player();
    room *rm = create_room();
    init_rm_sprt(rm, sprt);
    sfEvent event;
    tears *te = create_tears(py);
    enemies_t *enem_t = create_enemies();
    music *mu = create_music();
    sounds *so = create_sounds();
    init_all(wndw, sprt, perso);
    while (sfRenderWindow_isOpen(wndw->window)) {
        sprt->plus_lvl == true ? floor_pass(ro, &(reduce)
        {py, rm, te, enem_t, ro}, sprt, mu) : 0;
        event_window(wndw, sprt, &(reduce) {py, rm, te, enem_t});
        music_launcher(&(reduce) {py, rm, te, enem_t, ro}, mu->id_m,
        sprt->begin, mu);
        (sprt->begin == 1) ? draw_spwelcome(wndw, sprt) : 0;
        (sprt->begin == 2 || sprt->begin == 3)
        ? screen_choose_player(wndw, sprt, perso) : 0;
        (sprt->begin == 9) ? dopt_sprt(wndw, sprt) : 0;
        is_touched_button(wndw, sprt);
        (sprt->begin == 2) ? display_framebuffer(wndw, sprt) : 0;
        enemies_verification(enem_t, rm);
        (sprt->begin == 4) ? draw_spause(wndw, sprt, ro) : 0;
        (sprt->begin == 3) ? doors_colisions(sprt, rm, py) : 0;
        (sprt->begin == 3 || sprt->begin == 6)
        ? my_game(wndw, event, &(reduce) {py, rm, te, enem_t, ro, so},
        sprt) : 0;
        (sprt->begin == 3 && mu->id_m == 0) ? ++mu->id_m : 0;
        (sprt->begin == 3) ? update_mini_map(ro, rm) : 0;
        sprt->begin == 3 ? draw_mini_map(ro, wndw->window, rm) : 0;
        (sprt->begin == 3 && py->lf.red_hearth < 1) ? sprt->begin = 7 : 0;
        (sprt->begin == 6) ? display_framebuffer(wndw, sprt) : 0;
        (sprt->begin == 7) ? draw_loose_scrn(wndw, sprt) : 0;
        (sprt->begin == 8) ? dwin_sprt(wndw, sprt) : 0;
        reduce_clear_display(wndw);
    }
    end_buffer(sprt);
}
