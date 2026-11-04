/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 22:22:32 by gabrlee           #+#    #+#             */
/*   Updated: 2026/11/04 10:51:53 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_printf(const char *str, ...)
{
	int		bytes_written;
	int		res;
	int		i;
	va_list	args;

	i = -1;
	res = 0;
	bytes_written = 0;
	va_start(args, str);
	while (++i, str[i] || res == -1)
	{
		if (str[i] == '%')
			res = call_bonus(str, &i, &bytes_written, &args);
		else
			put_char(str[i], &bytes_written);
		if (res == -1)
		{
			bytes_written = -1;
			break ;
		}
	}
	va_end(args);
	return (bytes_written);
}
