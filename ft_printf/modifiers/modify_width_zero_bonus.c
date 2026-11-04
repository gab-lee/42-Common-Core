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
	char	*zero;
	char	*temp;
	int		len;

	(void) handle;
	len = (int)ft_strlen(safe_call(*str));
	if (width < len)
		return (0);
	if ((*str)[0] == '-' || (*str)[0] == '+')
	{
		if ((*str)[0] == '-' )
			zero = ft_strjoin("-", (create_padding(width - ft_strlen(safe_call(*str)), '0')));
		else 
			zero = ft_strjoin("+", (create_padding(width - ft_strlen(safe_call(*str)), '0')));
		temp = ft_strdup((*str) + 1);
		if (!temp)
		{
			free(zero);
			return (-1);
		}
		*str = temp;
	}
	else
		zero = create_padding(width - ft_strlen(safe_call(*str)), '0');
	temp = ft_strjoin(safe_call(zero), safe_call(*str));
	if (!temp)
		return (-1);
	free(zero);
	*str = temp;
	return (0);
}
