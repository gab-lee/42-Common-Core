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

char *handle_c(char *str, va_list *args, int *bytes_written, t_modifier *flags)
{
	int		c;
	char	*formatted_str;

	formatted_str = NULL;
	c = va_arg(*args, int);
	formatted_str = malloc(2 * sizeof(char));
	if (!formatted_str)
		return (NULL);
	formatted_str[0] = c;
	formatted_str[1] = '\0';
	formatted_str = (*flags)(formatted_str, 'c');
	return (formatted_str);
}
