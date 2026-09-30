int ft_strcmp(const char *s1, const char *s2)
{
    int i;

    i = -1;
    while (++i, s1[i] && s1[i] == s2[i])
        ;
    return (s1[i] - s2[i]);
}