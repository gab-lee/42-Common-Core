/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_width_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 23:05:13 by gabrlee           #+#    #+#             */
/*   Updated: 2026/10/26 13:22:10 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*space_padding(size_t count);

int	modify_width(char **str, char handle, int width, int precision)
{
	char *padding;
	char *temp;

	if (width < ft_strlen_safe(*str))
		return (1);
	padding = space_padding(width- ft_strlen_safe(*str));

	temp = strjoin_safe(padding, *str);
	if (!temp)
		return (-1);
	free(*str);
	*str = temp;
	return (1);
}


static char	*space_padding(size_t count)
{
	char	*str;
	int i;

	i = -1;
	str = malloc((count+1) * sizeof(char));
	if (!str)
		return (NULL);
	str[count] = '\0';
	while (++i, str[i])
		str[i] = ' ';
	return (str);
}