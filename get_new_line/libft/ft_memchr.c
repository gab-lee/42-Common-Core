#include "libft.h"

void *ft_memchr(const void *ptr, int c, size_t n)
{
    size_t i;

    i = -1;
    while (++i, i < n)
    {
        if (*((unsigned char *)ptr + i) == (unsigned char)(c))
            return ((unsigned char *)ptr + i);
    }
    return (NULL);
}