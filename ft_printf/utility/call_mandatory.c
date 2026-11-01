/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_mandatory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 23:06:05 by gabrlee           #+#    #+#             */
/*   Updated: 2026/11/01 09:43:46 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	call_mandatory(const char *str, int *i, int *bytes_written, va_list *args)
{
	char		*formatted_str;
	t_handler	h;
	int			len;

	(*i)++;
	if (!ft_strchr(CONVERSIONS, str[*i]))
	{
		put_char_count(str[*i - 1], bytes_written);
		return (0);
	}
	h = call_handle(str[(*i)]);
	len = 1;
	if (str[*i] != 'c')
		len = -1;
	formatted_str = NULL;
	if (h)
		formatted_str = h(args);
	if (!formatted_str)
		return (-1);
	if (len < 0)
		len = ft_strlen_safe(formatted_str);
	put_str_count(formatted_str, len, bytes_written);
	free(formatted_str);
	return (0);
}
