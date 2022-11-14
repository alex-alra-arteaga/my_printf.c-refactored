/*
** EPITECH PROJECT, 2022
** handle_S
** File description:
** Prints the string, non-printable characters are represented w/
** backlash and the value in octal base.
*/

#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>
#include "my.h"

char* cat_str(char* main_str, char* temp_str)
{
    my_strcat(main_str, temp_str);
    free(temp_str);
    return (main_str);
}

char* get_octal(int num, int* arr, char* temp, char* format)
{
    (void) format;
    int octal_n = 0;
    int j = 0;
    int l = 0;
    while (num != 0) {
        arr[l++] = num % 8;
        num = num / 8;
    }
    j = l -1;
    while (j >= 0)
        octal_n = octal_n * 10 + arr[j--];
    char* nb_arr = my_int_to_str(octal_n);
    my_strcat(temp, nb_arr);
    return (temp);
}

char* return_temp_str(char* temp_str, int i, char* input_str)
{
    temp_str[0] = input_str[i++];
    temp_str[1] = '\0';
    return (temp_str);
}

char* handles_S(va_list *va, char *format)
{
    char* input_str = va_arg(*va, char*);
    char* main_str = malloc(sizeof(char)* my_strlen(input_str) * 4 + 2);
    main_str[0] = '\0';
    int i = 0;
    int num = 0;
    while (input_str[i]) {
        char *temp_str = malloc(sizeof(char)*10);
        int* arr = malloc(sizeof(int)* 20);
        arr[0] = 0;
        if (input_str[i] < 32 || input_str[i] > 126) {
            my_strcat(main_str, "\\");
            num = input_str[i++];
            main_str = get_octal(num, arr, main_str, format);
            free(arr);
            continue;
        }
        temp_str = return_temp_str(temp_str, i, input_str);
        main_str = cat_str(main_str, temp_str);
    }
    return (main_str);
}
