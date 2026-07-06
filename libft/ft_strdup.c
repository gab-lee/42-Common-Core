int	ft_strlen(char *str);

char *strdup(char *str)
{
    int i;
 	char *dup;
    
    if(!(dup = malloc(ft_strlen(str)*sizeof(char)))
    	return (NULL);
    while (str[i])
        dup[i] = str[i];
    return (dup);
}

int	ft_strlen(char *str)
{
    int len;
    
    len = -1;
    while (str[len])
    	len++;
    return (len);
}