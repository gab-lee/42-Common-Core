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
	int		prefix;

	len = (int)ft_strlen(safe_call(*str));
	if (width < len)
		return (0);
	prefix = ((*str)[0] == '-' || (*str)[0] == '+');
	if ((handle == 'd' || handle == 'i') && (*str)[0] == ' ')
		prefix = 1;
	if ((handle == 'x' || handle == 'X') && (*str)[0] == '0'
		&& (*str)[1] == handle)
		prefix = 2;
	padding = create_padding(width - len + prefix, '0');
	if (!padding)
		return (-1);
	ft_memcpy(padding, *str, prefix);
	temp = ft_strjoin(padding, *str + prefix);
	free(padding);
	if (!temp)
		return (-1);
	free(*str);
	*str = temp;
	return (0);
}
