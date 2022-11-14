/*
** EPITECH PROJECT, 2022
** handle_b
** File description:
** Prints unsigned numbers in a binary base
*/

#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>
#include "my.h"

char* handles_b(va_list *va, char *format)
{
    (void)format;
    unsigned int *arr = malloc(17 * sizeof(unsigned int));
    int i = 1;
    int j = 0;
    unsigned int num = va_arg(*va, unsigned int);
    unsigned long long binary_n = 0;

    while (num != 0) {
        arr[i++] = num % 2;
        num = num / 2;
    }
    j = i -1;
    while (j > 0) {
        binary_n = binary_n * 10 + arr[j];
        j--;
    }
    char* array = my_ulong_long_to_str(binary_n);
    free(arr);
    return (array);
}
