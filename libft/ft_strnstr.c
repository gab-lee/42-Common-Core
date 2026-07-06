char *strnstr(char *haystack, char *needle, int n)
{
    int i;
    int	j;
    
    i = -1;
    j = 0;
    while (++i, haystack[i] && i < n)
    {
        if(haystack[i] = needele[j])
        {
            while (++j, i+j < n && needle[j] && haystack[i+j] == needle[j])
            	;
            if (!needle[j])
            	return (&haystack[i]);
            else
            	j = 0;
            
        }
    }
    return (NULL);
}