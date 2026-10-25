/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 23:05:54 by gabrlee           #+#    #+#             */
/*   Updated: 2026/10/21 22:42:19 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*handle_p(va_list *args, t_modifier m)
{
	char			*formatted_str;
	unsigned long	p;

	formatted_str = NULL;
	p = va_arg(*args, unsigned long);
	formatted_str = get_hexadecimal(p,0);
	if (!formatted_str)
		return (NULL);
	m(&formatted_str);
	if (!formatted_str)
		return (NULL);
	return (formatted_str);
}
