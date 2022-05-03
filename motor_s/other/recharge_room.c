/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** recharge the map
*/

#include "../../includes/motor.h"

static char *search_map()
{
    char *name_map = my_int_str(rand() % NB_MAPS + 1);
    char *extension = ".room";
    char *preced = "rooms/";
    char *total_name;
    int i = 0;
    int j = 0;
    int e = 0;
    total_name = malloc(sizeof(char) * (str_len(name_map)
    + str_len(extension) + str_len(preced)) + 1);
    if (total_name == NULL)
        return NULL;
    for (; preced[e] != '\0'; ++e)
        total_name[e] = preced[e];
    for (; name_map[i] != '\0'; ++i)
        total_name[i + e] = name_map[i];
    for (; extension[j] != '\0'; ++j)
        total_name[j + i + e] = extension[j];
    total_name[j + i + e] = '\0';
    return total_name;
}

char get_actual_room_char(reduce *red)
{
    return (red->ro->floor_rooms[red->rm->actual_room[1]]
    [red->rm->actual_room[0]]);
}

static char get_visited_char(reduce *red)
{
    return (red->ro->mini_map[red->rm->actual_room[1]]
    [red->rm->actual_room[0]]);
}

static bool get_empty(char is_visited, char actual_room)
{
    if (actual_room == 'T' || actual_room == 'B' || actual_room == 'S'
    || actual_room == 'M' || is_visited == 'X' || is_visited == 'B')
        return (true);
    return (false);
}

void recharge_room(reduce *red, bool is_empty, bool is_boss)
{
    char *actual_map;
    char *buff;
    char is_visited = get_visited_char(red);
    char actual_room = get_actual_room_char(red);
    is_empty = get_empty(is_visited, actual_room);
    actual_room == 'B' ? is_boss = true : 0;
    if (red->rm->change_room) {
        clear_tears(red);
        actual_map = is_empty || is_boss ? "rooms/empty.room" : search_map();
        buff = create_map_str(actual_map);
        !is_empty && !is_boss ? free(actual_map) : 0;
        place_enemies(buff, red->enem_t);
        place_stone(red->rm, red->py, buff, red->ro);
        is_visited != 'X'  && is_visited != 'T' ? place_bonus(red->rm) : 0;
        (red->ro->floor_rooms[red->rm->actual_room[1]][red->rm->actual_room[0]]
        == 'T' && (is_visited == 't')) ? place_item(red->rm) : 0;
        is_boss  && is_visited == 'b' ? place_boss_level(red->enem_t,
        red->ro->lvl == 4 ? true : false) : 0;
        red->rm->change_room = false;
    }
}
