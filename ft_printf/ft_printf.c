/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 22:22:32 by gabrlee           #+#    #+#             */
/*   Updated: 2026/10/20 23:09:43 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int i;
	int	bytes_written;
	//va_list args;

	i = -1;
	bytes_written = 0;
	//va_start(args, str);
	while (++i, str[i])
	{
		//if (str[i] == '%')
		//	handle_conversion(str, &i, &bytes_written, &args);
		//else
			//handle_write(str, &bytes_written);
		write(1,&str[i],1);
	}
	//va_end(args);
	return (bytes_written);
}
