/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 23:05:41 by gabrlee           #+#    #+#             */
/*   Updated: 2026/10/21 16:10:16 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*handle_x(char *str, va_list *args, int *bytes_written, t_modifier *flags)
{
	char	*formatted_str;
	unsigned int x;
	
	x = va_arg(*args, unsigned int);
	formatted_str = get_hexadecimal(x, 0);
	if (!formatted_str)
		return (NULL);
	put_str_count(formatted_str, bytes_written);
	return (formatted_str);
}