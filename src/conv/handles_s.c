/*
** EPITECH PROJECT, 2022
** handle_s
** File description:
** Checks flags and prints the string
*/

#include <stdarg.h>
#include <stddef.h>
#include "my.h"

char* handles_s(va_list *va, char *format)
{
    (void) format;
    char* arr = my_strdup(va_arg(*va, char*));
    return (arr);
}
