/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_conversion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 23:06:05 by gabrlee           #+#    #+#             */
/*   Updated: 2026/10/21 15:47:54 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static t_handler	call_handle(char c);

void	handle_conversion(const char *str, int *i, int *bytes_written, va_list *args)
{
	char		*flags;
	char		*formatted_str;
	t_handler	h;

	flags = NULL;
	formatted_str = NULL;
	while (str[(*i)++])
	{
		if (ft_strchr(CONVERSIONS, (str[*i])))
		{
			h = call_handle(str[*i]);
			h((char *)str, args, bytes_written);
			break ;
		}
		flags = ft_strcat_char(flags, str[*i]);
	}
	printf("=flags: %s=", flags);
}

static t_handler	call_handle(char c)
{
	if (c == 'c')
		return (handle_c);
	if (c == 's')
		return (handle_s);
	if (c == 'p')
		return (handle_p);
	if (c == 'd' || c == 'i')
		return (handle_d_or_i);
	if (c == 'u')
		return (handle_u);
	if (c == 'x')
		return (handle_x);
	if (c == 'X')
		return (handle_upper_x);
	return (NULL);
}