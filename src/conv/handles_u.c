/*
** EPITECH PROJECT, 2022
** handle_u
** File description:
** Shows unsigned decimal interpretation
*/

#include <stdarg.h>
#include <stddef.h>
#include "my.h"

char* handles_u(va_list *va, char *format)
{
    (void) format;
    unsigned int u = (va_arg(*va, unsigned int));;
    char* arr = my_uint_to_str(u);
    return (arr);
}
