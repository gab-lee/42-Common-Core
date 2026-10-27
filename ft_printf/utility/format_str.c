/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 16:04:50 by gabrlee           #+#    #+#             */
/*   Updated: 2026/10/26 13:22:11 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	str_shrink(char **str, size_t n)
{
	size_t	i;
	char *temp;

	i = -1;
	if (n == 0)
	{
		free(*str);
		*str = NULL;
		return (1);
	}
	if (ft_strlen_safe(*str) >= n)
		return (1);
	if (ft_strlen_safe(*str) < n)
	{
		temp = malloc (n * sizeof (char));
		if (!temp)
			return (-1);
		ft_strlcpy(temp, str, n);
		free(*str);
		*str = temp;
		free(temp); 
	}
	return (1);
}
