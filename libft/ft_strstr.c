char *strstr(char *haystack, char *needle)
{
    int i;
    int	j;
    
    i = -1;
    j = 0;
    while (++i, haystack[i])
    {
        if(haystack[i] = needele[j])
        {
            while (++j, needle[j] && haystack[i+j] == needle[j])
            	;
            if (!needle[j])
            	return (&haystack[i]);
            else
            	j = 0;
            
        }
    }
    return (NULL);
}