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

static int	hexa_len(unsigned long x);
static void	fill_hexa(char *str, unsigned long x, int idx, int upper);

char	*get_hexadecimal(unsigned long x, int upper)
{
	char	*formatted_str;
	int		len;

	len = hexa_len(x);
	formatted_str = malloc(len + 1);
	if (!formatted_str)
		return (NULL);
	formatted_str[len] = '\0';
	fill_hexa(formatted_str, x, len - 1, upper);
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

static void	fill_hexa(char *str, unsigned long x, int idx, int upper)
{
	str[idx] = HEXADECIMAL[x % 16];
	if (upper)
		str[idx] = ft_toupper(str[idx]);
	if (x >= 16)
		fill_hexa(str, x / 16, idx - 1, upper);
}
