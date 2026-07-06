void *memmove(void *dest, void *src, int n)
{
    int i;
    int tmp;
    
    i = -1;
    temp = malloc(n * sizeof(void *));
    while (++i, i < n)
    	temp [i] = src [i];
    i = -1;
    while (++i, i <n)
		dest[i] = temp[i];
    return (dest);
}