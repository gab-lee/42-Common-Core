/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_width_zero_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 23:05:13 by gabrlee           #+#    #+#             */
/*   Updated: 2026/10/26 13:28:39 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*zero_padding(size_t count);

int	modify_width_zero(char **str, char handle, int width, int precision)
{
	char	*zero;
	char	*temp;

	if (width < ft_strlen_safe(*str))
		return (1);
	zero = zero_padding(width - ft_strlen_safe(*str));
	if ((*str)[0] == '-')
	{
		temp = strjoin_safe("-", zero);
		if (!temp)
			return (-1);
		free(zero);
		zero = strjoin_safe("", temp);
		free(temp);
		temp = strjoin_safe("", (*str) + 1);
		if (!temp)
			return (-1);
		free(*str);
		str = temp;
		free(temp);
	}
	temp = strjoin_safe(zero, *str);
	if (!temp)
		return (-1);
	free(*str);
	*str = temp;
	return (1);
}

static char	*zero_padding(size_t count)
{
	char	*str;
	int i;

	i = -1;
	str = malloc((count + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[count] = '\0';
	while (++i, str[i])
		str[i] = '0';
	return (str);
}
