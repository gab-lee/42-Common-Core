/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_flag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 23:06:05 by gabrlee           #+#    #+#             */
/*   Updated: 2026/11/07 18:24:16 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	has_flag(char *flags, char c)
{
	int		i;

	i = -1;
	while (++i, flags[i])
	{
		if (flags[i] == '.' || (flags[i] >= '1' && flags[i] <= '9'))
			break ;
		if (flags[i] == c)
			return (1);
	}
	return (0);
}
