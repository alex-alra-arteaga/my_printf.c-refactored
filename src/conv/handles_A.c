/*
** EPITECH PROJECT, 2022
** handles_A
** File description:
** Prints the floating-point number in hexadecimal form
*/

#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>
#include "my.h"

char* cats_if_whole_is_greater_A(int cnt, char* array)
{
    my_strcat(array, "+");
    my_strcat(array, my_int_to_str(cnt));
    return (array);
}

char* cats_if_whole_is_lower_A(int cnt_2, char* array)
{
    my_strcat(array, "-");
    my_strcat(array, my_int_to_str(cnt_2));
}

char* strcats_handle_A(char* array, long whole_n,
 double num, bool wholeIsGreater)
{
    int cnt = 0;
    int cnt_2 = 0;
    if (whole_n > 2) {
        while (num > 2) {
            num = num / 2;
            cnt++;
        }
        wholeIsGreater = true;
    } else {
        while (num < 1) {
            num = num * 2;
            cnt_2++;
        }
    }
    if (wholeIsGreater) {
        cats_if_whole_is_greater_A(cnt, array);
    } else {
        cats_if_whole_is_lower_A(cnt_2, array);
    }
    return (array);
}

char* handles_A(va_list *va, char *format)
{
    (void) format;
    char* array = malloc(sizeof(char*));
    double num = va_arg(*va, double);
    int cnt = 0;
    int cnt_2 = 0;
    long whole_n = (int)num;
    bool wholeIsGreater = false;

    whole_n = (int)num;
    my_strcat(array, "0X");
    my_strcat(array, my_long_to_str(whole_n));
    my_strcat(array, ".");
    my_strcat(array, handle_decimal_hex(num));
    my_strcat(array, "P");
    array = strcats_handle_A(array, whole_n, num, wholeIsGreater);
    return (array);
}
