/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_plus_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 23:05:13 by gabrlee           #+#    #+#             */
/*   Updated: 2026/10/26 18:20:46 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	modify_plus(char **str, char handle, int width, int precision)
{
	char	*temp;
	(void)precision;
	(void)width;

	if ((handle != 'd' && handle != 'i') || (*str)[0] == '-')
		return (1);
	temp = strjoin_safe("+", *str);
	if (!temp)
		return (-1);
	free(*str);
	*str = temp;
	return (1);
}

