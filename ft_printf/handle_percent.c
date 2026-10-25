/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_percent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 23:05:52 by gabrlee           #+#    #+#             */
/*   Updated: 2026/10/21 15:36:47 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*handle_percent(char *str, va_list *args, int *bytes_written, t_modifier *flags)
{
	char	*formatted_str;

	(void) args;
	formatted_str = NULL;
	formatted_str = malloc(2 * sizeof(char));
	if (!formatted_str)
		return (NULL);
	formatted_str[0] = '%';
	formatted_str[1] = '\0';
	return (formatted_str);
}