char *ft_strcat(char *dest, char *src)
{
    int i;

    i = -1;
    while (*dest)
        *dest++;
    while (++i, src[i])
        dest[i] = src[i];
    return (dest);
}