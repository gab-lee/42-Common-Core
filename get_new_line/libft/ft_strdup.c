#include "libft.h"

static int ft_strlen_local(const char *str);

char *ft_strdup(const char *str)
{
    int i;
    char *dup;

    i = -1;
    if (!(dup = malloc(ft_strlen_local(str) * sizeof(char))))
        return (NULL);
    while (++i, str[i])
        dup[i] = str[i];
    dup[i] = '\0';
    return (dup);
}

static int ft_strlen_local(const char *str)
{
    int len;

    len = -1;
    while (++len, str[len])
        ;
    return (len);
}