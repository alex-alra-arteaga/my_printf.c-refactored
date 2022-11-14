/*
** EPITECH PROJECT, 2022
** handle_f
** File description:
** Shows float number
*/

#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>
#include "my.h"

char* handles_f(va_list *va, char *format)
{
    (void) format;
    char* array = malloc(sizeof(char*));
    float num = va_arg(*va, double);
    bool negative = false;

    if (num < 0) {
        num = -1 * num;
        negative = true;
    }
    long whole_n = (int)num;
    long decimal = (long)(num* 1000000) - (long)(whole_n * 1000000);
    char* decimals = my_long_to_str(decimal);
    int dec_len = my_strlen(decimals);
    if (negative)
        my_strcat(array, "-");
    my_strcat(array, my_long_to_str(whole_n));
    my_strcat(array, ".");
    my_strncat(array, decimals, dec_len);
    return (array);
}
