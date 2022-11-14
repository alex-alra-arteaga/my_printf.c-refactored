/*
** EPITECH PROJECT, 2022
** handle_i
** File description:
** Handles if flag is integer
*/
#include <stdarg.h>
#include "my.h"

char* handles_i(va_list *va, char *format)
{
    (void) format;
    int decimal = va_arg(*va, int);
    char* arr = my_int_to_str(decimal);
    return (arr);
}
