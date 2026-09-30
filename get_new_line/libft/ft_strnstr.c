#include "libft.h"

char *ft_strnstr(const char *haystack, const char *needle, size_t n)
{
    size_t i;
    size_t j;

    i = -1;
    j = 0;
    if (!needle || *needle == '\0')
        return ((char *)haystack);
    while (++i, haystack[i] && i < n)
    {
        if (haystack[i] == needle[j])
        {
            while (++j, i + j < n && needle[j] && haystack[i + j] == needle[j])
                ;
            if (!needle[j])
                return ((char *)&haystack[i]);
            else
                j = 0;
        }
    }
    return (NULL);
}