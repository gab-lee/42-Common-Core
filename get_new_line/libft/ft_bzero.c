#include "libft.h"

void ft_bzero(void *ptr, size_t n)
{
    size_t i;

    i = -1;
    while (++i, i < n)
        *((unsigned char *)ptr + i) = (char)(0);
}
