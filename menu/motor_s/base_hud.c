/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** hud
*/

#include "../includes/motor.h"

char *str_concat(char *str, char *concat)
{
    int i = 0;
    int j = 0;
    char *nw = malloc(sizeof(char) * (str_len(concat) + str_len(str) + 1));
    for (; str[i] != '\0'; ++i)
        nw[i] = str[i];
    for (; concat[j] != '\0'; ++j)
        nw[i + j] = concat[j];
    nw[i + j] = '\0';
    return nw;
}

void nb_time_hud(long time, sfRenderWindow *wd)
{
    sfText *hud = sfText_create();
    sfFont *font = sfFont_createFromFile("ressources/upheavtt.ttf");
    char *nb = str_concat("time = ", my_int_str(time));
    sfText_setFont(hud, font);
    sfText_setString(hud, nb);
    sfText_setPosition(hud, (sfVector2f) {WIDTH / 2 - (str_len(nb) / 2), 25});
    sfRenderWindow_drawText(wd, hud, NULL);
    sfText_destroy(hud);
    sfFont_destroy(font);
    free(nb);
}

void nb_piece_hud(int piece, sfRenderWindow *wd)
{
    sfText *hud = sfText_create();
    sfFont *font = sfFont_createFromFile("ressources/upheavtt.ttf");
    char *nb = str_concat("Pieces = ", my_int_str(piece));
    sfText_setFont(hud, font);
    sfText_setString(hud, nb);
    sfText_setPosition(hud, (sfVector2f) {50, 400});
    sfRenderWindow_drawText(wd, hud, NULL);
    sfText_destroy(hud);
    sfFont_destroy(font);
    free(nb);
}
