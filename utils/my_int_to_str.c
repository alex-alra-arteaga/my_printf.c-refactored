/*
** EPITECH PROJECT, 2022
** my_int_to_str.c
** File description:
** Converts a int to a string
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "my.h"

char* handle_errors(char* str, int i)
{
    str[i++] = '0';
    str[i] = '\0';
    return (str);
}

char* reverse_str(char* str, int i)
{
    str[i] = '\0';
    str = my_revstr(str);
    return (str);
}

char* my_int_to_str(int num)
{
    int i = 0;
    char *str = malloc(sizeof(char)*12);
    bool isNegative = false;
    if (num == 0) {
        str = handle_errors(str, i);
        return (str);
    }
    if (num < 0) {
        isNegative = true;
        num = -num;
    }
    while (num != 0) {
        int rem = num % 10;
        str[i++] = rem > 9 ? (rem - 10) + 'a' : rem + '0';
        num = num / 10;
    }
    if (isNegative)
        str[i++] = '-';
    str = reverse_str(str, i);
    return (str);
}
