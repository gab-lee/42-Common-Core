/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 23:06:05 by gabrlee           #+#    #+#             */
/*   Updated: 2026/10/27 22:55:40 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	has_zero(char *flags)
{
	int		i;

	i = -1;
	while (++i, flags[i])
	{
		if (flags[i] == '.' || (flags[i] >= '0' && flags[i] <= '9'))
			break ;
		if (flags[i] == '0')
			return (1);
	}
	return (0);
}

int	has_space(char *flags)
{
	int		i;

	i = -1;
	while (++i, flags[i])
	{
		if (flags[i] == '.' || (flags[i] >= '0' && flags[i] <= '9'))
			break ;
		if (flags[i] == ' ')
			return (1);
	}
	return (0);
}

int	has_minus(char *flags)
{
	int		i;

	i = -1;
	while (++i, flags[i])
	{
		if (flags[i] == '.' || (flags[i] >= '0' && flags[i] <= '9'))
			break ;
		if (flags[i] == '-')
			return (1);
	}
	return (0);
}

int	has_plus(char *flags)
{
	int		i;

	i = -1;
	while (++i, flags[i])
	{
		if (flags[i] == '.' || (flags[i] >= '0' && flags[i] <= '9'))
			break ;
		if (flags[i] == '+')
			return (1);
	}
	return (0);
}

int	has_hash(char *flags)
{
	int		i;

	i = -1;
	while (++i, flags[i])
	{
		if (flags[i] == '.' || (flags[i] >= '0' && flags[i] <= '9'))
			break ;
		if (flags[i] == '#')
			return (1);
	}
	return (0);
}
