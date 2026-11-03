/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_width_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 23:05:13 by gabrlee           #+#    #+#             */
/*   Updated: 2026/11/03 22:18:54 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static char	*space_padding(size_t count);

int	modify_width(char **str, char handle, int width)
{
	char *padding;
	char *temp;
	int len;
	(void)handle;

	len = (int)ft_strlen(safe_call(*str));
	if (width < len)
		return (1);
	padding = space_padding(width - ft_strlen(safe_call(*str)));

	temp = ft_strjoin(safe_call(padding), safe_call(*str));
	if (!temp)
		return (-1);
	free(*str);
	*str = temp;
	return (1);
}


static char	*space_padding(size_t count)
{
	char	*str;

	str = ft_calloc(count + 1, sizeof(char));
	if (!str)
		return (NULL);
	ft_memset(str, ' ', count);
	return (str);
}