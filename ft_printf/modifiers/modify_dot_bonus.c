/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_dot_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 23:05:13 by gabrlee           #+#    #+#             */
/*   Updated: 2026/10/26 15:20:51 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	str_precision(char **str, int precision);

int	modify_dot(char **str, char handle, int width, int precision)
{
	(void) width;
	if (handle == 'c' || handle == '%')
		return (1);
	if (handle == 's')
		return (str_shrink(str, precision));
	return (str_precision(str, precision));

}

static int	str_precision(char **str, int precision)
{
	char	*temp;
	int		sign;
	int		len;
	int		i;

	sign = ((*str)[0] == '-');
	len = ft_strlen_safe(*str) - sign;
	if (len >= precision)
		return (1);
	temp = malloc((sign + precision + 1) * sizeof(char));
	if (!temp)
		return (-1);
	i = 0;
	if (sign)
		temp[i++] = '-';
	while (i < sign + precision - len)
		temp[i++] = '0';
	ft_strlcpy(&temp[i], &(*str)[sign], len + 1);
	free(*str);
	*str = temp;
	return (1);
}
