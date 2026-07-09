#include "libft.h"

static int ft_strlen(char *str);

char *ft_strdup(char *str)
{
    int i;
    char *dup;

    i = -1;
    if (!(dup = malloc(ft_strlen(str) * sizeof(char))))
        return (NULL);
    while (++i, str[i])
        dup[i] = str[i];
    return (dup);
}

static int ft_strlen(char *str)
{
    int len;

    len = -1;
    while (++len, str[len])
        ;
    return (len);
}