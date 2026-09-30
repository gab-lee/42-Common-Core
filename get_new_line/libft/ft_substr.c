#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    char *substr;
    size_t i;

    i = -1;
    if (!(substr = malloc(len + 1 * sizeof(char))))
        return (NULL);
    while (++i, i < len && (i + start) < ft_strlen(s))
        substr[i] = s[start + i];
    substr[i] = '\0';
    return (substr);
}