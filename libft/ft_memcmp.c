int memcmp(void *s1, void *s2, int n)
{
    int i;
    
    i = -1;
    while (++i, i < n)
    {
         if (s1[i] != s2[i])
        	return (s2[i] -  s1[i]);
    }
    return (0);
}