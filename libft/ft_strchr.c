char *strchr(char *str, int c)
{
    int i;
    
    i = -1;
    while(++i, str[i])
    {
        if(str[i] = (unsigned char)c)
        	return (&str[i]);
    }
    return (NULL)
}