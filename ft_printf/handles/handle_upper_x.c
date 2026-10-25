/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_upper_x.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 23:05:43 by gabrlee           #+#    #+#             */
/*   Updated: 2026/10/21 16:55:19 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*handle_upper_x(va_list *args, t_modifier m)
{
	unsigned int	x;
	char			*formatted_str;

	formatted_str = NULL;
	x = va_arg(*args, unsigned int);
	formatted_str = get_hexadecimal(x, 1);
	if (!formatted_str)
		return (NULL);
	m(&formatted_str);
	if (!formatted_str)
		return (NULL);
	return (formatted_str);
}
