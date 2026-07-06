char *strncpy(char *dest, char *src, int n)
{
    int i;
    
    i = -1;
    if (!n)
    	return (dest);
    while (++i, src[i] && i < n)
    	dest[i] = src[i];
    return (dest);
}