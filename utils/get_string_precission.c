/*
** EPITECH PROJECT, 2022
** handle_precision.c
** File description:
** handle the precision
*/

#include <stdarg.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>
#include "my.h"

char *get_string_precission(char *string, int nb, int i)
{
    int extra_0 = 0;
    int j = 0;
    char *str = malloc(sizeof(char) * 1000);
    char *new_string;
    if ((my_str_isalpha(string) == 1
    || is_only_num(string) == 0) && my_strlen(string) > nb) {
        string[nb] = '\0';
        return (string);
    }
    if ((my_str_isalpha(string) == 1
    || is_only_num(string) == 0) && my_strlen(string) < nb) {
        return (string);
    }
    if (my_str_isalpha(string) == 0 &&
    is_float(string) == false && is_only_num(string) == 1 && my_strlen(string) < nb) {
        extra_0 = nb - my_strlen(string);
        while (extra_0 > 0) {
            str[j] = '0';
            extra_0 --;
            j ++;
        }
        return (my_strcat(str, string));
    }

    if (my_str_isalpha(string) == 0 &&
    is_float(string) == false && is_only_num(string) == 1)
        new_string = my_strdup(precision_int(string, nb));

    if (my_str_isalpha(string) == 0 &&
    is_special_float(string, nb) == false && is_only_num(string) == 1) {
        while (string[i] != '.') {
            i++;
        }
        string[i + (nb + 1)] = '\0';
        return (string);
    }
    if (my_str_isalpha(string) == 0 &&
    is_special_float(string, nb) == true && is_float(string) == true) {
        new_string = my_strdup(special_float(string, nb));
    }
    return (new_string);
}
