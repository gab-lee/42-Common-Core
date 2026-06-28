int ft_isalpha(char *str)
{
    int i;

    i = -1;
    while (++i, str[i])
    {
        if (!(str[i] >= '1' && str[i] <= '9'))
            return (0);
    }
    return (1);
}
