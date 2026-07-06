void *memset(void *ptr, int c, int n)
{
    int	i;

    i = -1;
    while (++i, i < n)
        ptr[i] = (unsigned char)(c % 256);
}