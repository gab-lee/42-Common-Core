/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_flags.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 19:26:02 by gabrlee           #+#    #+#             */
/*   Updated: 2026/11/01 19:28:32 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int check_valid_flags(flags)
{
	int	i;

	i = -1;
	if (++i, flags[i])
	{
		if (!(ft_strchr(FLAGS, flags[i]) || (ft_isnum(flags[i]))))
			return (-1);
	}
	return (0);
}