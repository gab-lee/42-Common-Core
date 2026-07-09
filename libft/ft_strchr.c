#include <stdlib.h>

char *ft_strchr(char *str, int c)
{
    int i;

    i = -1;
    while (++i, str[i])
    {
        if ((unsigned char)str[i] == (unsigned char)c)
            return (&str[i]);
    }
    if ((unsigned char)str[i] == (unsigned char)c)
        return (&str[i]);
    return (NULL);
}