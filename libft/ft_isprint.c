int ft_isprint(char *str)
{
    int i;

    i = -1;
    while (++i, str[i])
    {
        if (!(str[i] >= 32 && str[i] <= 126))
            return (0);
    }
    return (1);
}
