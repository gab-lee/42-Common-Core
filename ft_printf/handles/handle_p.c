/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 23:05:54 by gabrlee           #+#    #+#             */
/*   Updated: 2026/10/31 08:45:08 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*handle_p(va_list *args)
{
	char			*formatted_str;
	char			*temp;
	unsigned long	p;

	formatted_str = NULL;
	p = va_arg(*args, unsigned long);
	if (p == 0)
	{
		formatted_str = strjoin_safe("", "(nil)");
		if (!formatted_str)
			return (NULL);
		return (formatted_str);
	}
	temp = get_hexadecimal(p,0);
	if (!temp)
		return (NULL);
	formatted_str = strjoin_safe("0x", temp);
	free(temp);
	if (!formatted_str)
		return (NULL);
	return (formatted_str);
}
