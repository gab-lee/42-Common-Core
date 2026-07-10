#include "libft.h"

static void *ft_memset_helper(void *ptr, int c, size_t n);

void ft_bzero(void *ptr, size_t n)
{
    ft_memset_helper(ptr, 0, n);
}

static void *ft_memset_helper(void *ptr, int c, size_t n)
{
    size_t i;

    i = -1;
    while (++i, i < n)
        *((unsigned char *)ptr + i) = (char)(c);
    return (ptr);
}
