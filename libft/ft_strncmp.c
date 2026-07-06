int strncmp(char *s1, char *s2, int n)
{
    int i;
    
    i = -1;
    while(++i, i < n && s1[i] && s1[i]=s2[i])
    	;
    return (s1[i] - s2[i]);
}