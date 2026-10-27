/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_conversion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 23:06:05 by gabrlee           #+#    #+#             */
/*   Updated: 2026/10/27 22:55:40 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	handle_conversion(const char *str, int *i, int *bytes_written, va_list *args)
{
	char		*formatted_str;
	t_handler	h;

	formatted_str = NULL;
	while (str[(*i)++])
	{
		if (ft_strchr(CONVERSIONS, (str[*i])))
		{
			h = call_handle(str[*i]);
			if (!h)
				return (-1);
			formatted_str = h(args);
			if (!formatted_str)
				return (-1);
			put_str_count(formatted_str, bytes_written);
			free(formatted_str);
			break ;
		}
		return (-1);
	}
	return (0);
}
