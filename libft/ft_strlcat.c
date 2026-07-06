int strlcat(char *dest, char *src, int n)
{
    int i;
    
    i = -1;
    while(*dest)
        *dest++;
    while (++i, src[i] && i < (n-1))
        dest[i] = src[i];
    dest[i] = '\0';
    return (dest);
}