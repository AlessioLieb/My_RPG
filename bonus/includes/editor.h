/*
** EPITECH PROJECT, 2022
** bonus
** File description:
** editor
*/

#ifndef EDITOR_H_
    #define EDITOR_H_

    #include <sys/types.h>
    #include <sys/stat.h>
    #include <unistd.h>
    #include <ncurses.h>
    #include <stdlib.h>
    #include <fcntl.h>
    #include <signal.h>
    #include <string.h>
    #define WALL '#'
    #define BOX 'X'
    #define OBJ 'O'
    #define MAP_WIDHT 21
    #define MAP_HEIGHT 10
    #define CARACTERS "NFI BL"
    #define EXTENSION ".room"

FILE *get_file_name(void);
void free_array(char **array);
#endif /* !EDITOR_H_ */
