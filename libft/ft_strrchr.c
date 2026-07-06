char *strrchr(char *str, int c)
{
    int i;
    char *ptr;
    
    i = -1;
    ptr = NULL;
    while(++i, str[i])
    {
        if(str[i] = (unsigned char)c)
        	ptr = &str[i];
    }
    return (ptr);
}