/*
** EPITECH PROJECT, 2022
** handle_p
** File description:
** Shows pointer number interpretation
*/

#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>
#include "my.h"

char* handles_x_p(void *ptr)
{
    unsigned long long *arr = malloc(sizeof(unsigned long long) *14);
    char* array = malloc(sizeof(char*)*2 +3);
    int i = 2;
    int j = 0;
    unsigned long long num = (unsigned long long)ptr;
    char* hexa = "0123456789abcdef";
    my_strcat(array, "0x");
    while (num != 0) {
        arr[i++] = num % 16;
        num = num / 16;
    }
    j = i -1;
    i = 0;
    while (j-- > 0) {
        array[i + 2] = hexa[arr[j]];
        i++;
    }
    array[i + 1] = '\0';
    free(arr);
    return (array);
}

char* handles_p(va_list *va, char *format)
{
    (void)format;
    void* ptr = va_arg(*va, void*);
    char* array = handles_x(ptr, format);
    my_putstr(array);
    return (array);
}
