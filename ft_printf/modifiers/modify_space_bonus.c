/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_space_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 23:05:13 by gabrlee           #+#    #+#             */
/*   Updated: 2026/10/21 23:05:48 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	modify_space(char **str, char handle, int width, int precision)
{
	char	*temp;

	if ((handle != 'd' && handle != 'i') || (*str)[0] == '-')
		return (1);
	temp = ft_strjoin(" ", *str);
	if (!temp)
		return (-1);
	free(*str);
	*str = temp;
	return (1);
}
