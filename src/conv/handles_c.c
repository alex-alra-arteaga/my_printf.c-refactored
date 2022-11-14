/*
** EPITECH PROJECT, 2022
** handle_c
** File description:
** Handles if flag is a int and prints it
*/
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>

char* handles_c(va_list *va, char *format)
{
    (void) format;
    char* my_str = malloc(sizeof(unsigned char));
    int nb = (va_arg(*va, int));
    unsigned char my_char = (unsigned char)nb;
    my_str[0] = my_char;
    my_str[1] = '\0';
    return (my_str);
}
