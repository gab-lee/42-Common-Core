/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_conversion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 23:06:05 by gabrlee           #+#    #+#             */
/*   Updated: 2026/10/27 23:14:05 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_conversion(const char *str, int *i, int *bytes_written, va_list *args)
{
	char		*flags;
	char		*formatted_str;
	t_handler	h;

	flags = NULL;
	(*i)++;
	while (str[*i])
	{
		if (ft_strchr(CONVERSIONS, str[*i]))
		{
			h = call_handle(str[*i]);
			formatted_str = NULL;
			if (h)
				formatted_str = h(args);
			if (!formatted_str || (flags
					&& call_modifier(&formatted_str, flags, str[*i]) < 0))
			{
				free(flags);
				free(formatted_str);
				return (-1);
			}
			put_str_count(formatted_str, bytes_written);
			free(formatted_str);
			free(flags);
			return (0);
		}
		flags = ft_strcat_char(flags, str[*i]);
		(*i)++;
	}
	free(flags);
	return (-1);
}
