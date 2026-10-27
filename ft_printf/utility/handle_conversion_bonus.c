/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_conversion_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 23:06:05 by gabrlee           #+#    #+#             */
/*   Updated: 2026/10/27 23:14:10 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	handle_conversion(const char *str, int *i, int *bytes_written, va_list *args)
{
	char		*flags;
	char		*formatted_str;
	t_handler	h;

	flags = NULL;
	formatted_str = NULL;
	(*i)++;
	while (str[(*i)++])
	{
		if (ft_strchr(CONVERSIONS, (str[*i])))
		{
			h = call_handle(str[*i]);
			if (!h)
			{
				free(flags);
				return (-1);
			}
			formatted_str = h(args);
			if (!formatted_str || call_modifier(&formatted_str, flags,
					str[*i]) < 0 || !formatted_str)
			{
				free(flags);
				free(formatted_str);
				return (-1);
			}
			put_str_count(formatted_str, bytes_written);
			free(formatted_str);
			free(flags);
			break ;
		}
		flags = ft_strcat_char(flags, str[*i]);
	}
	return (0);
}
