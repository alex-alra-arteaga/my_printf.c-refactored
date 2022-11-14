/*
** EPITECH PROJECT, 2022
** get_nb_width.c
** File description:
** get_nb
*/

#include <stdarg.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>
#include "my.h"

int get_nb_width(char *format, int i)
{
    int nb = 0;
    bool stop = false;

    while (stop == false && format[i]) {
        if (is_num(format[i])) {
            stop = true;
        }
        i++;
    }
    i--;
    nb = format[i] - '0';
    while (is_num(format[i + 1])) {
        nb = nb * 10;
        nb += format[i + 1] - '0';
        if (format[i - 1] == '-') {
            nb = nb * -1;
        }
        i++;
    }
    return (nb);
}
