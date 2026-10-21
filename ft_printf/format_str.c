/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 16:04:50 by gabrlee           #+#    #+#             */
/*   Updated: 2026/10/21 16:42:10 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	hexa_len(unsigned int x)
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

static void	fill_hexa(char *str, unsigned int x, int idx)
{
	str[idx] = HEXADECIMAL[x % 16];
	if (x >= 16)
		fill_hexa(str, x / 16, idx - 1);
}

char	*get_hexadecimal(unsigned int x)
{
	char	*formatted_str;
	int		len;

	len = hexa_len(x);
	formatted_str = malloc(len + 1);
	if (!formatted_str)
		return (NULL);
	formatted_str[len] = '\0';
	fill_hexa(formatted_str, x, len - 1);
	return (formatted_str);
}

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}