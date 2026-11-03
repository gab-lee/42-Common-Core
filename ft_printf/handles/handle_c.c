/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 23:06:06 by gabrlee           #+#    #+#             */
/*   Updated: 2026/11/01 09:47:45 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*handle_c(va_list *args)
{
	int		c;
	char	*formatted_str;

	formatted_str = NULL;
	c = va_arg(*args, int);
	formatted_str = ft_calloc(2, sizeof(char));
	if (!formatted_str)
		return (NULL);
	formatted_str[0] = (unsigned char)c;
	return (formatted_str);
}
