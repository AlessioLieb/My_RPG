/*
** EPITECH PROJECT, 2021
** ouais
** File description:
** main_func.c
*/

#include "../includes/motor.h"

void check_move_all(reduce *red)
{
    red->py->move_timer.timer_total += sfClock_getElapsedTime
    (red->py->time).microseconds - red->py->move_timer.timer;
    while (red->py->move_timer.timer_total > 10000) {
        if (!check_move_right(red->py, red->rm))
            red->py->actual_speed = (sfVector2f) {0, 0};
        sfSprite_move(red->py->sp, red->py->actual_speed);
        move_player_check(red);
        red->py->move_timer.timer_total -= 10000;
    }
    red->py->move_timer.timer =
    sfClock_getElapsedTime(red->py->time).microseconds;
}

int my_game(window *wndw, sfEvent event, reduce *red, options *sprt)
{
    recharge_room(red, false, false);
    player_room(wndw->window, red, sprt);
    check_move_all(red);
    draw_enemies(red->enem_t, wndw->window, red->py, red->rm);
    draw_life(red->py, wndw->window);
    draw_bonus(red->rm, wndw->window, red->py);
    nb_piece_hud(red->py->invent.money, wndw->window);
    nb_bomb_hud(red->py->invent.bomb, wndw->window);
    nb_key_hud(red->py->invent.key, wndw->window);
    disp_stat_hud(red, wndw->window);
    nb_time_hud(sfClock_getElapsedTime(red->py->time).microseconds / 1000000,
    wndw->window);
    return 0;
}

void screen_choose_player(window *wndw, options *sprt, players *perso)
{
    draw_spbarre(wndw, sprt);
    (sprt->choose == 0) ? draw_robhein(wndw, perso) : 0;
    (sprt->choose == 1) ? draw_theotitime(wndw, perso) : 0;
    (sprt->choose == 2) ? draw_aliciau(wndw, perso) : 0;
    (sprt->choose == 3) ? draw_osca(wndw, perso) : 0;
}

void enemies_verification(enemies_t *enem_t, room *rm)
{
    int count = 0;

    for (int i = 0; i != 10; ++i) {
        enem_t->big_adv[i].pos.x != -1 ? ++count : 0;
        enem_t->flying_adv[i].pos.x != -1 ? ++count : 0;
        enem_t->little_adv[i].pos.x != -1 ? ++count : 0;
        enem_t->no_moving_adv[i].pos.x != -1 ? ++count : 0;
    }
    if (count == 0)
        rm->open = true;
    else
        rm->open = false;
}

int main_func(window *wndw, options *sprt, players *perso, rooms *ro)
{
    char *buff = malloc(1000);
    int file = open("rooms/1.room", O_RDONLY);
    int size = read(file, buff, 1000);
    buff[size] = '\0';
    player *py = creation_player();
    room *rm = create_room(buff);
    init_rm_sprt(rm, sprt);
    sfEvent event;
    tears *te = create_tears(py);
    enemies_t *enem_t = create_enemies();
    place_enemies(buff, enem_t);
    place_stone(rm, py, buff);
    init_all(wndw, sprt, perso);
    place_bonus(rm);
    place_boss_level(enem_t, true);
    while (sfRenderWindow_isOpen(wndw->window)) {
        event_window(wndw, sprt, &(reduce) {py, rm, te, enem_t});
        (sprt->begin == 1) ? draw_spwelcome(wndw, sprt) : 0;
        (sprt->begin == 2 || sprt->begin == 3)
        ? screen_choose_player(wndw, sprt, perso) : 0;
        is_touched_button(wndw, sprt);
        (sprt->begin == 2) ? display_framebuffer(wndw, sprt) : 0;
        enemies_verification(enem_t, rm);
        (sprt->begin == 3) ? doors_colisions(sprt, rm, py) : 0;
        (sprt->begin == 3 || sprt->begin == 6)
        ? my_game(wndw, event, &(reduce) {py, rm, te, enem_t, ro}, sprt) : 0;
        (sprt->begin == 6) ? display_framebuffer(wndw, sprt) : 0;
        (sprt->begin == 4) ? draw_spause(wndw, sprt) : 0;
        sfRenderWindow_display(wndw->window);
        sfRenderWindow_clear(wndw->window, sfBlack);
        sprt->plus_lvl == true ? floor_pass(ro, &(reduce)
        {py, rm, te, enem_t, ro}, sprt, wndw) : 0;
    }
    end_buffer(sprt);
}
