/*
** EPITECH PROJECT 2022
** fnc_ptr.h
** File description:
** Fnc_ptr
*/

#ifndef FNC_PTR_H_
    #define FNC_PTR_H_

    #include <stdarg.h>

    typedef struct s_flags {
        char *op;
        char*(*ptr)(char *arr);
    } t_flags;

    typedef struct s_width {
        char *op;
        char*(*ptr)(char *arr, int nb); // + 1 argument/parameter
    } t_width;

    typedef struct s_precision {
        char *op;
        char*(*ptr)(char *arr, int nb); // +1 argument/parameter
    } t_precision;

    typedef struct s_lenmod {
        char *op;
        char*(*ptr)(char *arr);
    } t_lenmod;

    typedef struct s_conv {
        char *op;
        char*(*ptr)(va_list *, char* format);
    } t_conv;

    typedef struct deci_point { //for handle_hash.c
        char*(*ptr)(char *arr, char* format);
    } t_handle_hash;

#endif
