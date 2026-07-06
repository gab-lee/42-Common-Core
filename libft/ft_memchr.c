void *memchr(void *ptr, int c, int n)
{
    int i;
    
    i = -1;
    while (i < n)
    {
    	if (ptr[i] == (unsigned char)(c % 256))
        	return (&ptr[i]);
	}
    return (NULL);
}