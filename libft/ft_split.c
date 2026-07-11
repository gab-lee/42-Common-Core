#include "libft.h"

static int ft_count_splits(char const *s, char c);

char **ft_split(char const *s, char c)
{
    int i;
    int j;
    int nsplits;
    char **array;

    i = -1;
    j = 0;
    nsplits = ft_count_splits(*s, c);
    if (!(array = malloc(nsplits * sizeof(char *))))
        return (NULL);
    while (++i, i < nsplits, *(s++))
    {
        while (*s != c)
            array[i][j++] = *s;
        j = 0;
    }
    return (array);
}

static int ft_count_splits(char const *s, char c)
{
    int n;

    n = 0;
    while (*(s++))
    {
        if (*s == c)
            n++;
    }
}