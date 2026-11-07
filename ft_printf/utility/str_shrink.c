/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_shrink.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 16:04:50 by gabrlee           #+#    #+#             */
/*   Updated: 2026/11/03 23:40:42 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	str_shrink(char **str, size_t n)
{
	char *temp;

	if (n == 0)
	{
		free(*str);
		*str = NULL;
		return (0);
	}
	if (ft_strlen(safe_call(*str)) <= n)
		return (0);
	temp = malloc ((n + 1) * sizeof (char));
	if (!temp)
		return (-1);
	ft_strlcpy(temp, *str, n + 1);
	free(*str);
	*str = temp;
	return (0);
}
