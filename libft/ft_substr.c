#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    char *substr;
    int i;

    i = -1;
    if (!(substr = malloc(ft_strlen(s) * sizeof(char))))
        return (NULL);
    while (++i, start < len)
        substr[i] = s[start + i];
    return (substr);
}