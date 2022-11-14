/*
** EPITECH PROJECT, 2022
** handle_structs.c
** File description:
** handle the structs
*/

#include "my.h"
#include "fnc_ptr.h"

char* handles_conv(int i, va_list *va, char *format, const t_conv *conv)
{
    int j = 0;
    int cnt_1 = 0;
    int cnt_2 = i +1;
    int cnt_3 = 0;
    char *arr = my_strdup("dicsaAbcdeEfFgGinopsSuxX");

    while (format[cnt_2] && cnt_3 != 1 && format[i] == '%') {
        while (arr[cnt_3]) {
            if (format[cnt_2] == arr[cnt_3]) {
                cnt_3 = 1;
                break;
            }
            cnt_3++;
        }
        if (format[cnt_2 + 1] == '%')
            break;
        if (cnt_3 == 1) {
            break;
        }
        cnt_1 = 0;
        cnt_2++;
        cnt_3 = 0;
    }
    char* str_return_tmp = NULL;
    char* str_return_conv = malloc(sizeof(char) *1000);
    str_return_conv[0] = '\0';
    while (conv[j].op) {
        if (conv[j].op[0] == format[cnt_2]) {
            str_return_tmp = conv[j].ptr(va, format);
            free(str_return_conv);
            str_return_conv = str_return_tmp;
            str_return_tmp = NULL;
        }
        j++;
    }
    free(arr);
    arr = NULL;
    return (str_return_conv);
}

char* handles_lenmod(int i, char *str_return,
char *format, const t_lenmod *lenmod)
{
    int j = 0;
    int cnt_1 = 0;
    int cnt_2 = i;
    int cnt_3 = 0;
    char *str = my_strdup("hlqLjzZt");
    char arr[2][2] = {{'h', 'h'}, {'l', 'l'}};

    while (format[cnt_2++] && cnt_3 != 1) {
        while (str[cnt_1]) {
            ((arr[cnt_1][0] == format[cnt_2] &&
            arr[cnt_1][0] == format[cnt_2 + 1])
            || (arr[cnt_1][1] == format[cnt_2] &&
            arr[cnt_1][1] == format[cnt_2 + 1])
            || (str[cnt_1] == format[cnt_2])) ? cnt_3 = 1 : cnt_1++;
        }
        cnt_1 = 0;
    }
    char* str_return_lenmod = malloc(sizeof(char)*1000);
    str_return_lenmod[0] = '\0';
    while (lenmod[j++].op[0]) {
        if (lenmod[j].op[0] == format[cnt_2])
            str_return_lenmod = lenmod[j].ptr(str_return);
    }
    return (str_return_lenmod);
}

char* handless_precision(int i, char *str_return,
char *format, const t_precision *precision)
{
    char* str_return_precision = malloc(sizeof(char) *1000);
    str_return_precision[0] = '\0';
    char* str_return_tmp = NULL;

    int nb = get_nb_precision(format, i);
    str_return_tmp = precision[0].ptr(str_return, nb);
    free(str_return_precision);
    str_return_precision = str_return_tmp;
    str_return_tmp = NULL;
    return (str_return_precision);
}

char* handles_width(int i, char *str_return, char *format, const t_width *width)
{
    char* str_return_tmp = NULL;

    char *arr = my_strdup("0123456789");
    int nb = get_nb_width(format, i);
    str_return_tmp = width[0].ptr(str_return, nb);
    return (str_return_tmp);
}

char* handles_flags(int i, char *str_return, char *format, const t_flags *flags)
{
    int j = 0;
    int cnt_1 = 0;
    int cnt_2 = i;
    int cnt_3 = 0;
    char *arr = my_strdup("#0- +");

    while (format[cnt_2] && cnt_3 != 1) {
        while (arr[cnt_1] != format[cnt_2]) {
            (arr[cnt_1] == format[cnt_2]) ? cnt_3 = 1 : cnt_1++;
        }
        cnt_2++;
    }
    char* str_return_flags = malloc(sizeof(char)*1000);
    str_return_flags[0] = '\0';
    while (flags[j].op[0]) {
        if (flags[j].op[0] == format[cnt_2])
            str_return_flags = flags[j].ptr(str_return);
        j++;
    }
    return (str_return_flags);
}
