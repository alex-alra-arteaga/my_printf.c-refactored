/*
** EPITECH PROJECT, 2022
** printf
** File description:
** printf
*/

#include <stdarg.h>
#include <stddef.h>
#include <stdbool.h>
#include "fnc_ptr.h"
#include "my.h"
/*
const t_flags flags[5] = {
    {"#", &handle_hash},
    {"0", &handle_0},
    {"-", &handle_minus},
    {" ", &handle_space},
    {"+", &handle_plus},
};*/

const t_width width[] = {
    {"0", &handles_num},
    {"1", &handles_num},
    {"2", &handles_num},
    {"3", &handles_num},
    {"4", &handles_num},
    {"5", &handles_num},
    {"6", &handles_num},
    {"7", &handles_num},
    {"8", &handles_num},
    {"9", &handles_num},
};

const t_precision precision[] = {
    {".", &handles_precisionss},
};
/*
const t_lenmod lenmod[10] = {
    {"hh", &handle_hh},
    {"h", &handle_h},
    {"l", &handle_l},
    {"ll", &handle_ll},
    {"q", &handle_q},
    {"L", &handle_L},
    {"j", &handle_j},
    {"z", &handle_z},
    {"Z", &handle_Z},
    {"t", &handle_t},
};*/

const t_conv conv[] = {
    {"d", &handles_d},
    {"i", &handles_i},
    {"c", &handles_c},
    {"s", &handles_s},
    {"o", &handles_o},
    {"u", &handles_u},
    {"x", &handles_x},
    {"X", &handles_X},
    {"e", &handles_e},
    {"E", &handles_E},
    {"f", &handles_f},
    {"F", &handles_F},
    {"g", &handles_g},
    {"G", &handles_G},
    {"a", &handles_a},
    {"A", &handles_A},
    {"p", &handles_p},
    {"n", &handles_n},
    {"b", &handles_b},
    {"S", &handles_S},
    {NULL, NULL}
};

char* converse_types(char* format, int i, char* str_return, va_list *va)
{
    char* str_return_tmp = NULL;
    if (includes_conv(format, i)) {
        str_return_tmp = handles_conv(i, va, format, conv);
        free(str_return);
        str_return = str_return_tmp;
        str_return_tmp = NULL;
        }
    if (includes_precision(format, i)) {
        str_return_tmp = handless_precision(i, str_return, format, precision);
        free(str_return);
        str_return = str_return_tmp;
        str_return_tmp = NULL;
    }
    if (includes_width(format, i)) {
        str_return_tmp = handles_width(i, str_return, format, width);
        free(str_return);
        str_return = str_return_tmp;
        str_return_tmp = NULL;
    }
    return (str_return);
}

int my_printf(char *format, ...)
{
    va_list va;
    int i = 0;
    va_start(va, format);
    while (format[i]) {
        char* str_return = malloc(sizeof(char) *1000);
        str_return[0] = '\0';
        if (format[i] == '%' && format[i +1] == '%') {
            my_putchar('%');
            i = i +2;
            continue;
        }
        if (format[i] == '%' && format[i +1] && format[i +1] != '%') {
            str_return = converse_types(format, i, str_return, &va);
            i = cnt_printf(format, i);
            my_putstr(str_return);
        }
        if (format[i++] != '\0')
            my_putchar(format[i]);
    }
    va_end(va);
    return (i);
}
