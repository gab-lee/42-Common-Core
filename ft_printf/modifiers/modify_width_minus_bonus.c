/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_width_minus_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 23:05:13 by gabrlee           #+#    #+#             */
/*   Updated: 2026/11/03 23:08:28 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	modify_width_minus(char **str, char handle, int width)
{
	char	*padding;
	char	*temp;
	int		len;

	(void) handle;
	len = (int)ft_strlen(safe_call(*str));
	if (width < len)
		return (0);
	padding = create_padding(width - len, ' ');
	if (!padding)
		return (-1);
	temp = ft_strjoin(safe_call(*str), padding);
	free(padding);
	if (!temp)
		return (-1);
	free(*str);
	*str = temp;
	return (0);
}
