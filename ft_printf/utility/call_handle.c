/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_handle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 23:06:05 by gabrlee           #+#    #+#             */
/*   Updated: 2026/10/27 22:55:40 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_handler	call_handle(char c)
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
	if (c == '%')
		return (handle_percent);
	return (NULL);
}
