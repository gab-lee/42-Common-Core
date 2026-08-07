#include <stdlib.h>

char *ft_strchr(const char *str, int c)
{
    int i;

    i = -1;
    while (++i, str[i])
    {
        if ((unsigned char)str[i] == (unsigned char)c)
            return ((char *)&str[i]);
    }
    if ((unsigned char)str[i] == (unsigned char)c)
        return ((char *)&str[i]);
    return (NULL);
}