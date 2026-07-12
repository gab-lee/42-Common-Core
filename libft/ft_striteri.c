#include "libft.h"

void ft_striteri(char *s, void (*f)(unsigned int, char *))
{
    int i;

    i = -1;
    while (++i, s[i])
        f(i, &s[i]);
}