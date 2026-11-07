/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_width_zero_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 23:05:13 by gabrlee           #+#    #+#             */
/*   Updated: 2026/11/04 12:24:40 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	modify_width_zero(char **str, char handle, int width)
{
	char	*padding;
	char	*temp;
	int		len;
	int		sign;

	(void) handle;
	len = (int)ft_strlen(safe_call(*str));
	if (width < len)
		return (0);
	sign = ((*str)[0] == '-' || (*str)[0] == '+');
	padding = create_padding(width - len + sign, '0');
	if (!padding)
		return (-1);
	if (sign)
		padding[0] = (*str)[0];
	temp = ft_strjoin(padding, *str + sign);
	free(padding);
	if (!temp)
		return (-1);
	free(*str);
	*str = temp;
	return (0);
}
