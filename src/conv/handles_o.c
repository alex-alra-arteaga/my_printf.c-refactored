/*
** EPITECH PROJECT, 2022
** handle_o
** File description:
** Shows octal number interpretation
*/

#include <stdarg.h>
#include <stddef.h>
#include "my.h"

char* handles_o(va_list *va, char *format)
{
    (void) format;
    unsigned int *arr = malloc(10 * sizeof(unsigned int));
    int i = 1;
    int j = 0;
    unsigned int num = (va_arg(*va, unsigned int));
    unsigned int octal_n = 0;

    while (num != 0) {
        arr[i++] = num % 8;
        num = num / 8;
    }
    j = i -1;
    while (j > 0) {
        octal_n = octal_n * 10 + arr[j];
        j--;
    }
    char* array = my_uint_to_str(octal_n);
    free(arr);
    return (array);
}
