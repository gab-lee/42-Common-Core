#include "libft.h"

char *ft_strrchr(const char *str, int c)
{
    int i;
    char *ptr;

    i = -1;
    ptr = NULL;
    while (++i, str[i])
    {
        if ((unsigned char)str[i] == (unsigned char)c)
            ptr = (char *)&str[i];
    }
    if ((unsigned char)str[i] == (unsigned char)c)
        return ((char *)&str[i]);
    return (ptr);
}