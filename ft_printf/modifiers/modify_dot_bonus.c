/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_dot_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 23:05:13 by gabrlee           #+#    #+#             */
/*   Updated: 2026/10/21 23:05:48 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	modify_dot(char **str, char handle, int width, int precision)
{

	if (handle == 'c' || handle == '%')
		return (1);
	if (handle == 's')
		return (str_shrink(str, precision));
	return (str_precision(str, precision));

}

static int str_precision(char **str, int precision)
{
	iterate from the back
	i = ft_strlen_safe(*str);
	j = 0 
	if (--i, i >=0 && j < dot && (*str[i] != '0' || ' '))
	{
		*str[i] = '0';
		j++
	}
}