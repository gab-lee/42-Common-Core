#include "libft.h"

char *ft_strjoin(char const *s1, char const *s2)
{
    char *str;
    int i;

    i = 0;
    if (!(str = malloc(ft_strlen(s1) + ft_strlen(s2) * sizeof(char))))
        return (NULL);
    while (*s1)
        str[i++] = *(s1++);
    while (*s2)
        str[i++] = *(s2++);
    return (str);
}
/*
#include <stdio.h>
int main(void)
{
    char s1[] = "Hello, ";
    char s2[] = "World.";
    char *s3 = ft_strjoin(s1, s2);
    printf("%s", s3);
}
*/