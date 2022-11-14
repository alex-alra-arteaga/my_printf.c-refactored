/*
** EPITECH PROJECT, 2022
** mini_printf
** File description:
** Minimalistic version of printf
*/

#include "my.h"

int cnt_printf(const char* format, int i)
{
    int cnt_2 = i;
    int cnt_3 = 0;
    char* final_conv = "aAbcdeEfFgGinopsSuxX";

    while (format[cnt_2]) {
        while (final_conv[cnt_3]) {
            if (format[cnt_2] == final_conv[cnt_3])
                return (cnt_2+1);
            cnt_3++;
        }
        cnt_3 = 0;
        cnt_2++;
    }
    return (cnt_2);
}
