/*
** EPITECH PROJECT, 2022
** handle_hash.c
** File description:
** If it's octal conversions, outputs a 0 at the beginning, if it's %x or %X, an 0x
*/
/*
#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>
#include "my.h"
#include "fnc_ptr.h"

//Use structs

char* handle_hash(va_list *va, char *format, t_conv *conv)
{
    (void) format;
    int i = 0;
    //0
    //0x
    //Decimal point
    t_handle_hash put_zero_x[2] = {
        &handle_x,
        &handle_X,
    };

    t_handle_hash deci_point[8] = {
        &handle_a,
        &handle_A,
        &handle_e,
        &handle_E,
        &handle_f,
        &handle_F,
        &handle_g,
        &handle_G,
    };
    
    if (conv[1].ptr == handle_o) {
        char* zero = my_strdup("")
        char* handle_o_str = my_strdup(handle_o(va, format));
    } 

    if (conv[1].ptr == &put_zero_x[i]) {
        char* str = put_zero_x[i].ptr(va, format);
    }

    if (conv[1].ptr == &deci_point[i]) {

        char* str = deci_point[i].ptr(va, format);

    }
    return ();
}
*/