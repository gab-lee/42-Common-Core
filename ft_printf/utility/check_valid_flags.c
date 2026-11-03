/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_flags.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 19:26:02 by gabrlee           #+#    #+#             */
/*   Updated: 2026/11/03 10:51:34 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	check_order(char c, int *order);

int	check_valid_flags(char *flags)
{
	int	i;
	int	order;

	i = -1;
	if (!flags)
		return (-1);
	while (++i, flags[i])
	{
		if (!(ft_strchr(FLAGS, flags[i]) || (ft_isdigit(flags[i]))))
			return (-1);
		if (check_order(flags[i], &order) == -1)
			return (-1);
	}
	return (0);
}

static int	check_order(char c, int *order)
{
	if (c == '.')
	{
		*order = 2;
		return (0);
	}
	else if (order == 0 && (c >= '1' && c <= '9'))
	{
		order = 1;
		return (1);
	}
	if (order > 0 && !ft_isdigit(c))
		return (-1);
	return (0);
}
