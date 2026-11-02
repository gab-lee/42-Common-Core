/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_d_or_i.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 23:06:03 by gabrlee           #+#    #+#             */
/*   Updated: 2026/10/21 22:34:35 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*handle_d_or_i(va_list *args)
{
	int		d;
	char	*formatted_str;

	formatted_str = NULL;
	d = va_arg(*args, int);
	formatted_str = ft_itoa(d);
	if (!formatted_str)
		return (NULL);
	return (formatted_str);
}
