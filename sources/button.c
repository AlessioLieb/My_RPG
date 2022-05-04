/*
** EPITECH PROJECT, 2022
** myworld
** File description:
** button gestion
*/

#include "../includes/menu.h"

void part_linked_button(options *opt, window *wndw)
{
    factory_button(opt, &mines_choose, (sfIntRect){704, 0, 54, 40},
    (sfVector2f){720, 600});
    opt->ar_btn[TURN_LEFT_WHEEL_PERSO].params = 1;
    opt->ar_btn[TURN_LEFT_WHEEL_PERSO].screen = 2;
    factory_button(opt, &resume_button, (sfIntRect){910, 0, 518, 46},
    (sfVector2f){890, 765});
    opt->ar_btn[RESUME_GAME_PAUSE].params = 1;
    opt->ar_btn[RESUME_GAME_PAUSE].screen = 4;
    factory_button(opt, &home_button, (sfIntRect){1432, 0, 377, 45},
    (sfVector2f){965, 865});
    opt->ar_btn[QUIT_PAUSE].params = 1;
    opt->ar_btn[QUIT_PAUSE].screen = 4;
    factory_button(opt, &print_win, (sfIntRect){1816, 0, 176, 45},
    (sfVector2f){872, 820});
    opt->ar_btn[NEXT].params = 0;
    opt->ar_btn[NEXT].screen = 3;
    factory_button(opt, &print_win, (sfIntRect){1998, 0, 297, 45},
    (sfVector2f){970, 665});
    opt->ar_btn[OPTIONS].params = 1;
    opt->ar_btn[OPTIONS].screen = 4;
    factory_button(opt, &quitgame, (sfIntRect){2300, 0, 166, 45},
    (sfVector2f){1030, 565});
    opt->ar_btn[QUIT_GAME].params = 1;
    opt->ar_btn[QUIT_GAME].screen = 4;
}

void linked_button(options *opt, window *wndw)
{
    opt->t = sfTexture_createFromFile("ressources/button_sprt.png", NULL);
    opt->ar_btn = malloc(sizeof(button) * 10);
    opt->len_button = 0;
    factory_button(opt, &continue_button, (sfIntRect){0, 0, 362, 100},
    (sfVector2f){760, 870});
    opt->ar_btn[CONTINUE_FIRST].params = 1;
    opt->ar_btn[CONTINUE_FIRST].screen = 1;
    factory_button(opt, &home_button, (sfIntRect){760, 0, 150, 150},
    (sfVector2f){350, 220});
    opt->ar_btn[HOME_SCREEN_TWO].params = 1;
    opt->ar_btn[HOME_SCREEN_TWO].screen = 2;
    factory_button(opt, &play_button, (sfIntRect){369, 0, 277, 90},
    (sfVector2f){820, 690});
    opt->ar_btn[PLAY_SCREEN_TWO].params = 1;
    opt->ar_btn[PLAY_SCREEN_TWO].screen = 2;
    factory_button(opt, &plus_choose, (sfIntRect){649, 0, 54, 40},
    (sfVector2f){1150, 600});
    opt->ar_btn[TURN_RIGHT_WHEEL_PERSO].params = 1;
    opt->ar_btn[TURN_RIGHT_WHEEL_PERSO].screen = 2;
    part_linked_button(opt, wndw);
}
