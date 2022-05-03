/*
** EPITECH PROJECT, 2022
** item launching
** File description:
** rpg
*/

#include "../includes/motor.h"

char *item_selected(char *path, int nb)
{
    char *new_str = malloc(sizeof(char) * str_len(path) + 15);
    char *int_str = my_int_str(nb);
    char *extension = ".png";
    int i = 0;
    int j = 0;
    int e = 0;
    for (; path[i] != '\0'; ++i)
        new_str[i] = path[i];
    for (; int_str[j] != '\0'; ++j)
        new_str[i + j] = int_str[j];
    for (; extension[e] != '\0'; ++e)
        new_str[i + j + e] = extension[e];
    new_str[i + j + e] = '\0';
    return new_str;
}

bool already_got(char *tmp, old_item_t old_t)
{
    for (int i = 0; i < old_t.cp; ++i)
        if (my_str_compare(tmp, old_t.old[i]))
            return false;
    return true;
}

void launch_item(player *py, room *rm)
{
    if ((*(rm->item->change))(py)) {
        sfSprite_destroy(rm->item->sp);
        rm->item = NULL;
        py->new_item = true;
    }
}
