#include "libft.h"

static int ft_intsize(int n, int *sign);
static void ft_fill_str(int n, char *str, int sign);

char *ft_itoa(int n)
{
    char *str;
    int sign;
    int size;

    sign = 1;
    size = ft_intsize(n, &sign);
    if (!(str = malloc(size * sizeof(char))) || !n)
        return (NULL);
    ft_fill_str(n, &str[size - 1], sign);
    return (str);
}

static int ft_intsize(int n, int *sign)
{
    int size;

    size = -1;
    if (n < 0)
    {
        size++;
        *sign = -1;
    }
    while (++size, n)
        n = n / 10;
    return (size);
}
#include <stdio.h>
static void ft_fill_str(int n, char *str, int sign)
{
    printf("n: %d\n", n);
    if (!n)
    {
        if (sign == -1)
            *str = '-';
        return;
    }

    *str = (n % 10) * sign + '0';
    ft_fill_str(n / 10, str - 1, sign);
}
/*
int main(void)
{
    int n = -42;
    char *str = ft_itoa(n);
    printf("%s\n", str);
}
*/