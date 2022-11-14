/*
** EPITECH PROJECT, 2022
** handles_a
** File description:
** Prints the floating-point number in hexadecimal form
*/

#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>
#include "my.h"

char* handle_decimal_hex(double nb)
{
    int *arr = malloc(17 * sizeof(int));
    char *hex_deci = malloc(sizeof(int));
    int i = 1;
    int j = 0;
    double num = nb;
    char hexa[] = "0123456789abcdef";
    long whole_n = (int)num;
    long decimal = (long)(num* 1000000) - (long)(whole_n * 1000000);
    while (decimal != 0) {
        arr[i++] = decimal % 16;
        decimal = decimal / 16;
    }
    j = i -1;
    i = 0;
    while (j-- > 0) {
        hex_deci[i] = hexa[arr[j]];
        i++;
    }
    free(arr);
    return (hex_deci);
}

char* cats_if_whole_is_greater_a(int cnt, char* array)
{
    my_strcat(array, "+");
    my_strcat(array, my_int_to_str(cnt));
    return (array);
}

char* cats_if_whole_is_lower_a(int cnt_2, char* array)
{
    my_strcat(array, "-");
    my_strcat(array, my_int_to_str(cnt_2));
}

char* strcats_handle_a(char* array, long whole_n,
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
        cats_if_whole_is_greater_a(cnt, array);
    } else {
        cats_if_whole_is_lower_a(cnt_2, array);
    }
    return (array);
}

char* handles_a(va_list *va, char *format)
{
    (void) format;
    char* array = malloc(sizeof(char*));
    double num = va_arg(*va, double);
    int cnt = 0;
    int cnt_2 = 0;
    long whole_n = (int)num;
    bool wholeIsGreater = false;

    whole_n = (int)num;
    my_strcat(array, "0x");
    my_strcat(array, my_long_to_str(whole_n));
    my_strcat(array, ".");
    my_strcat(array, handle_decimal_hex(num));
    my_strcat(array, "p");
    array = strcats_handle_a(array, whole_n, num,
     wholeIsGreater);
    return (array);
}