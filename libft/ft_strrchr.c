#include "libft.h"

char *ft_strrchr(char *str, int c)
{
    int i;
    char *ptr;

    i = -1;
    ptr = NULL;
    while (++i, str[i])
    {
        if ((unsigned char)str[i] == (unsigned char)c)
            ptr = &str[i];
    }
    if ((unsigned char)str[i] == (unsigned char)c)
        return (&str[i]);
    return (ptr);
}