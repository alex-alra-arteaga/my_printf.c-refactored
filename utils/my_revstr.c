/*
** EPITECH PROJECT, 2022
** my_revstr
** File description:
** write a function that reverses a string
*/
int len(char const *str)
{
    int i = 0;
    while (str[i]) {
        i++;
    }
    return (i);
}

char *my_revstr(char *str)
{
    int i = 0;
    int j = len(str) - 1;
    char str_temp;
    while (j > i) {
        str_temp = str[i];
        str[i] = str[j];
        str[j] = str_temp;
        i++;
        j--;
    }
    return (str);
}
