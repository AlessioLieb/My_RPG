/*
** EPITECH PROJECT, 2022
** bonus
** File description:
** reduce
*/

#include "../includes/editor.h"

static FILE *get_file_name_red(char *name_file, int cp)
{
    FILE *file = NULL;
    name_file = realloc(name_file, cp + strlen(EXTENSION) + 1);
    for (int i = 0; EXTENSION[i] != '\0'; ++i)
        name_file[cp + i] = EXTENSION[i];
    name_file[cp + strlen(EXTENSION)] = '\0';
    file  = fopen(name_file, "w+");
    free(name_file);
    if (file == NULL) {
        endwin();
        exit(0);
    }
    return file;
}

FILE *get_file_name(void)
{
    char *name_file = malloc(sizeof(char));
    int ch = 0;
    int cp = 0;
    char tmp = 0;
    printw("Write your file name");
    move(1, 0);
    ch = getch();
    while (ch != 10) {
        tmp = ch;
        name_file[cp] = tmp;
        ++cp;
        ch = getch();
        name_file = realloc(name_file, cp + 1);
    }
    return get_file_name_red(name_file, cp);
}

void free_array(char **array)
{
    for (int i = 0; array[i] != NULL; ++i)
        free(array[i]);
    free(array);
}
