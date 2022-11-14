/*
** EPITECH PROJECT, 2022
** my_int_to_str.c
** File description:
** Converts a int to a string
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int len_long(char const *str)
{
    int i = 0;
    while (str[i]) {
        i++;
    }
    return (i);
}

char *my_revstr_long(char *str)
{
    int i = 0;
    int j = len_long(str) - 1;
    char str_temp;
    while (j > i) {
        str_temp = str[i];
        str[i] = str[j];
        str[j] = str_temp;
        i ++;
        j --;
    }
    return (str);
}

char* my_long_to_str(long num)
{
    int i = 0;
    char* str = malloc(sizeof(char)*21);

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

    str = my_revstr_long(str);

    return (str);
}
