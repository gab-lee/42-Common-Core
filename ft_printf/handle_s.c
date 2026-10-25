/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 23:05:49 by gabrlee           #+#    #+#             */
/*   Updated: 2026/10/21 15:52:18 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*handle_s(char *str, va_list *args, int *bytes_written, t_modifier *flags)
{
	char	*s;
	char	*formatted_str;

	formatted_str = NULL;
	s = va_arg(*args, char *);
	formatted_str = ft_strjoin("", s);
	if (!formatted_str)
		return (NULL);
	return (formatted_str);
}