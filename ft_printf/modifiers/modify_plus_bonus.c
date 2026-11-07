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

#include "ft_printf_bonus.h"

int	modify_plus(char **str, char handle, int prop)
{
	char	*temp;

	if (!prop)
		return (0);
	if ((handle != 'd' && handle != 'i') || (*str)[0] == '-')
		return (0);
	temp = ft_strjoin(safe_call("+"), safe_call(*str));
	if (!temp)
		return (-1);
	free(*str);
	*str = temp;
	return (0);
}

