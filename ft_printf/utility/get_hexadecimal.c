/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_hexadecimal.c                                  :+:      :+:    :+:   */
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
