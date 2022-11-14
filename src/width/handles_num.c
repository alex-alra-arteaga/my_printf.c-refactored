/*
** EPITECH PROJECT, 2022
** is_only_num
** File description:
** handle the width
*/

#include <stdarg.h>
#include <stddef.h>
#include <stdbool.h>
#include "my.h"

char *positive_padding(char *paddded_arr, int padding, char *argument)
{
    int total_len = padding + my_strlen(argument);
    int cnt = 0;
    int i = 0;

    while (padding > 0) {
        paddded_arr[cnt] = ' ';
        cnt++;
        padding--;
    }
    while (cnt < total_len) {
        paddded_arr[cnt] = argument[i];
        i++;
        cnt++;
    }
    return (paddded_arr);
}

char *negative_padding(char *paddded_arr, int padding, char *argument)
{
    int i = 0;
    int len = padding + my_strlen(argument);

    while (i < (my_strlen(argument))) {
        paddded_arr[i] = argument[i];
        i++;
    }
    while (i < len) {
        paddded_arr[i] = ' ';
        i++;
    }
    return (paddded_arr);
}

char *final_string(char *arr, int nb)
{
    int natural_nb = nb;
    int len = my_strlen(arr);
    char *str = malloc(sizeof(char) * (len + 1));
    str = my_strcpy(str, arr);
    char *padded_arr = NULL;
    int padding = 0;
    if (nb < 0) {
        natural_nb = nb * -1;
    }
    if (natural_nb > len) {
        padding = natural_nb - len;
        padded_arr = malloc(sizeof(char) * (len + padding));
        (nb > 0) ? positive_padding(padded_arr, padding, arr)
        : negative_padding(padded_arr, padding, arr);
    } else {
        return (arr);
    }
    return (padded_arr);
}

char *handles_num(char *arr, int number)
{
    int nb = number;
    char *array = NULL;
    array = my_strdup(arr);
    return (final_string(array, nb));
}
