/*
** EPITECH PROJECT, 2022
** my_strdup.c
** File description:
** allocates memory and copies the string given as argument
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"

char *my_strdup(char const *src)
{
    int i = 0;
    int len = my_strlen(src);
    char *string = malloc((len +1) * sizeof(char));
    while (src[i] != '\0') {
        string[i] = src[i];
        i++;
    }
    string[i] = '\0';
    return (string);
}
