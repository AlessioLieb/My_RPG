/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** run
*/

#ifndef MAP_H_
    #define MAP_H_

    #include <SFML/Graphics.h>
    #include <stdlib.h>
    #include <SFML/System/Export.h>
    #include <stdio.h>
    #include <time.h>
    #include <unistd.h>
    #include <math.h>
    #include <SFML/Audio/Export.h>
    #include <SFML/Audio/SoundStatus.h>
    #include <SFML/Audio/Types.h>
    #include <SFML/System/InputStream.h>
    #include <SFML/System/Time.h>
    #include <SFML/System/Vector3.h>
    #include <stddef.h>
    #include <SFML/Audio.h>
    #include <SFML/System/Export.h>
    #include <SFML/System/Time.h>
    #include <SFML/System/Types.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <stdbool.h>
    #define HEIGHT 1080
    #define WIDTH 1920

typedef struct {
    sfSprite *sp;
    sfTexture *tx;
    int x;
    int y;
    bool as_moved;
    int speed;
    int actual_sp;
}player;

typedef struct {
    sfSprite *sp;
    sfVector2f pos;
}stone;

typedef struct {
    sfSprite *sp;
    int actual_room;
    int len_stone;
    stone *st;
}room;

bool collision_stone(room *rm, player *py, int x, int y);
void draw_stone(room *rm, sfRenderWindow *wd);
void place_stone(room *rm, player *py);
stone *create_stone(void);
int move_sp_top(player *py, int top, room *rm);
#endif
