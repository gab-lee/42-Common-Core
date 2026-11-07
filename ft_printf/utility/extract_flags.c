/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 23:06:05 by gabrlee           #+#    #+#             */
/*   Updated: 2026/11/07 17:33:08 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	get_width(char *flags);
static int	is_valid_width(char *width);
static int	get_precision(char *flags);

int	extract_flags(char *flags, int *width, int *precision)
{
	*width = get_width(flags);
	*precision = get_precision(flags);
	if (*width < 0)
		return (-1);
	return (0);
}

static int	get_width(char *flags)
{
	int		i;
	char	*width;
	int		start;
	int		res;

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
		else if (start && flags[i] >= '0' && flags[i] <= '9')
			width = ft_strcat_char(width, flags[i]);
	}
	if (!width)
		return (0);
	if (is_valid_width(width) == -1)
	{
		free(width);
		return (-1);
	}
	res = ft_atoi(width);
	free(width);
	return (res);
}

static int	get_precision(char *flags)
{
	int		i;
	int		start;
	int		p;
	char	*precision;

	i = -1;
	start = 0;
	precision = NULL;
	while (++i, flags[i])
	{
		if (flags[i] == '.')
			start = 1 ;
		if (start && flags[i] >= '0' && flags[i] <= '9')
			precision = ft_strcat_char(precision, flags[i]);
	}
	if (precision)
	{
		p = ft_atoi(precision);
		free (precision);
		return (p);
	}
	else
		return (-1);
}

static int	is_valid_width(char *width)
{
	char	*padded;
	int		res;

	if (ft_strlen(safe_call(width)) > 10 || ft_strlen(safe_call(width)) == 0)
		return (-1);
	padded = ft_strdup(width);
	if (!padded || modify_width_zero(&padded, 'd', 10) == -1)
	{
		free(padded);
		return (-1);
	}
	res = -1;
	if (ft_strncmp("2147483647", padded, 10) > 0)
		res = 0;
	free(padded);
	return (res);
}
