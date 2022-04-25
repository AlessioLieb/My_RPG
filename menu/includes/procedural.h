/*
** EPITECH PROJECT, 2022
** procedural.h
** File description:
** procedural
*/

#ifndef procedural
    #define procedural
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <time.h>
    #include <math.h>

typedef struct {
    int *lvl_rooms;
    int *verge;
    char **floor_rooms;
    int lvl;
}rooms;

void gen_main(rooms *room);

int entirely_connected(char **map, int x, int y, int len);
void break_walls(char **map, int x);
void another_boss_reduce(int *max, int i, int x, char **map);
int reduce_replace_boss(char **map, int x, int i);
int deep_reduce_place_boss(int x, char **map, int i);
int reduce_place_r_boss(char **map, int i, int x);
int ver_start(char **map, int x);
int wrong_map(char **map, int x);
void find_verge(char **map, int x, rooms *room);
int my_intarray_len(int *array);
int place_secret_room(char **map, int x, rooms *room);
void place_treasure_shop(char **map, int x, rooms *room);
int place_secret_room(char **map, int x, rooms *room);
char **print_map(char **map, int x, rooms *room, int j);
int connected_room_fr(char **map, int x, int y, int len);
int connected_b(char **map, int x, int y, int len);
void place_boss(char **map, int x);
int replace_boss(char **map, int x);

int reduce_r_gen(int init_x1, int init_y1, char **map);
int reduce_l_gen(int init_x1, int init_y1, char **map);
int reduce_d_gen(int init_x1, int init_y1, char **map);
int reduce_u_gen(int init_x1, int init_y1, char **map);

void procedural_gen(char **map, int x, rooms *room, int lvl);
void create_lvl(rooms *room);
int connected_room(char **map, int maxx, int maxy, int x);
int place_r_boss(char **map, int x);
int len(int px, int py, int cx, int cy);
int count_rooms(char **map, int x);
void create_rooms(rooms *room);
#endif
