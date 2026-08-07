#include "libft.h"

static void ft_bzero_local(void *ptr, size_t n);

void *ft_calloc(size_t count, size_t size)
{
    void *ptr;

    if (!(ptr = malloc(count * size)))
        return (NULL);
    ft_bzero_local(ptr, count * size);
    return (ptr);
}

static void ft_bzero_local(void *ptr, size_t n)
{
    size_t i;

    i = -1;
    while (++i, i < n)
        *((unsigned char *)ptr + i) = (char)(0);
}