#include "libft.h"

static size_t local_ft_strlen(const char *str);

size_t ft_strlcpy(char *dest, const char *src, size_t n)
{
    size_t i;

    i = -1;
    if (!n)
        return local_ft_strlen(src);
    while (++i, src[i] && i < (n - 1))
        dest[i] = src[i];
    dest[i] = '\0';
    return (local_ft_strlen(src));
}

static size_t local_ft_strlen(const char *str)
{
    int len;

    len = -1;
    while (len++, str[len])
        ;
    return (len);
}
