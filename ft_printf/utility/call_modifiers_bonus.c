/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_modifiers_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 23:27:41 by gabrlee           #+#    #+#             */
/*   Updated: 2026/11/03 10:52:16 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	get_width(char *flags);
static int	get_precision(char *flags);
static int	apply_width(char **str, char *flags, char handle, int width);

int	call_modifier(char **str, char *flags, char handle)
{
	if (check_valid_flags(flags) == -1)
		return (-1);
	if (modify_dot(str, handle, get_precision(flags)) == -1)
		return (-1);
	if (apply_sign(str, handle, has_plus(flags), has_space(flags)) == -1)
		return (-1);
	if (modify_hashtag(str, handle, has_hash(flags)) == -1)
		return (-1);
	if (apply_width(str, flags, handle, get_width(flags)) == -1)
		return (-1);
	return (1);
}

static int	apply_sign(char *str, char *handle, int has_plus, int has_space)
{
	if (has_plus)
		return (modify_plus(str, handle));
	else if (has_space)
		return (modify_space(str, handle));
	return (0);
}

static int	apply_width(char **str, char *flags, char handle, int width)
{
	if (has_minus(flags))
		return (modify_width_minus(str, handle, width));
	if (has_zero(flags))
		return (modify_width_zero(str, handle, width));
	return (modify_width(str, handle, width));
}

static int	get_width(char *flags)
{
	int		i;
	char	*width;
	int		start;

	i = -1;
	width = NULL;
	start = 0;
	while (++i, flags[i])
	{
		if (flags[i] == '.')
			break ;
		if (!start && flags[i] > '0' && flags[i] <= '9')
		{
			start = 1;
			width = ft_strcat_char(width, flags[i]);
		}
		if (start && flags[i] >= '0' && flags[i] <= '9')
			width = ft_strcat_char(width, flags[i]);
	}
	if (width)
		return (ft_atoi(width));
	return (0);
}

static int get_precision(char *flags)
{
	int		i;
	int		start;
	char	*precision;

	i = -1;
	start = 0;
	precision = NULL;
	while (++i, flags[i])
	{
		if (flags[i] == '.')
			start = 1 ;
		if (start && flags[i] >= '0' && flags[i] <= '9')
			ft_strcat_char(precision, flags[i]);
	}
	if (precision)
		return (ft_atoi(precision));
	else
		return (0);
}
