/*
** EPITECH PROJECT, 2022
** handle_d
** File description:
** Handles if flag is an int
*/
#include <stdarg.h>
#include <stddef.h>
#include "my.h"

char* handles_d(va_list *va, char *format)
{
    (void) format;
    int decimal = (va_arg(*va, int));
    char* arr = my_int_to_str(decimal);
    return (arr);
}
