voiid *memcpy(void *dest, void *src, int n)
{
    int i;
    
    i = -1;
    while (++i, i < n)
    	dest[i] = src[i];
    return (dest);
}