/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 23:05:49 by gabrlee           #+#    #+#             */
/*   Updated: 2026/10/27 23:03:17 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*handle_s(va_list *args)
{
	char	*s;
	char	*formatted_str;

	formatted_str = NULL;
	s = va_arg(*args, char *);
	if (!s)
		s = "(null)";
	formatted_str = strjoin_safe("", s);
	if (!formatted_str)
		return (NULL);
	return (formatted_str);
}