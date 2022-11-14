/*
** EPITECH PROJECT, 2022
** handle_g
** File description:
** Shows shorter number interpretation of %e or %g
*/

#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>
#include "my.h"

//I have no clue how to test this with a main, but it should work

char* handles_g(va_list *va, char *format)
{
    (void) format;
    char* handle_e_str = handles_e(va, format);
    char* handle_f_str = handles_f(va, format);

    if (my_strlen(handle_e_str) > my_strlen(handle_e_str)) {
        return (handle_f_str);
    }
    return (handle_e_str);
}
