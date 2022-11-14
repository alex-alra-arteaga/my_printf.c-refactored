/*
** EPITECH PROJECT, 2022
** handle_e
** File description:
** Shows scientific number interpretation
*/

#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>
#include "my.h"

char* positive_exponent_e(char* array, double num, bool negative)
{
    int i = 0;
    while (num > 10) {
            num = num / 10;
            i++;
        }
        long whole_n_after = (int)num;
        long decimal = (long) ((int) (num * 1000000))
         % (long) (whole_n_after * 1000000);
        char* decimals = my_long_to_str(decimal);
        int dec_len = my_strlen(decimals);
        if (negative)
            my_strcat(array, "-");
        my_strcat(array, my_long_to_str(whole_n_after));
        my_strcat(array, ".");
        my_strncat(array, decimals, dec_len);
        my_strcat(array, "e+");
        if (i < 10)
            my_strcat(array, "0");
        my_strcat(array, my_int_to_str(i));
        return (array);
}

char* negative_exponent_e(char* array, double num, bool negative)
{
    int i = 0;
    while (num < 1) {
        num = num * 10;
        i++;
    }
    long whole_n_after = (int)num;
    long decimal = (long) ((int) (num * 1000000))
     % (long) (whole_n_after * 1000000);
    char* decimals = my_long_to_str(decimal);
    int dec_len = my_strlen(decimals);
    if (negative)
        my_strcat(array, "-");
    my_strcat(array, my_long_to_str(whole_n_after));
    my_strcat(array, ".");
    my_strncat(array, decimals, dec_len);
    my_strcat(array, "e-");
    if (i < 10)
        my_strcat(array, "0");
    my_strcat(array, my_int_to_str(i));
    return (array);
}

char* handles_e(va_list *va, char *format)
{
    (void) format;
    char* array = malloc(sizeof(char*));
    double num = va_arg(*va, double);
    bool negative = false;

    if (num < 0) {
        num = -1 * num;
        negative = true;
    }
    int whole_n = (int)num;
    if (whole_n != 0) {
        array = positive_exponent_e(array, num, negative);
    } else {
    array = negative_exponent_e(array, num, negative);
    }
    return (array);
}
