/*
** EPITECH PROJECT, 2022
** bonus
** File description:
** main
*/

#include "../includes/editor.h"

static void init(void)
{
    initscr();
    keypad(stdscr, TRUE);
    start_color();
    mousemask(BUTTON1_CLICKED , NULL);
}

static char **create_content(void)
{
    char **array_file = malloc(sizeof(char *) * (MAP_HEIGHT + 2));
    int i = 0;
    int j = 0;
    for (; i < MAP_HEIGHT; ++i) {
        array_file[i] = malloc(sizeof(char) * (MAP_WIDHT + 2));
        for (; j < MAP_WIDHT; ++j)
            array_file[i][j] = ' ';
        array_file[i][j] = '\n';
        array_file[i][j + 1] = '\0';
        j = 0;
    }
    for (int j = 0; j < 20; ++j)
        array_file[0][j] = 'X';
    for (int j = 0; j < 20; ++j)
        array_file[i -1][j] = 'X';
    array_file[i] = NULL;
    for (int j = 0; array_file[j] != NULL; ++j)
        array_file[j][0] = 'X';
    for (int j = 0; array_file[j] != NULL; ++j)
        array_file[j][20] = 'X';
    return array_file;
}

static void fill_content(char **content_file)
{
    MEVENT event;
    int ch = 0;
    int cp = 0;
    mvprintw(0, 0, "Actual caracter %c", CARACTERS[cp]);
    ch = getch();
    while (ch != 10) {
        if (ch == KEY_MOUSE && getmouse(&event) == OK && event.x < 20
        && event.y < 9 && event.x > 0 && event.y > 0) {
                mvprintw(event.y, event.x, "%c", CARACTERS[cp]);
                content_file[event.y][event.x] = CARACTERS[cp];
        }
        if (cp > 0 && ch == KEY_LEFT)
            --cp;
        if (cp < 6 && ch == KEY_RIGHT)
            ++cp;
        mvprintw(0, 0, "Actual caracter %c", CARACTERS[cp]);
        ch = getch();
    }
}

static void map_editor(void)
{
    char **content_file = create_content();
    FILE *file = get_file_name();
    clear();
    fill_content(content_file);
    for (int i = 0; content_file[i] != NULL; ++i)
        fwrite(content_file[i], strlen(content_file[i]), 1, file);
    fclose(file);
    free_array(content_file);
    clear();
}

int main(void)
{
    init();
    map_editor();
    endwin();
    return 0;
}
