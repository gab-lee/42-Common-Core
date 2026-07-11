#include "libft.h"

char *ft_strtrim(char const *s1, char const *set)
{
    char *tstr;
    int tsize;
    char *tmp;
    int i;

    i = -1;
    tsize = 0;
    while (*tmp)
    {
        if (ft_strchr(set, (int)*(tmp++)))
            tsize++;
    }
    if (!(tstr = malloc((ft_strlen(s1) - tsize + 1) * sizeof(char))))
        return (NULL);
    while (++i, s1[i])
    {
        if (!(ft_strchr(set, (int)(s1[i]))))
            *(tstr++) = s1[i];
    }
    *tstr = '\0';
    return (tstr);
}