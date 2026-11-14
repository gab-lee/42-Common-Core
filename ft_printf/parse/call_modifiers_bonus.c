/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_modifiers_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 23:27:41 by gabrlee           #+#    #+#             */
/*   Updated: 2026/11/04 11:05:11 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	apply_width(char **str, char *flags, char handle, int width);
static int	apply_sign(char **str, char handle, int plus, int space);

int	call_modifier(char **str, char *flags, char handle)
{
	int	width;
	int	precision;

	width = -1;
	precision = -1;
	if (extract_flags(flags, &width, &precision) == -1)
		return (-1);
	if (modify_dot(str, handle, precision) == -1)
		return (-1);
	if (apply_sign(str, handle, has_flag(flags, '+'), has_flag(flags, ' '))
		== -1)
		return (-1);
	if (modify_hashtag(str, handle, has_flag(flags, '#')) == -1)
		return (-1);
	if (apply_width(str, flags, handle, width) == -1)
		return (-1);
	free(flags);
	return (0);
}

static int	apply_sign(char **str, char handle, int plus, int space)
{
	if (plus)
		return (modify_plus(str, handle));
	else if (space)
		return (modify_space(str, handle));
	return (0);
}

static int	apply_width(char **str, char *flags, char handle, int width)
{
	if (width < 0)
		return (-1);
	if (has_flag(flags, '-'))
		return (modify_width_minus(str, handle, width));
	if (has_flag(flags, '0') && !ft_strchr(flags, '.'))
		return (modify_width_zero(str, handle, width));
	return (modify_width(str, handle, width));
}
