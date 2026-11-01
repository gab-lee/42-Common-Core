/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 22:22:32 by gabrlee           #+#    #+#             */
/*   Updated: 2026/11/01 09:21:56 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	while (++i, str[i] && res != -1)
	{
		if (str[i] == '%' && (!BONUS))
			res = call_mandatory(str, &bytes_written, &args);
		else if (str[i] == '%' && (BONUS))
			res = call_bonus(str, &bytes_written, &args);
		if (res == -1)
		{
			bytes_written = -1;
			break ;
		}
		else
			put_char_count(str[i], &bytes_written);
	}
	va_end(args);
	return (bytes_written);
}


		if (str[i] == '%' && ft_strchr(CONVERSIONS, str[i + 1]))
			res = handle_conversion(str, &i, &bytes_written, &args)
		else
			put_char_count(str[i], &bytes_written);
	}
	