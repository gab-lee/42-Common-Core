char *ft_strcpy(char *dest, char *src)
{
    int i;

    i = -1;
    while (++i, src[i])
        dest[i] = src[i];
    return (dest);
}