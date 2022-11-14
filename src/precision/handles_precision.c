/*
** EPITECH PROJECT, 2022
** handle_precision.c
** File description:
** handle the precision
*/

#include <stdarg.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"

int get_i (int i, char *string) {
     while (string[i] != '.') {
        i++;
    }
    return(i);
}

bool is_special_float(char *str, int nb)
{
    int i = 0;
    int cnt = 0;
    bool count = false;

    while (str[i] != '\0') {
        if (str[i] == '.') {
            count = true;
        }
        i++;
        if (count == true) {
            cnt++;
        }
    }
    return ((cnt < nb) ? true : false);
}

char *special_float(char *string, int nb)
{
    int cnt = 0;
    int i = 0;
    int extra_space = 0;
    char *new_str = NULL;
    i = get_i(i, string);
    while (string[i] != '\0') {
        cnt++;
        i++;
    }
    extra_space = nb - cnt;
    new_str = malloc(sizeof(char) * (my_strlen(string) + extra_space +1));
    my_strcpy(new_str, string);
    while (extra_space >= 0) {
        new_str[i] = '0';
        i++;
        extra_space--;
    }
    new_str[i] = '\0';
    return (new_str);
}

char *precision_int(char* string, int nb)
{
    int i = 0;
    int j = 0;
    int len = my_strlen(string) + 1;
    char *str = NULL;
    while (string[i]) {
        if (string[i] == '.')
            string[i] = '\0';
            return (string);
        i++;
    }
    str = malloc(sizeof(char) * (len + nb +1));
    str[0] = '\0';
    my_strcpy(str, string);
    str[len - 1] = '.';
    while (nb > 0) {
        str[len + j] = '0';
        nb--;
        j++;
    }
    str[len + j] = '\0';
    return (str);
}

char *handles_precisionss(char *arr, int number)
{
    int j = 0;
    int i = 0;
    int nb = number;
    char *string = my_strdup(arr);
    char *final_string = NULL;
    while (string[j] != '\0') {
        if (nb == 0 && (string[j] == '.' && string[j + 1] == '0')) {
            my_putchar('\n');
            break;
        }
        if (nb == 0 && string[j] == '.' && string[j + 1] == 'e' && (string[j + 2] == '-' || string[j + 2] == '+')) {
            string[j] = '\0';
        }
        j++;
    }
    final_string = my_strdup(get_string_precission(string, nb, i));
    free(string);
    return (final_string);
}
