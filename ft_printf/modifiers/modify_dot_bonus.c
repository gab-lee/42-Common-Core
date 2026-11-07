/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_dot_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 23:05:13 by gabrlee           #+#    #+#             */
/*   Updated: 2026/11/07 17:52:43 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	str_precision(char **str, int precision);

int	modify_dot(char **str, char handle, int precision)
{
	char	*temp;

	if (precision < 0)
		return (0);
	if (handle == 'c' || handle == '%')
		return (0);
	if (precision == 0 && (handle == 's' || ft_strncmp(*str, "0", 2) == 0))
	{
		temp = ft_strdup("");
		if (!temp)
			return (-1);
		free(*str);
		*str = temp;
		return (0);
	}
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
	len = ft_strlen(safe_call(*str)) - sign;
	if (len >= precision)
		return (0);
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
	return (0);
}
