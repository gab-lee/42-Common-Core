/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 17:24:17 by gabrlee           #+#    #+#             */
/*   Updated: 2026/09/30 20:29:51 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intsize(int n, int *sign);
static void	ft_fill_str(int n, char *str, int sign);

char	*ft_itoa(int n)
{
	char	*str;
	int		sign;
	int		size;

	sign = 1;
	if (n == 0)
	{
		str = malloc(2 * sizeof(char));
		if (!str)
			return (NULL);
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	size = ft_intsize(n, &sign);
	str = malloc((size + 1) * sizeof(char));
	if (!str || !n)
		return (NULL);
	ft_fill_str(n, &str[size - 1], sign);
	str[size] = '\0';
	return (str);
}

static int	ft_intsize(int n, int *sign)
{
	int	size;

	size = -1;
	if (n < 0)
	{
		size++;
		*sign = -1;
	}
	while (++size, n)
		n = n / 10;
	return (size);
}

static void	ft_fill_str(int n, char *str, int sign)
{
	if (!n)
	{
		if (sign == -1)
			*str = '-';
		return ;
	}
	*str = (n % 10) * sign + '0';
	ft_fill_str(n / 10, str - 1, sign);
}
