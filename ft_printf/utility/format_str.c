/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 16:04:50 by gabrlee           #+#    #+#             */
/*   Updated: 2026/10/26 13:22:11 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	to_upper(int c);
static int	hexa_len(unsigned long x);
static void	fill_hexa(char *str, unsigned long x, int idx, int (*f)(int));

char	*get_hexadecimal(unsigned long x, int upper)
{
	char	*formatted_str;
	int		len;

	len = hexa_len(x);
	formatted_str = malloc(len + 1);
	if (!formatted_str)
		return (NULL);
	formatted_str[len] = '\0';
	if (upper)
		fill_hexa(formatted_str, x, len - 1, to_upper);
	else
		fill_hexa(formatted_str, x, len - 1, NULL);
	return (formatted_str);
}

static int	hexa_len(unsigned long x)
{
	int	len;

	len = 1;
	while (x >= 16)
	{
		x /= 16;
		len++;
	}
	return (len);
}

static void	fill_hexa(char *str, unsigned long x, int idx, int (*f)(int))
{
	if (f)
		str[idx] = f(HEXADECIMAL[x % 16]);
	else
		str[idx] = HEXADECIMAL[x % 16];
	if (x >= 16)
		fill_hexa(str, x / 16, idx - 1, f);
}

static int	to_upper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

char	*strjoin_safe(char const *s1, char const *s2)
{
	char	*str;
	int		i;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	str = malloc((ft_strlen_safe(s1) + ft_strlen_safe(s2) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (*s1)
		str[i++] = *(s1++);
	while (*s2)
		str[i++] = *(s2++);
	str[i] = '\0';
	return (str);
}

size_t	str_shrink(char **str, size_t n)
{
	size_t	i;
	char *temp;

	i = -1;
	if (n == 0)
	{
		free(*str);
		*str = NULL;
		return (1);
	}
	if (ft_strlen_safe(*str) >= n)
		return (1);
	if (ft_strlen_safe(*str) < n)
	{
		temp = malloc (n * sizeof (char));
		if (!temp)
			return (-1);
		strlcpy(temp, str, n);
		free(*str);
		*str = temp;
		free(temp); 
	}
	return (1);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = -1;
	if (!n)
		return (ft_strlen(src));
	while (++i, src[i] && i < (n - 1))
		dest[i] = src[i];
	dest[i] = '\0';
	return (ft_strlen(src));
}