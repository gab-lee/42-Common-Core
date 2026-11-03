/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_width_zero_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 23:05:13 by gabrlee           #+#    #+#             */
/*   Updated: 2026/11/03 23:09:03 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static char	*zero_padding(size_t count);

int	modify_width_zero(char **str, char handle, int width)
{
	char	*zero;
	char	*temp;
	int len;
	(void)handle;

	len = (int)ft_strlen(safe_call(*str));
	if (width < len)
		return (1);
	zero = zero_padding(width - ft_strlen(safe_call(*str)));
	if ((*str)[0] == '-')
	{
		temp = ft_strjoin(safe_call("-"), safe_call(zero));
		if (!temp)
			return (-1);
		free(zero);
		zero = ft_strjoin(safe_call(""), safe_call(temp));
		free(temp);
		temp = ft_strjoin(safe_call(zero), safe_call((*str) + 1));
		if (!temp)
			return (-1);
		free(*str);
		*str = temp;
		free(temp);
	}
	temp = ft_strjoin(safe_call(zero), safe_call(*str));
	free(zero);
	if (!temp)
		return (-1);
	free(*str);
	*str = temp;
	return (1);
}

static char	*zero_padding(size_t count)
{
	char	*str;

	str = ft_calloc(count + 1, sizeof(char));
	if (!str)
		return (NULL);
	ft_memset(str, '0', count);
	return (str);
}
