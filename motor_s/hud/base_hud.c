/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** hud
*/

#include "../../includes/motor.h"

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

void nb_time_hud(long time, sfRenderWindow *wd, window *wndw, options *sprt)
{
    sfText *hud = sfText_create();
    sfFont *font = sfFont_createFromFile("ressources/upheavtt.ttf");
    int t = time / 60;
    int t2 = time % 60;
    t2 = (t2 == 0) ? 0 : t2;
    char *nb = str_concat("Time = ", my_int_str(t));
    nb = str_concat(nb, " : ");
    nb = str_concat(nb, my_int_str(t2));
    if (sprt->win_cond == true && wndw->last_time[0] == 0) {
        wndw->last_time[0] = t;
        wndw->last_time[1] = t2;
    }
    sfText_setFont(hud, font);
    sfText_setString(hud, nb);
    sfText_setPosition(hud, (sfVector2f){(WIDTH / 2.2), 25});
    sfText_setScale(hud, (sfVector2f){1, 1});
    sfRenderWindow_drawText(wd, hud, NULL);
    sfText_destroy(hud);
    sfFont_destroy(font);
    free(nb);
}

void nb_piece_hud(int piece, sfRenderWindow *wd)
{
    sfText *hud = sfText_create();
    sfFont *font = sfFont_createFromFile("ressources/upheavtt.ttf");
    sfSprite *pi = sfSprite_create();
    sfTexture *p = sfTexture_createFromFile("./Sprites/allpickups.png", NULL);
    sfSprite_setTexture(pi, p, sfTrue);
    sfSprite_setTextureRect(pi, (sfIntRect){0, 129, 9, 11});
    sfSprite_setScale(pi, (sfVector2f){3, 3});
    sfSprite_setPosition(pi, (sfVector2f){80, 250});
    char *nb = str_concat(" ", my_int_str(piece));
    sfText_setFont(hud, font);
    sfText_setString(hud, nb);
    sfText_setPosition(hud, (sfVector2f){115, 250});
    sfText_setScale(hud, (sfVector2f){0.75, 0.75});
    sfRenderWindow_drawText(wd, hud, NULL);
    sfRenderWindow_drawSprite(wd, pi, NULL);
    sfText_destroy(hud);
    sfFont_destroy(font);
    sfSprite_destroy(pi);
    sfTexture_destroy(p);
    free(nb);
}

void nb_bomb_hud(int bomb, sfRenderWindow *wd)
{
    sfText *hud = sfText_create();
    sfFont *font = sfFont_createFromFile("ressources/upheavtt.ttf");
    sfSprite *bo = sfSprite_create();
    sfTexture *b = sfTexture_createFromFile("./Sprites/allpickups.png", NULL);
    sfSprite_setTexture(bo, b, sfTrue);
    sfSprite_setTextureRect(bo, (sfIntRect){9, 129, 13, 13});
    sfSprite_setScale(bo, (sfVector2f){3, 3});
    sfSprite_setPosition(bo, (sfVector2f){74, 295});
    char *nb = str_concat(" ", my_int_str(bomb));
    sfText_setFont(hud, font);
    sfText_setString(hud, nb);
    sfText_setPosition(hud, (sfVector2f){115, 300});
    sfText_setScale(hud, (sfVector2f){0.75, 0.75});
    sfRenderWindow_drawText(wd, hud, NULL);
    sfRenderWindow_drawSprite(wd, bo, NULL);
    sfText_destroy(hud);
    sfFont_destroy(font);
    sfSprite_destroy(bo);
    sfTexture_destroy(b);
    free(nb);
}

void nb_key_hud(int key, sfRenderWindow *wd)
{
    sfText *hud = sfText_create();
    sfFont *font = sfFont_createFromFile("ressources/upheavtt.ttf");
    sfSprite *ke = sfSprite_create();
    sfTexture *k = sfTexture_createFromFile("./Sprites/allpickups.png", NULL);
    sfSprite_setTexture(ke, k, sfTrue);
    sfSprite_setTextureRect(ke, (sfIntRect){0, 141, 9, 11});
    sfSprite_setScale(ke, (sfVector2f){3, 3});
    sfSprite_setPosition(ke, (sfVector2f){80, 350});
    char *nb = str_concat(" ", my_int_str(key));
    sfText_setFont(hud, font);
    sfText_setString(hud, nb);
    sfText_setPosition(hud, (sfVector2f){115, 350});
    sfText_setScale(hud, (sfVector2f){0.75, 0.75});
    sfRenderWindow_drawText(wd, hud, NULL);
    sfRenderWindow_drawSprite(wd, ke, NULL);
    sfText_destroy(hud);
    sfFont_destroy(font);
    sfSprite_destroy(ke);
    sfTexture_destroy(k);
    free(nb);
}
