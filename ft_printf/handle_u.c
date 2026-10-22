/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 23:05:45 by gabrlee           #+#    #+#             */
/*   Updated: 2026/10/21 22:37:46 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*uitoa(unsigned int n);
static int	ft_uintsize(unsigned int n);
static void	ft_fill_str(unsigned int n, char *str);

char	*handle_u(char *str, va_list *args, int *bytes_written, t_modifier *flags)
{
	unsigned int	u;
	char			*formatted_str;

	u = va_arg(*args, unsigned int);
	formatted_str = uitoa(u);
	if (!formatted_str)
		return (NULL);
	put_str_count(formatted_str, bytes_written);
	return (formatted_str);
}

static char	*uitoa(unsigned int n)
{
	char	*str;
	int		size;

	if (n == 0)
	{
		str = malloc(2 * sizeof(char));
		if (!str)
			return (NULL);
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	size = ft_uintsize(n);
	str = malloc((size + 1) * sizeof(char));
	if (!str || !n)
		return (NULL);
	ft_fill_str(n, &str[size - 1]);
	str[size] = '\0';
	return (str);
}

static int	ft_uintsize(unsigned int n)
{
	int	size;

	size = -1;
	while (++size, n)
		n = n / 10;
	return (size);
}

static void	ft_fill_str(unsigned int n, char *str)
{
	if (!n)
		return ;
	*str = (n % 10) + '0';
	ft_fill_str(n / 10, str - 1);
}