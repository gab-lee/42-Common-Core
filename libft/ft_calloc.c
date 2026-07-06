void *bzero(void *ptr, int n);
=
void	*ft_calloc(size_t count, size_t size)
{
 	void *ptr;
    if(!(ptr = malloc(count * size))
    	return (NULL);
    bzero(ptr, count * size);
    return (ptr);   
}

void *bzero(void *ptr, int n)
{
    int	i;
    
    i = -1;
    while (++i, i < n)
    	p[i] = '\0';
    return (ptr);
}=