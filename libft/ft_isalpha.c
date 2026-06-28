int ft_isalpha(char *str)
{
    int i;

    i = -1;
    while (++i, str[i])
    {
        if (!(str[i] >= 'a' && str[i] <= 'z') && !(str[i] >= 'A' && str[i] <= 'Z'))
            return 0;
    }
    return (1);
}
