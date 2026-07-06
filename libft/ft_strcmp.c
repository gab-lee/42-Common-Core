int strcmp(char *s1, char *s2)
{
    int i;
    
    i = -1;
    while(++i, s1[i] && s1[i]=s2[i])
    	;
    return (s1[i] - s2[i]);
}