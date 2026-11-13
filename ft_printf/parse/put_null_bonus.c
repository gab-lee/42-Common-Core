/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_null_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 23:06:05 by gabrlee           #+#    #+#             */
/*   Updated: 2026/11/07 18:24:16 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	put_null(char *flags, char *str, int *bytes_written)
{
	int	width;
	int	precision;
	int	i;

	width = 0;
	precision = -1;
	if (extract_flags(flags, &width, &precision) == -1)
		width = 0;
	i = 0;
	while (!has_flag(flags, '-') && ++i < width)
		put_char(' ', bytes_written);
	put_char('\0', bytes_written);
	while (has_flag(flags, '-') && ++i < width)
		put_char(' ', bytes_written);
	free(flags);
	free(str);
	return (0);
}
