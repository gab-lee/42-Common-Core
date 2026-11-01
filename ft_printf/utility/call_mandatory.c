/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_mandatory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 23:06:05 by gabrlee           #+#    #+#             */
/*   Updated: 2026/11/01 09:31:10 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	call_mandatory(const char *str, int *i, int *bytes_written, va_list *args)
{
	char		*formatted_str;
	t_handler	h;

	if (!ft_strchr(CONVERSIONS, str[*i + 1]))
	{
		put_char_count(str[*i], i);
		return (0);
	}
	h = call_handle(str[*i + 1]);
	formatted_str = NULL;
	if (h)
		formatted_str = h(args);
	if (!formatted_str)
		return (-1);
	put_str_count(formatted_str, bytes_written);
	free(formatted_str);
	return (0);
}
