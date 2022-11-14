/*
** EPITECH PROJECT, 2022
** handle_n
** File description:
** Stores value of length of format before %, stored in a pointer variable
*/

#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>
#include "my.h"

char* handles_n(va_list *va, char *format)
{
    int* num = va_arg(*va, int *);
    int i = 0;

    while (format[i] != '%') {
        i++;
    }
    *num = i -1;
    return ("nothing");
}
