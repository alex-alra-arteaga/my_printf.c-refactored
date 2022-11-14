/*
** EPITECH PROJECT, 2022
** handle_precision.c
** File description:
** handle the precision
*/

#include <stdarg.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>
#include "my.h"

int get_nb_precision(char *format, int i)
{
    int nb = 0;
    bool stop = false;
    while (stop == false && format[i] != '\0') {
        if (format[i] == '.') {
            stop = true;
        }
        i++;
    }
    nb = format[i] - '0';
    while (is_num(format[i + 1])) {
        nb = (nb * 10);
        nb += format[i + 1] - '0';
        i++;
    }
    return (nb);
}
