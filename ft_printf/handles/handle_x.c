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

char	*handle_x(va_list *args)
{
	char			*formatted_str;
	unsigned int	x;

	formatted_str = NULL;
	x = va_arg(*args, unsigned int);
	formatted_str = get_hexadecimal(x, 0);
	if (!formatted_str)
		return (NULL);
	return (formatted_str);
}