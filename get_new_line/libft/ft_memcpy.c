#include "libft.h"

void *ft_memcpy(void *dest, const void *src, size_t n)
{
    size_t i;

    i = -1;
    while (++i, i < n)
        *((unsigned char *)dest + i) = *((unsigned char *)src + i);
    return (dest);
}