/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 23:06:06 by gabrlee           #+#    #+#             */
/*   Updated: 2026/10/21 22:59:11 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*handle_c(va_list *args, t_modifier m)
{
	int		c;
	char	*formatted_str;

	formatted_str = NULL;
	c = va_arg(*args, int);
	if (c == 0)
		formatted_str = malloc(1 * sizeof(char));
	else
		formatted_str = malloc(2 * sizeof(char));
	if (!formatted_str)
		return (NULL);
	if (c == 0)
		formatted_str[0] = (unsigned char)c;
	else
	{
		formatted_str[0] = (unsigned char)c;
		formatted_str[1] = '\0';
	}
	m(&formatted_str);
	if (!formatted_str)
		return (NULL);
	return (formatted_str);
}
