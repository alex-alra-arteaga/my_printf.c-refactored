/*
** EPITECH PROJECT, 2022
** handle_G
** File description:
** Shows shorter number interpretation of %E or %F
*/

#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>
#include "my.h"

char* handles_G(va_list *va, char *format)
{
    (void) format;
    char* handle_e_str = handles_E(va, format);
    char* handle_f_str = handles_F(va, format);

    if (my_strlen(handle_e_str) > my_strlen(handle_f_str)) {
        return (handle_f_str);
    }
    return (handle_e_str);
}
