/*
** EPITECH PROJECT, 2022
** include01
** File description:
** Handles different includes
*/

#include <stdarg.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"

bool includes_conv(const char* format, int i)
{
    int cnt_1 = 0;
    int cnt_2 = i +1;
    int cnt_3 = 0;
    char* str = my_strdup("aAbcdeEfFgGinopsSuxX");

    while (format[cnt_2]) {
        while (str[cnt_1]) {
            if (str[cnt_1] == format[cnt_2])
                return (true);
            cnt_1++;
        }
        cnt_1 = 0;
        cnt_2++;
    }
    return (false);
}

bool includes_lenmod(const char* format, int i)
{
    int cnt_1 = 0;
    int cnt_2 = i;
    char* str = my_strdup("hlqLjzZt");
    char* final_conv = my_strdup("aAbcdeEfFgGinopsSuxX");
    char str_arr[2][2] = {{'h', 'h'}, {'l', 'l'}};

    while (format[cnt_2++]) {
        while (str[cnt_1++]) {
            if ((str_arr[0][0] == format[cnt_2] && str_arr[0][1] == format[cnt_2+1]) || ((str_arr[1][0] == format[cnt_2] && str_arr[1][1] == format[cnt_2+1]))) {
                return (true);
            }
            if (str[cnt_1] == format[cnt_2]) {
                return (true);
            }
        }
        cnt_1 = 0;
        int cnt_3 = 0;
        while (final_conv[cnt_3++]) {
            if (format[cnt_2] == final_conv[cnt_3])
                return (false);
        }
    }
    return (false);
}

bool includes_precision(const char* format, int i) 
{
    int cnt_1 = 0;
    int cnt_2 = i;
    int cnt_3 = 0;
    char* final_conv = "aAbcdeEfFgGinopsSuxX";

    while (format[cnt_2]) {
        if (format[cnt_2] == '.')
            return (true);
        cnt_2++;
        cnt_3 = 0;
        while (final_conv[cnt_3]) {
            if (format[cnt_2] == final_conv[cnt_3])
                return (false);
            cnt_3++;
        }
    }
    return (false);
}

bool includes_width(const char* format, int i)
{
    int cnt_1 = 0;
    int cnt_2 = i;
    char* str = "0123456789";
    char* final_conv = "aAbcdeEfFgGinopsSuxX";

    while (format[cnt_2]) {
        while (str[cnt_1]) {
            if (str[cnt_1] == format[cnt_2])
                return (true);
            cnt_1++;
        }
        cnt_1 = 0;
        cnt_2++;
        int cnt_3 = 0;
        while (final_conv[cnt_3]) {
            if (format[cnt_2] == final_conv[cnt_3])
                return (false);
            cnt_3++;
        }
    }
    return (false);
}

bool includes_flags(const char* format, int i)
{
    int cnt_1 = 0;
    int cnt_2 = i;
    char* str = my_strdup("#0- +");
    char* final_conv = my_strdup("aAbcdeEfFgGinopsSuxX");

    while (format[cnt_2]) {
        while (str[cnt_1]) {
            if (str[cnt_1] == format[cnt_2])
                return (true);
            cnt_1++;
        }
        cnt_1 = 0;
        cnt_2++;
        int cnt_3 = 0;
        while (final_conv[cnt_3]) {
            if (format[cnt_2] == final_conv[cnt_3])
                return (false);
            cnt_3++;
        }
    }
    return (false);
}
