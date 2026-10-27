/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_modifiers_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 23:27:41 by gabrlee           #+#    #+#             */
/*   Updated: 2026/10/27 17:31:51 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_width(char *flags);
static int	get_precision(char *flags);
static int	has_zero(char *flags);
static int	has_space(char *flags);
static int	has_minus(char *flags);
static int	apply_width(char **str, char *flags, char handle, int width);

int	call_modifier(char **str, char *flags, char handle)
{
	int width;
	int precision;

	width = 0;
	precision = 0;

	if (ft_strchr(flags, '+'))
	{
		if (modify_plus(str, handle, width, precision) < 0)
			return (-1);
	}
	else if (has_space(flags))
	{
		if (modify_space(str, handle, width, precision) < 0)
			return (-1);
	}
	width = get_width(flags);
	if (width && apply_width(str, flags, handle, width) < 0)
		return (-1);
	precision = get_precision(flags);
	if (precision)
	{
		if (modify_dot(str, handle, width, precision) < 0)
			return (-1);
	}
	if (ft_strchr(flags, '#'))
	{
		if (modify_hashtag(str, handle, width, precision) < 0)
			return (-1);
	}
	return (1);
}

static int	apply_width(char **str, char *flags, char handle, int width)
{
	if (has_minus(flags))
		return (modify_width_minus(str, handle, width, 0));
	if (has_zero(flags))
		return (modify_width_zero(str, handle, width, 0));
	return (modify_width(str, handle, width, 0));
}

static int get_width(char *flags)
{
	int		i;
	char	*width;
	int		start;

	i = -1;
	width = "";
	start = 0;
	while (++i, flags[i])
	{
		if (flags[i] == '.')
			break ;
		if (!start && flags[i] > '0' && flags[i] <=9)
		{
			start = 1;
			ft_strcat_char(width, flags[i]);
		}
		if (start && flags[i] >= '0' && flags[i] <=9)
			ft_strcat_char(width, flags[i]);
	}
	return (atoi(width));
}

static int has_zero(char *flags)
{
	int		i;

	i = -1;
	while (++i, flags[i])
	{
		if (flags[i] == '.' || (flags[i] > '0' && flags[i] <= '9'))
			break ;
		if (flags[i] == '0')
			return (1);
	}
	return (0);
}

static int has_space(char *flags)
{
	int		i;

	i = -1;
	while (++i, flags[i])
	{
		if (flags[i] == '.' || (flags[i] > '0' && flags[i] <= '9'))
			break ;
		if (flags[i] == ' ')
			return (1);
	}
	return (0);
}

static int has_minus(char *flags)
{
	int		i;

	i = -1;
	while (++i, flags[i])
	{
		if (flags[i] == '.' || (flags[i] > '0' && flags[i] <= '9'))
			break ;
		if (flags[i] == '-')
			return (1);
	}
	return (0);
}
static int get_precision(char *flags)
{
	int		i;
	int		start;
	char	*precision;

	i = -1;
	start = 0;
	precision = "";
	while (++i, flags[i])
	{
		if (flags[i] == '.')
			start = 1 ;
		if (start && flags[i] >= '0' && flags[i] <=9)
			ft_strcat_char(precision, flags[i]);
	}
	return (atoi(precision));
}
