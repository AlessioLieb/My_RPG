/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** int to str
*/

#include "../includes/motor.h"

int put_nbr(unsigned long long nb, char *str, int i)
{
    int rest;
    if (nb >= 0) {
        if (nb >= 10) {
            rest = nb % 10;
            nb = (nb - rest) / 10;
            ++i;
            put_nbr(nb, str, i);
            str[i] = (rest + 48);
        }
        else {
            ++i;
            str[i] = (nb + 48);
        }
    }
}

int nb_size(unsigned long long nb)
{
    int i = 0;
    while (nb > 0) {
        nb = nb / 10;
        ++i;
    }
    return (i);
}

void my_evil_str(char *str)
{
    int i = 0;
    int j = 0;
    char temp;
    while (str[i] != '\0')
        ++i;
    --i;
    while (i > j){
        temp = str[j];
        str[j] = str [i];
        str[i] = temp;
        --i;
        ++j;
    }
}

char *my_int_str(unsigned long long nb)
{
    char *str = malloc(sizeof(char) * nb_size(nb) + 2);
    int i = 0;
    put_nbr(nb, str, i);
    str += 1;
    str[nb_size(nb)] = '\0';
    my_evil_str(str);
    return (str);
}

int str_len(char const *str)
{
    int i = 0;
    for(; str[i] != '\0'; ++i);
    return i;
}
