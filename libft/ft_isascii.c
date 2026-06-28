int ft_isascii(char *str)
{
    int i;

    i = -1;
    while (++i, str[i])
    {
        if (!(str[i] >= 0 && str[i] <= 127))
            return (0);
    }
    return (1);
}
