int ft_strlen(char *str)
{
	int len;

	len = -1;
	while (len++, str[len])
		;
	return (len);
}
