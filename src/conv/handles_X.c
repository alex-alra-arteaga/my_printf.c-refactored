/*
** EPITECH PROJECT, 2022
** handle_u
** File description:
** Shows unsigned hexadecimal interpretation (base 16)
*/

#include <stdarg.h>
#include <stddef.h>
#include "my.h"

char* handles_X(va_list *va, char *format)
{
    (void) format;
    unsigned int *arr = malloc(17 * sizeof(unsigned int));
    char* array = malloc(sizeof(char*));
    int i = 0;
    int j = 0;
    unsigned int num = (va_arg(*va, unsigned int));
    char* hexa = "0123456789ABCDEF";

    while (num != 0) {
        arr[i++] = num % 16;
        num = num / 16;
    }
    j = i;
    i = 0;
    while (j-- > 0) {
        array[i] = hexa[arr[j]];
        i++;
    }
    free(arr);
    return (array);
}
