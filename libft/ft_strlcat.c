#include "libft.h"

size_t ft_strlcat(char *dest, const char *src, size_t n)
{
    size_t i;
    size_t dest_len;

    i = -1;
    dest_len = ft_strlen(dest);
    if (n < dest_len)
        return (n + ft_strlen(src));
    while (*dest)
        dest++;
    while (++i, src[i] && (dest_len + i < (n - 1)))
        dest[i] = src[i];
    dest[i] = '\0';
    return (dest_len + ft_strlen(src));
}