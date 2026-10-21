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

void	handle_u(char *str, va_list *args, int *bytes_written, void (*flags)(char *))
{
	unsigned int	u;
	char			*s;
	char			*formatted_str;

	u = va_arg(*args, unsigned int);
	s = uitoa(u);
	put_str_count(s, bytes_written);
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