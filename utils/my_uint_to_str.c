/*
** EPITECH PROJECT, 2022
** my_uint_to_str.c
** File description:
** Converts a unsigned int to a string
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "my.h"

char* my_uint_to_str(unsigned int num)
{
    int i = 0;
    char* str = malloc(sizeof(char)*12);

    if (num == 0) {
        str[i++] = '0';
        str[i] = '\0';
        return (str);
    }

    while (num != 0) {
        unsigned int rem = num % 10;
        str[i++] = rem > 9 ? (rem - 10) + 'a' : rem + '0';
        num = num / 10;
    }

    str[i] = '\0';

    str = my_revstr(str);

    return (str);
}
